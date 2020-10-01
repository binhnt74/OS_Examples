#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

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
    return ptr;
}
int main()
{
    int msize = 4096;
    char *name = "SharedMem";
    void* ptr = NULL;
    ptr = createSharedMemory(name, msize);
    if (ptr == NULL)
        return -1;
    const char *message_0 = "Hello ";
    const char *message_1 = "World!";
    /* write to the shared memory object */

    sprintf(ptr,"%s",message_0);
    char * st = ptr;
    ptr += strlen(message_0);
    sprintf(ptr,"%s",message_1);
    ptr += strlen(message_1);

    printf("%s", st);
    return 0;
}
