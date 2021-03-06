#include <stdio.h>
#include <omp.h>
#include <mpi.h>

int main(int argc, char *argv[]) 
{
    MPI_Init(NULL, NULL);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

#pragma omp parallel for
    for (int i = 0; i < omp_get_num_threads(); ++i)
    {    
        printf("C hybrid. Process-thread: %s-%d\n", world_rank, omp_get_thread_num());
    }

    MPI_Finalize();
    return 0;

}
