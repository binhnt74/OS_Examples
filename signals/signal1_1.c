#include<stdio.h> 
#include<signal.h> 

void handle_SigInt(int sig) 
{
    //printf("Handle Signal\n"); 
    printf("Caught signal %d\n", sig); 
}

int main() 
{ 
    signal(SIGINT, handle_SigInt); 
    while (1) 
    { 
        printf("Hello world\n"); 
        sleep(1); 
    } 
    return 0; 
} 