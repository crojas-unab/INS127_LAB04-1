#include<stdio.h>
#include<stdlib.h>

int imprimirArreglo(int *A,int c);
 
int main(){
	int a,b,c,d,columnas=4, result=0;	
	/*SOLICITO ENTRADA POR TECLADO*/
	printf ("ingrese el valor de a:\n >: ");
	scanf("%i",&a);
	printf ("ingrese el valor de b:\n >: ");
	scanf("%i",&b);
	printf ("ingrese el valor de c:\n >: ");
	scanf("%i",&c);
	printf ("ingrese el valor de d:\n >: ");
	scanf("%i",&d);

	/*DECLARO Y ASIGNO VALORES AL ARREGLO*/	
	int *A= (int*) malloc(columnas*sizeof(int));
	A[0]=a;
	A[1]=b;
	A[2]=c;
	A[3]=d;
	int *ptra , *ptrb,*ptrc,*ptrd;
	
	result=imprimirArreglo(A,columnas);
	printf("--->%d\n", result);
	return 0;
}

int imprimirArreglo(int *A, int c){
	// caso base
	
	if (c==1){
		return A[0];
	}
	else{
		
		printf("--->%d\n",A[c-1]);
		
		return imprimirArreglo(A,c-1);	
	}
	
}
