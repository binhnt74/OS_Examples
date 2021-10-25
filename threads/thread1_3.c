#include <pthread.h>
#include <stdio.h>
#define N 10000
#define N_THREADS 300

volatile int cnt = 0;

void *runner(void *arg)
{
    int i = 0;
    for (i = 0; i < N; i++)
    {
        cnt++;
    }
    //printf("Hello Thread \n");
    //pthread_exit(0);
}
int main()
{
    //int n = 3;
    pthread_t tid[N_THREADS];
    //pthread_attr_t attr;
    //pthread_attr_init(&attr);
    int i = 0;
    for (i = 0; i < N_THREADS; i++)
        pthread_create(&tid[i], NULL, runner, NULL);
    for (i = 0; i < N_THREADS; i++)
        pthread_join(tid[i], NULL);

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