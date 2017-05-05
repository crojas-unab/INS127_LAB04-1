#include<stdio.h>

int calcularFactorial(int x);
 
int main(){
	int x = 9, resultado=0;		
	resultado = calcularFactorial(x);
	printf("\n El resultado es ==> %d", resultado);
	
	return 0;
}

int calcularFactorial(int n){
	/* caso base*/
	//printf("\n x=%d",n);
	if(n < 1){
		return 1;
	}
	else{
		//printf ("%d\n",x);
		n=calcularFactorial(n-1)*n;
		
		return n;
	}
}
