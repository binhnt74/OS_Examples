#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    // printf() displays the string inside quotation
    printf("Hello, World!\n");
    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        printf("Fork failed");
        return -1;
    }
    else if (pid == 0){
        printf("Child is running\n");
        int r = 0;
        char file[]="/usr/bin/ls";
        char args[] = "-lh";
        r = execl(file, file, args, NULL);
        printf("Result: %d\n", r);
    }

    else
    {
        printf("Parent %d is waiting...\n", pid);
        wait(NULL);

        printf("Child completed\n");
    }

    return 0;
}
