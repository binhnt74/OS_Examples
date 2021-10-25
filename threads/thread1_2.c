#include <pthread.h>
#include <stdio.h>

int N = 10;
int sum = 0;
void* runner(int* n){
    int i;
    sum = 0;
    int N = *n;
    for (i=1;i<=N;i++)
        sum += i;
    printf("sum = %d\n", sum);
    pthread_exit(0);
}
int main(){
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    int k = 5;
    pthread_create(&tid, &attr, runner, &k);
    pthread_join(tid, NULL);
    return 0;
}
