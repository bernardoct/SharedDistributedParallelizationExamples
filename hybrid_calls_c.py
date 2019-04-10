from mpi4py import MPI
import subprocess

comm = MPI.COMM_WORLD
rank = comm.Get_rank()

print 'Calling OpenmpTest from Python MPI rank {}'.format(rank)
function_call = ['./OpenmpTest', '{}'.format(rank)]
subprocess.call(function_call)

comm.Barrier()
