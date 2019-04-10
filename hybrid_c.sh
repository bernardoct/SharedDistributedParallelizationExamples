#!/bin/bash
#PBS -N test_hybrid
#PBS -l nodes=2:ppn=16
#PBS -l walltime=:00:30
#PBS -o ./output/hybrid_c.out
#PBS -e ./error/hybrid_c.err
module load openmpi-1.10.7-gnu-x86_64
export OMP_NUM_THREADS=8

set -x
cd "$PBS_O_WORKDIR"

# Construct a copy of the hostfile with only 16 entries per node.
# MPI can use this to run 16 tasks on each node.
export TASKS_PER_NODE=2
uniq "$PBS_NODEFILE"|awk -v TASKS_PER_NODE="$TASKS_PER_NODE" '{for(i=0;i<TASKS_PER_NODE;i+=1) print}' > nodefile

#cat nodefile
mpiexec --hostfile nodefile -n 4 -x OMP_NUM_THREADS ./Hybrid
