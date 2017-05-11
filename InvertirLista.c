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

void insertaralFinal(Lista *lista, int var){
	Nodo *nodo1; 
	nodo1 = malloc(sizeof(Nodo));
	nodo1->num = var;
	nodo1->sgte = NULL;
	Nodo *nodo2;
	nodo2 = lista->fin;
	lista->fin = nodo1;
	nodo2->sgte = nodo1;
	lista->tam = lista->tam++;

}

/*FUNCION ELIMINAR ELEMENTO DE LA LISTA*/

int Eliminar(Lista *ptlis,int valor){
	Nodo *aux = ptlis->ini;  
	Nodo *auxE;
	int eliminado = 0;
	if  (valor==aux->num){	//verificar si el nodo incial es = al valor
		auxE = aux;
		ptlis->ini = aux->sgte;
		ptlis->tam = ptlis->tam --;
		auxE->sgte = NULL ; 
		eliminado = 1 ; 
		free(auxE); 

	}else{
		while (eliminado != 1 && aux->sgte != ptlis->fin){
			if(aux->sgte->num != valor){
				aux = aux->sgte;
				
			}else{
				auxE = aux->sgte;
				aux->sgte= aux->sgte->sgte;
				auxE->sgte = NULL;
				ptlis->tam = ptlis->tam--;
				eliminado = 1;
				free(auxE);
			}
		}

		if (valor == aux->sgte->num){ 	//verifica si el valor a eliminar es el ultimo
			auxE = aux->sgte;
			ptlis->fin = aux;
			aux->sgte = aux->sgte;
			aux->sgte = NULL;
			ptlis->tam = ptlis->tam--;
			free(auxE);
			eliminado = 1;
			
		} 
	}
	return eliminado;
}

void invertirLista(Lista *lista){
	int variable;//guarda el dato
	if (lista->ini->sgte != NULL){
		variable = lista->ini->num;
		Eliminar(lista,lista->ini->num);
		invertirLista(lista);
		insertaralFinal(lista,variable);
	}
}

int main(int argc, char *argv[]){
	int num=0;
	Lista *list;
	Lista *list2;
	Nodo *aux;	
	Nodo *aux2;	
	list=crearLista();

	printf ("\n");
	agregarDato(list,1);
	agregarDato(list,4);
	agregarDato(list,5);
	agregarDato(list,2);
	agregarDato(list,7);
	agregarDato(list,8);
	aux=list->ini;
	recorreLis(list);
	
	invertirLista(list);
	printf ("\n\nINVIRTIENDO LA LISTA:\n\n");
	
	recorreLis(list);


	return 0;	
}

