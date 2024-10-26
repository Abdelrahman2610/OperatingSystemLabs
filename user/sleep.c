/*
Name: Abdelrahman Mohamed Salah
ID:120210020
 */
#include "../kernel/types.h"
#include "user.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: sleep <seconds>\n");  
        exit(1);  
    }

    int sleep_time = atoi(argv[1]);
    if (sleep_time <= 0) {
        printf("Error: Invalid time interval: %s\n", argv[1]);  
        exit(1); 
    }

    printf("Sleeping for %d seconds...\n", sleep_time); 
    sleep(sleep_time);
    printf("Woke up after %d seconds!\n", sleep_time);  

    exit(0);
}
