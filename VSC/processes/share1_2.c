#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

void* ptr = NULL;

/* create a shared memory with a name and
the size (in bytes) */
void* createSharedMemory(char* name, int size)
{
    /* shared memory file descriptor */
    int shm_fd;
    /* pointer to shared memory obect */
    void *ptr;
    /* create the shared memory object */
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    /* configure the size of the shared memory object */
    ftruncate(shm_fd, size);
    /* memory map the shared memory object */
    ptr = mmap(0, size, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    int * p = ptr;
    *p = 0;
    return ptr;
}
void exec_ChildProcess()
{
    printf("Child process is running...\n");
    int* p = (int*) ptr;
    for (int i=0; i<10; i++)
        (*p)++;
    printf("Shared value from child: %d\n",*p);
    exit(0);
}

void exec_ParentProcess()
{
    printf("Parent process is running...\n");
    int* p = (int*) ptr;
    for (int i=0; i<10; i++)
        (*p)++;
    printf("Shared value from parent: %d\n",*p);
    printf("Parent is waiting for any child to terminate...\n");
    wait(NULL);
    printf("My child terminated!\n");

}
int create_2processes()
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
        //exec_ChildProcess();
        printf("Child process is running...\n");
        int* p = (int*) ptr;
        for (int i=0; i<10000; i++)
            (*p)++;
        printf("Shared value from child: %d\n",*p);
        exit(0);
    }

    else
    {
        //exec_ParentProcess();
        printf("Parent process is running...\n");
        printf("Parent id is %d\n", getpid());
        int* p = (int*) ptr;
        for (int i=0; i<10000; i++)
            (*p)++;
        printf("Shared value from parent: %d\n",*p);
        printf("Parent is waiting for any child to terminate...\n");
        wait(NULL);
        printf("My child terminated!\n");
    }
    return 0;
}

int main()
{
    int msize = 4096;
    char *name = "SharedMem";

    ptr = createSharedMemory(name, msize);
    if (ptr == NULL)
        return -1;
    int *p = ptr;
    create_2processes();
    printf("Final shared value: %d\n", *p);
    return 0;
}
