#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]) 
{
#pragma omp parallel
{    
    printf("C OpenMP. Process-thread: %s-%d\n", argv[1], omp_get_thread_num());
}
    return 0;

}
