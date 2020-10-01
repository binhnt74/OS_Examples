#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

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
        printf("Child process id is %d\n", getpid());
        printf("My parent process id is %d\n", getppid());
        sleep(10);
    }

    else
    {
        printf("Parent process is running...\n");
        printf("Parent process id is %d\n", getpid());
        sleep(5);
        return 0;
    }

    printf("Program is about to finish!\n");

    return 0;
}
