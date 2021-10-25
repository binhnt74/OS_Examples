#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

#define N 10000
#define N_THREADS 300

volatile int cnt = 0;
sem_t mutex;

void *runner(void *arg)
{
    int i = 0;
    for (i = 0; i < N; i++)
    {
        sem_wait(&mutex);
        cnt++;
        sem_post(&mutex);
    }
    //printf("Hello Thread \n");
    //pthread_exit(0);
}
int main()
{
    //int n = 3;
    pthread_t tid[N_THREADS];
    
    sem_init(&mutex, 0, 1);
    //pthread_attr_t attr;
    //pthread_attr_init(&attr);
    int i = 0;
    for (i = 0; i < N_THREADS; i++)
        pthread_create(&tid[i], NULL, runner, NULL);
    for (i = 0; i < N_THREADS; i++)
        pthread_join(tid[i], NULL);
    sem_destroy(&mutex);
    
    if (cnt != N_THREADS * N)
    {
        printf("Boom %d\n", cnt);
    }
    else
    {
        printf("Ok %d\n", cnt);
    }
    
    return 0;
}