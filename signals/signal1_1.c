#include <stdio.h> 
#include <signal.h>
#include <stdlib.h> 
#include <unistd.h>

void handle_SigInt(int sig) 
{
    //printf("Handle Signal\n"); 
    //printf("Caught signal %d\n", sig); 
    write(STDOUT_FILENO, "Caught signal\n",6);
}

int main() 
{ 
    signal(SIGINT, handle_SigInt); 
    int N = 5;
    while (1) 
    { 
        printf("Hello world\n"); 
        sleep(1);
        N--;
        if (N<0) {
            printf("Signal handler returns to default now, press Ctrl-C to terminate!\n");
            signal(SIGINT, SIG_DFL);  
            break;
        }
    } 
    while (1)
    {
        /* code */
    }
    

    return 0; 
} 