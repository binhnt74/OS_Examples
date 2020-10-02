#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#define N 5

int psum(int a[], int b, int e){
    int s = 0;
    int i;
    for (i = b;i<=e;i++){
        s += a[i];
    }
    return s;
}
int main()
{
    printf("Parallel summing!\n");
    //const int N = 5;
    int a[N] = {1, 2, 3, 4, 5};
    int s = psum(a, 0, N-1);

    printf("Sum = %d\n", s);
    
    pid_t pid;      //process id
    pid = fork();   //creating a new child process
    if (pid < 0)
    {
        printf("Fork failed");
        return -1;
    }
    else if (pid == 0){
        printf("Child process is running...\n");
        //printf("Child process id is %d\n", getpid());
        //printf("My parent process id is %d\n", getppid());
        s++;
        printf("Sum of child = %d\n", s);

    }

    else
    {
        printf("Parent process is running...\n");
        //printf("Parent process id is %d\n", getpid());
        printf("Sum of parent = %d\n", s);
        //return 0;
    }

    //printf("Program is about to finish!\n");

    return 0;
}
