#include<stdio.h>
#include<unistd.h>

void main(){
    printf("Hello processes\n");
    int p;
    p = fork();
    if (p==0){
        printf("Child process running..\n");
    }
    else if (p>0){
        printf("Parent process running..\n");
    }
    else {
        printf("fork failed\n");
        return;
    }
    printf("Both processes running..\n");
}