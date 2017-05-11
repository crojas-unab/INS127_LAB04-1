#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodo{
	int num;
	struct nodo *sgte;
}Nodo;

typedef struct {
	int tam;
	Nodo *fin;	
		
}Pila;

Pila* crearPila(){    
	Pila* aux;
	aux=(Pila*)malloc(sizeof(Pila));
	aux->fin=NULL;
	aux->tam=0;
}

void apilar(Pila *pila1,int valor){
	Nodo *nodo1;
	if(nodo1=(Nodo*)malloc(sizeof(Nodo))){
		nodo1->sgte=pila1->fin;
		pila1->tam++;
		pila1->fin=nodo1;
		nodo1->num=valor;
	}
}



bool esVacia(Pila *p){
	if (p->fin==NULL){
		return true;
	}else{
		return false;
	}												
}

Nodo* topPila(Pila *p){
	return p->fin;
}


Nodo *popPila(Pila* p){
	Nodo*aux;
	if(p->tam>0){
		aux=p->fin;	
		p->fin = aux->sgte;
		aux->sgte=NULL;
			
		
	}
	return aux;
	free(aux);

}

void mostrarPila(Pila *pila){
	Nodo *nodo1;
	if(!esVacia(pila)){
		printf("\nLos valores de la pila son: ");
		while(!esVacia(pila)){
			nodo1=popPila(pila);		
			printf("\n%d",nodo1->num);
		}
	}
	else{
		printf("\nLa pila esta vacia ");
	}		
	free(nodo1);
}

static void savePila(Pila *p, Pila *p2){
	int i;
	if (!esVacia(p)){  //SI LA PILA NO ESTA VACIA EJECUTA LO SIGUIENTE
		i=popPila(p)->num; //DESENCOLA EL NUMERO Y LO GUARDA EN i
		savePila(p,p2); // Copia datos en la otra pila
		apilar(p,i); //APILA NUEVAMENTE
		apilar(p2,i);
		}
	
}

static void inver(Pila *p, int d){
	int i;
	if (!esVacia(p)){  //SI LA PILA NO ESTA VACIA EJECUTA LO SIGUIENTE
		i=popPila(p)->num; //DESENCOLA EL NUMERO Y LO GUARDA EN i
		inver(p,d); 
		apilar(p,i); //APILA NUEVAMENTE

		}else{
			apilar(p,d);
		}
	
}
	

static void invertir(Pila *p){
	
	int i;
	if (!esVacia(p)){  //SI LA PILA NO ESTA VACIA EJECUTA LO SIGUIENTE
		i=popPila(p)->num; //DESENCOLA EL NUMERO Y LO GUARDA EN i		
		invertir(p); // ENTRA DE NUEVO A LA FUNCION
		inver(p,i); //APILA NUEVAMENTE
	}	
}




//MAIN
int main (int argc, char argv[]){
	int p;
	Pila *pila;
	Pila *pila2;
	pila=crearPila();
	pila2=crearPila();
	apilar(pila,1);
	apilar(pila,15);
	apilar(pila,3);
	apilar(pila,22);
	apilar(pila,8);
	apilar(pila,9);	
	savePila(pila,pila2);//COPIA LA PILA EN PILA 2
	mostrarPila(pila2); //MUESTRO ORDEN DE PILA
	printf("\n\nINVIRTIENDO PILA....\n ");
	invertir(pila); //FUNCION QUE INVIERTE PILA POR RECURSIVIDAD
	mostrarPila(pila); //PILA INVERTIDA
	return 0;

}
