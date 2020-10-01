#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void fork_example()
{
    pid_t pid;      //process id
    pid = fork();   //creating a new child process
    if (pid < 0)
    {
        printf("Fork failed");
        return -1;
    }
    else if (pid == 0)
    {
        printf("Child process is running...\n");
        printf("Child process id is %d\n", getpid());
        printf("My parent process id is %d\n", getppid());
        exit(0);
    }

    else
    {
        printf("Parent process is running...\n");
        printf("Parent process id is %d\n", getpid());
        printf("Parent is waiting for any child to terminate...\n");
        wait(NULL);
        printf("My child terminated!\n");
    }
    return;
}

int main()
{
    printf("Hello, World of Processes!\n");
    fork_example();
    printf("Program is about to finish!\n");
    return 0;
}
