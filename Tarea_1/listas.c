#include <stdio.h>
#include <mpi.h>

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
		
	//Nodo maestro
	if(my_id==0){
		/*Separamos el vector en este caso el vector sera v={0,1,2,3,4,5,6,7,8}
		en el nodo maestro hacemos la separacion del vector y lo enviamos
		a los otros nodos
		*/ 
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
		/*Aca enviamos a los nodos 1,2 y 3, los argumentos de send son
		MPI_Send(variable (un vector en este caso),tamaño, tipo de variable,
		numero de nodo, el TAG y la comunicacion con MPI_COMM_WORLD)
		*/
		MPI_Send(&v1, 3, MPI_INT, 1, 20, MPI_COMM_WORLD);
		MPI_Send(&v2, 3, MPI_INT, 2, 21, MPI_COMM_WORLD);
		MPI_Send(&v3, 3, MPI_INT, 3, 22, MPI_COMM_WORLD);
		
				
	}else{
	if(my_id==1){
		/*Aca recibimos lo que envio el nodo maestro y calculamos el promedio
		los argumentos de recv son MPI_Recv(variable, tamaño variable, tipo variable,
		de que nodo recibe, TAG, comunicacion por mpi, status)		
		*/
		MPI_Recv(&v1, 3, MPI_INT, 0, 20, MPI_COMM_WORLD, &stat);
		/*Promedio del primer vector*/ 
		aux1=(v1[0]+v1[1]+v1[2])/3;
		printf("Calculo promedio %d",aux1);
		printf(" Nodo 1\n");
		/*Eviamos el resultado del promedio al nodo maestro*/
		MPI_Send(&aux1, 1, MPI_INT, 0, 23, MPI_COMM_WORLD);
		
	}else{
	if(my_id==2){
		MPI_Recv(&v2, 3, MPI_INT, 0,21, MPI_COMM_WORLD, &stat);
		/*Promedio del segundo vector*/
		aux2=(v2[0]+v2[1]+v2[2])/3;
		printf("Calculo promedio %d",aux2);
		printf(" Nodo 2\n");
		/*Enviamos el promedio al nodo maestro*/
		MPI_Send(&aux2, 1, MPI_INT, 0, 24, MPI_COMM_WORLD);
				
	}else{
	if(my_id==3){
		MPI_Recv(&v3, 3, MPI_INT, 0,22, MPI_COMM_WORLD, &stat);
		/*Promedio del segundo vector*/
		aux3=(v3[0]+v3[1]+v3[2])/3;
		printf("Calculo promedio %d",aux3);
		printf(" Nodo 3\n");
		/*Enviamos el resultado del promedio al nodo maestro*/
		MPI_Send(&aux3, 1, MPI_INT, 0, 25, MPI_COMM_WORLD);
	}	}}}	


	if(my_id==0){
		/*Volvemos al nodo maestro y recibimos todos los promedios de los nodos 1,2 y 3*/
		MPI_Recv(&aux1, 1, MPI_INT, 1, 23, MPI_COMM_WORLD,&stat);
		MPI_Recv(&aux2, 1, MPI_INT, 2, 24, MPI_COMM_WORLD,&stat);
		MPI_Recv(&aux3, 1, MPI_INT, 3, 25, MPI_COMM_WORLD,&stat);
		/*Calculamos el promedio total con el promedio parcial de los vectores 1,2 y 3*/
		resultado=(aux1+aux2+aux3)/3;
		/*Calculamos la varianza usando los valores promedio y mostramos por pantalla los resultados
		todo esto esta en el nodo maestro		
		*/
		varianza=((aux1-resultado)*(aux1-resultado)+(aux2-resultado)*(aux2-resultado)+(aux3-resultado)*(aux3-resultado))/3;
		printf("Calculo promedio total %d",resultado);
		printf(" Nodo maestro\n");
		printf("Calculo varianza %d",varianza);
		printf(" Nodo maestro\n");
		
	}


  ierr = MPI_Finalize();
	
	
	
    return 0;
}

