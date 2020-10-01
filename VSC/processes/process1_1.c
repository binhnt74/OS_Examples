#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("Hello, World of Processes!\n");
    pid_t pid;      //process id
    pid = fork();   //creating a new child process
    if (pid < 0)
    {
        printf("Fork failed");
        return -1;
    }
    else if (pid == 0){
        printf("Child process is running...\n");
    }
    else
    {
        printf("Parent process is running...\n");
        wait(NULL);
    }
    printf("The end!\n");
    return 0;
}
