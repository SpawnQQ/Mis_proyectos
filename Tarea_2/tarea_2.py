from mpi4py import MPI
import random

def lista_aleatorios(n):
	lista=[0] *n
	for i in range(n):
		lista[i]=random.random()
	return lista

comm = MPI.COMM_WORLD
size = comm.Get_size()
rank = comm.Get_rank()

root = 0
promedio=0
sumatoria=0
l=lista_aleatorios(100)
div_tamaño = 100 / size

if rank == root:
	for i in range(100):
		promedio=promedio+l[i]
	promedio=promedio / 100

promedio = comm.bcast(promedio, root=root)
l = comm.bcast(l,root=root)

for i in range(div_tamaño*rank, div_tamaño*(rank+1)):
	sumatoria=(promedio-l[i])+sumatoria

sumatoria = comm.gather(sumatoria, root=root)

if rank == root:
	print diferencial
	
