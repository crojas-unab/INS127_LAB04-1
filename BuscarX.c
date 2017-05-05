#include<stdio.h>
#include<stdlib.h>

int buscarX(int *A,int c,int x);
 
int main(){
	int x, columnas=4, result=0;
	/*SOLICITO ENTRADA POR TECLADO*/
	printf ("ingrese el valor a buscar:\n >: ");
	scanf("%i",&x);

	/*DECLARO Y ASIGNO VALORES AL ARREGLO*/	
	int *A= (int*) malloc(columnas*sizeof(int));	
	A[0]=5;
	A[1]=6;
	A[2]=9;
	A[3]=2;
	
	result=buscarX(A,columnas,x);
	if (result== x)
		printf("encontrado ->%d",result);
	else{
		printf("numero no encontrado");
	}
	return 0;
}

int buscarX(int *A, int c,int x){
	// caso base
	if (A[c-1]==x){
		return A[c-1];
	}
	
	if (c==1){
		return A[0];
	}
	else{				
		return buscarX(A,c-1, x);	
	}
	
}
