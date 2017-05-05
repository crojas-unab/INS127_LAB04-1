#include<stdio.h>

int multiplicarConSuma(int x, int y);
 
int main(){
	int x = 75, y=29, resultado=0;		
	resultado = multiplicarConSuma(x, y);
	printf("\n El resultado es ==> %d", resultado);
	
	return 0;
}

int multiplicarConSuma(int x, int y){
	/* caso base*/
	//printf("\n x=%d == y=%d", x, y);
	if(y == 1){
		return x;
	}
	else{
		//printf ("%d\n",x);
		x=x+multiplicarConSuma(x, y-1);
		
		return x;
	}
}
