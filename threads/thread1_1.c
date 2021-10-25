#include <pthread.h>
#include <stdio.h>
#define n 3

void* runner(void* arg){
    long id = *(long*)arg;
    printf("Thread %ld is running...\n", id);
    pthread_exit(0);
}
int main(){
    //int n = 3;
    pthread_t tid[n] = {1, 2, 3};
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    int i = 0;
    for (i=0;i<n;i++)
        pthread_create(&tid[i], &attr, runner, &tid[i]);
    for (i=0;i<n;i++)
        pthread_join(tid[i], NULL);
    return 0;
}