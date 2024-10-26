/*
Name:AbdelrahmanMohamed Salah
ID:120210020
*/
#include "../kernel/types.h"  
#include "../kernel/stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
    int p[2];              
    char recv_buf[5]; 
    pipe(p);
    if (fork() == 0) {   
        close(p[1]);  
        read(p[0], recv_buf, 4);
        recv_buf[4] = '\0'; 
        close(p[0]);    
        printf("%d: received %s\n", getpid(), recv_buf);
        exit(0);   
    } else {
        close(p[0]); 
        write(p[1], "ping", 4);
        close(p[1]);
        int status;
	wait(&status);
        exit(0); 
    }
}
