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

int calcularOcurrencia(Nodo *aux,int n){
	
	
	if(aux != NULL){
		if(aux->num == n){
			return ( 1 + calcularOcurrencia(aux->sgte,n));
		}
		return calcularOcurrencia(aux->sgte,n);
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
	agregarDato(list,78);
	agregarDato(list,45);
	agregarDato(list,45);
	agregarDato(list,45);
	agregarDato(list,45);
	recorreLis(list);
	aux=list->ini;
	num=calcularOcurrencia(aux,45);
	printf ("\n\nEl numero buscado 45 se repite %d veces",num);
	return 0;	
}

