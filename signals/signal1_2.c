#include <stdio.h> 
#include <signal.h>
#include <stdlib.h> 
#include <unistd.h>

void child_handler(int sig){
    //write(STDOUT_FILENO, "Hit child handler \n",20);
    printf("Hit child handler \n");
    static int hits = 3;
    if (hits>0){
        hits--;
    }
    else exit(1);
}

void parent_handler(int sig){
    //write(STDOUT_FILENO, "Hit parent handler \n",21);
    printf("Hit parent handler \n");
    static int hits = 3;
    if (hits>0){
        hits--;
    }
    else exit(1);
}

void main(){
    if (fork()==0){
        struct sigaction sa;
        sigemptyset(&sa.sa_mask);
        sa.sa_flags = 0;
        sa.sa_handler = child_handler;
        if (sigaction(SIGINT, &sa, NULL)==-1){
            printf("Error\n");
            exit(1);
        }
        while (1){
            /* code */
        }
        

    } else {
        struct sigaction sa;
        sigemptyset(&sa.sa_mask);
        sa.sa_flags = 0;
        sa.sa_handler = parent_handler;
        if (sigaction(SIGINT, &sa, NULL)==-1){
            printf("Error\n");
            exit(1);
        }
        while (1){
            /* code */
        }
    }
    return;
}