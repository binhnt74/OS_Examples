#include <pthread.h>
#include <stdio.h>

void* runner(void* arg){
    printf("Hello Thread \n");
    //pthread_exit(0);
}
int main(){
    //int n = 3;
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    int i = 0;
    //for (i=0;i<n;i++)
    pthread_create(&tid, NULL, runner, NULL);
    pthread_join(tid, NULL);
    
    return 0;
}