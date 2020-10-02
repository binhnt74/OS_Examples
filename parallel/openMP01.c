#include <omp.h>
#include <stdio.h>

int main(){
    #pragma omp parallel
    {
        int i = omp_get_thread_num();
        printf("Hello %d\n", i);
        printf("OpenMP %d\n", i);
    }
    return 0;
}