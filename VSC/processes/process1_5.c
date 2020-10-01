#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int shared = 0;

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
      int i;
      for (i=0;i<10;i++)
         shared++;
      printf("shared in child is %d\n", shared);
      exit(0);
   }

   else
   {
      printf("Parent process is running...\n");
      int i;
      for (i=0;i<10;i++)
         shared++;
      printf("shared in parent is %d\n", shared);
      wait(NULL);
    }
   return;
}

int main()
{
   printf("Hello, World of Processes!\n");
   fork_example();
   return 0;
}
