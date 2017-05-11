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


void EliminarX(Lista *list,Nodo *nodo,int var){
	Nodo *aux;
	if(var==nodo->num && list->ini==nodo){ //valido primera posicion del nodo
		aux=nodo;                                
		list->ini=aux->sgte;
		aux->sgte=NULL;
		list->tam--;
		free(aux);
	}else if (nodo->sgte!=NULL){
		EliminarX(list,nodo->sgte,var); //recursividad
		if(var==nodo->sgte->num){
			aux=nodo->sgte;
			nodo->sgte=nodo->sgte->sgte;
			aux->sgte=NULL;
			list->tam--;
			free(aux);
		}
	}
}

int main(int argc, char *argv[]){
	int number;
	Lista *list;
	Nodo *aux;	
	list=crearLista();
	printf ("\n");
	agregarDato(list,7);
	agregarDato(list,4);
	agregarDato(list,3);
	agregarDato(list,5);
	agregarDato(list,6);	
	recorreLis(list);
	printf("\nIngrese el numero a eliminar: ");
	aux=list->ini;
	scanf("%d",&number);	
	EliminarX(list,aux,number);
	recorreLis(list);

	return 0;	
}

