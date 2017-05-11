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

int Eliminar(Lista *ptlis,int valor){
	Nodo *aux=ptlis->ini;
	Nodo *auxElim;
	int eliminado=0;
	if (valor==aux->num){
		auxElim=aux;
		ptlis->ini=aux->sgte;
		ptlis->tam--;
		auxElim->sgte=NULL;
		eliminado=1;
		free(auxElim);
	}else{
		while (aux->sgte!=NULL && eliminado!=1){
			if (aux->sgte->num!=valor){
				aux=aux->sgte;
			}else{
				auxElim=aux->sgte;
				aux->sgte=aux->sgte->sgte;
				ptlis->tam--;
				auxElim->sgte=NULL;
				eliminado=1;
				free(auxElim);
			}
		}
	}
	return eliminado;
}

int calcularMaximo(Nodo *nod, int max){
	if (nod->sgte == NULL){
		return max;
	}else{
		if(max < nod->num){
			return calcularMaximo(nod->sgte,nod->num);
		}else{
			return calcularMaximo(nod->sgte,max);
		}
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
	agregarDato(list,52);
	agregarDato(list,7);
	recorreLis(list);
	aux=list->ini;
	num=calcularMaximo(aux, 0);
	printf("\nEl mayor numero de la Lista es : %d",num);


	return 0;	
}

