#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t id;
    printf("Hello, Process World!\n");

    id=fork();
    if(id>0)
    {
        /*parent process*/
        printf("Process id returned by fork: %d\n", id);
        printf("This is parent section [Process id: %d].\n",getpid());
    }
    else if(id==0)
    {
        /*child process*/
        printf("fork created [Process id: %d].\n",getpid());
        printf("fork parent process id: %d.\n",getppid());
    }
    else
    {
        /*fork creation failed*/
        printf("fork creation failed!!!\n");
    }

    /* duplicate code */
    int i;
    printf("Printing the numbers from 1 to 10\n");
    for(i=1; i<=10; i++)
        printf("%d ",i);
    printf("\n");

    return 0;

}
