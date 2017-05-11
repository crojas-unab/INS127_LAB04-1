#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct nodo{
	int num;
	struct nodo *sgte;
}Nodo;

typedef struct lista {
	Nodo *ini;
	Nodo *fin;
	int tam;
	
}Lista;

Lista *crearLista(){
	Lista *lista;
	if (lista=(Lista*)malloc(sizeof(Lista))){
	
		if(lista->tam=0)
			lista->ini=NULL;
			lista->fin=NULL;
			lista->tam=0;
	}
	else {
		printf ("Lista no tienen memoria asignada");
	}	
	return lista;
	free(lista);	
}

void agregarDato(Lista *l, int numero){
	Nodo *aux;
	if (aux=(Nodo*)malloc(sizeof(Nodo))){
		aux->num=numero;
		if (l->tam==0){
			aux->sgte=NULL;
			l->fin=aux;
			l->ini=aux;
		
		}
		else{
			aux->sgte=l->ini;
			l->ini=aux;			
		}
		l->tam++;
	}
	else {
		printf ("Lista no tienen memoria asignada");
	}
}

void recorreLis(Lista *l){
	Nodo *aux1;
	aux1=l->ini;
	printf("Los elemementos de la lista son:\n\n");
	int i;
	for (i=0;i<l->tam;i++){
		printf("%d",aux1->num);
		printf("\n");
		aux1=aux1->sgte;
	}
	free(aux1);
}


void ordenarLista(Lista *lis,Nodo *nodo,Nodo *nodo2){
	if(nodo->sgte != NULL && nodo2->sgte != NULL){
		if (nodo2->num > nodo2->sgte->num){
			int var;
			var = nodo2->num;
			nodo2->num = nodo2->sgte->num;
			nodo2->sgte->num = var;
			ordenarLista(lis,nodo,nodo2->sgte);	
		}
		ordenarLista(lis,nodo,nodo2->sgte);
	}else if(nodo->sgte == NULL){
		printf("");
	}else{
		nodo2 = lis->ini;
		ordenarLista(lis,nodo->sgte,nodo2);	
	}
}

void listarLista(Nodo *auxiliar){		
	if(auxiliar != NULL){
		printf("%d\n",auxiliar->num);
		listarLista(auxiliar->sgte);
	}
	else{
		printf("\n");
	}
}


void insertarFinal(Lista *list, int var){
	Nodo *aux; 
	aux = (Nodo*)malloc(sizeof(Nodo));
	aux->num = var;
	aux->sgte = NULL;
	Nodo *aux1;
	aux1 = list->fin;
	list->fin = aux;
	aux1->sgte = aux;
	list->tam ++;
}


void ingresarElementoDespues(Lista *lista,int var,int bus){
	Nodo *aux = lista->ini;
	Nodo *nodo; 
	nodo = malloc(sizeof(Nodo));
	nodo->num = var;
	nodo->sgte = NULL;
	if ( bus == aux->num){
		nodo->sgte = lista->ini->sgte;
		lista->ini->sgte = nodo;
		lista->tam ++ ;
	}else{
		int control = 0; 
		while(aux->sgte != NULL && control == 0){
			 	
			if (aux->num == bus){
				nodo->sgte = aux->sgte;
				aux->sgte = nodo;
				lista->tam ++ ;
				control = 1;
			}else{
				if (bus == aux->num && aux->sgte == lista->fin){
						insertarFinal(lista,var);
						lista->tam ++ ;
						control = 1;
				}
			}
			aux = aux->sgte;
		}
	}
}



void insertarOrdenado(Lista *lista,Nodo *nodo, int var){
	if(var >= nodo->num && var <= nodo->sgte->num){
		//condicion que agrega el numero de forma correcta.
		ingresarElementoDespues(lista,var,nodo->num);
		printf("\nIngresado Correctamente!\n ");
	}else if(var < lista->ini->num){
		//condicion crear un numero al inicio de la lista
		agregarDato(lista,var);
		printf("\nIngresado Correctamente!\n ");
	}else if(var > lista->fin->num){
		//verifica si el numero a agregar sera al final de la lista
		insertarFinal(lista,var);
		printf("\nIngresado Correctamente!\n ");
	}else if(nodo->sgte == NULL){
		printf("\n");
	}else{
		insertarOrdenado(lista,nodo->sgte,var);
	}
}

int main(int argc, char *argv[]){
	int number=0;
	Lista *list;
	Nodo *aux;	
	Nodo *aux2;	
	list=crearLista();

	printf ("\n");
	agregarDato(list,1);
	agregarDato(list,4);
	agregarDato(list,5);
	agregarDato(list,2);
	agregarDato(list,7);
	aux=list->ini;
	aux2=list->ini->sgte;

	recorreLis(list);
	ordenarLista(list,aux,aux2);
	printf("\nSu lista ordenanda es:\n");
	listarLista(aux);
	
	printf("\nInserte un nuevo elemento, para ordenarlo : ");
	scanf("%i",&number); 	
	insertarOrdenado(list,aux,number);
	
	printf("\nContenido de la lista + elemento ingresado : \n");
	Nodo *aux1=list->ini;
	listarLista(aux1);

	return 0;	
}

