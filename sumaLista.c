#include<stdio.h>
#include<stdlib.h>

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

int sumaLista(Nodo *aux){		
	if(aux != NULL){
			return (aux->num + sumaLista(aux->sgte));		
		return sumaLista(aux->sgte);
	}else{
		return 0;
	}
}

int main(int argc, char *argv[]){
	int num;
	Lista *list;
	Nodo *aux;	
	list=crearLista();
	printf ("\n");
	agregarDato(list,7);
	agregarDato(list,4);
	agregarDato(list,5);
	agregarDato(list,5);
	agregarDato(list,7);
	recorreLis(list);
	aux=list->ini;
	num=sumaLista(aux);
	printf ("\n\nLa suma de la lista es: %d",num);
	return 0;	
}

