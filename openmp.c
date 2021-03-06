#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]) 
{
#pragma omp parallel for
    for (int i = 0; i < omp_get_num_threads(); ++i)
    {    
        printf("C OpenMP. Process-thread: %s-%d\n", argv[1], i);
    }
    return 0;

}
