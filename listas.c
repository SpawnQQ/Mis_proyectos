#include <stdio.h>
#include <mpi.h>

#define MASTER_TO_SLAVE_TAG 1
#define SLAVE_TO_MASTER_TAG 0
#define TAG 0
#define WORKTAG	1
int main(int argc, char **argv)
{
	int ierr, num_procs, my_id=0;
	int aux1,aux2,aux3,resultado;
	int varianza;
	int v1[3],v2[3],v3[3];
	MPI_Status stat;
  	ierr = MPI_Init(&argc, &argv);
	ierr = MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
  	ierr = MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
		
	if(my_id==0){

		for(int i=0;i<9;i++){
			if(i<3){
				v1[i]=i;
			}else{
				if(i>=3 && i<6){
					v2[i-3]=i;				
				}
				else{
					if(i>=6){
						v3[i-6]=i;			
					}			
				}
			}
		}
		MPI_Send(&v1, 3, MPI_INT, 1, 20, MPI_COMM_WORLD);
		MPI_Send(&v2, 3, MPI_INT, 2, 21, MPI_COMM_WORLD);
		MPI_Send(&v3, 3, MPI_INT, 3, 22, MPI_COMM_WORLD);
		
				
	}else{
	if(my_id==1){
		MPI_Recv(&v1, 3, MPI_INT, 0, 20, MPI_COMM_WORLD, &stat);
		aux1=(v1[0]+v1[1]+v1[2])/3;
		printf("Calculo promedio %d",aux1);
		printf(" Nodo 1\n");
		MPI_Send(&aux1, 1, MPI_INT, 0, 23, MPI_COMM_WORLD);
		
	}else{
	if(my_id==2){
		MPI_Recv(&v2, 3, MPI_INT, 0,21, MPI_COMM_WORLD, &stat);
		aux2=(v2[0]+v2[1]+v2[2])/3;
		printf("Calculo promedio %d",aux2);
		printf(" Nodo 2\n");
		MPI_Send(&aux2, 1, MPI_INT, 0, 24, MPI_COMM_WORLD);
				
	}else{
	if(my_id==3){
		MPI_Recv(&v3, 3, MPI_INT, 0,22, MPI_COMM_WORLD, &stat);
		aux3=(v3[0]+v3[1]+v3[2])/3;
		printf("Calculo promedio %d",aux3);
		printf(" Nodo 3\n");
		MPI_Send(&aux3, 1, MPI_INT, 0, 25, MPI_COMM_WORLD);
	}	}}}	


	if(my_id==0){
		MPI_Recv(&aux1, 1, MPI_INT, 1, 23, MPI_COMM_WORLD,&stat);
		MPI_Recv(&aux2, 1, MPI_INT, 2, 24, MPI_COMM_WORLD,&stat);
		MPI_Recv(&aux3, 1, MPI_INT, 3, 25, MPI_COMM_WORLD,&stat);
		resultado=(aux1+aux2+aux3)/3;
		varianza=((aux1-resultado)*(aux1-resultado)+(aux2-resultado)*(aux2-resultado)+(aux3-resultado)*(aux3-resultado))/3;
		printf("Calculo promedio total %d",resultado);
		printf(" Nodo maestro\n");
		printf("Calculo varianza %d",varianza);
		printf(" Nodo maestro\n");
		
	}


  ierr = MPI_Finalize();
	
	
	
    return 0;
}

