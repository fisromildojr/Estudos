#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void FLVazia(TipoLista *Lista){
	Lista->Inicio = (TipoApontador) malloc(sizeof(TipoCelula));
	Lista->Fim = Lista->Inicio;
	Lista->Fim->Prox = NULL;
}

int Vazia(TipoLista Lista){
	return (Lista.Inicio == Lista.Fim);
}

void Inserir(TipoLista *Lista, TipoItem x){
	Lista->Fim->Prox = (TipoApontador) malloc(sizeof(TipoCelula));
	Lista->Fim = Lista->Fim->Prox;
	Lista->Fim->Item = x;
	Lista->Fim->Prox = NULL;
}

/*

void Remover(TipoLista *Lista, TipoItem *x, TipoApontador p){
	TipoApontador Aux;
	if(Vazia(*Lista)){
		printf("ERRO: Lista vazia ou a posicao nao existe!");
		return;
	}
	
	Aux = p->Prox;
	*x = Aux->Item;
	p->Prox = Aux->Prox;
void Remover(TipoLista *Lista, TipoItem *x, TipoApontador p){
	TipoApontador Aux;
	if(Vazia(*Lista)){
		printf("ERRO: Lista vazia ou a posicao nao existe!");
		return;
	}
	
	Aux = p->Prox;
	*x = Aux->Item;
	p->Prox = Aux->Prox;

	if(p->Prox == NULL){
		Lista->Fim = p;
	}
	free(Aux);
}	if(p->Prox == NULL){
		Lista->Fim = p;
	}
	free(Aux);
}

*/

void Imprimir(TipoLista Lista){
	TipoApontador Aux;
    Aux = Lista.Inicio->Prox;    
    while(Aux != NULL){
        printf("%d\n", Aux->Item.Elemento);
        Aux=Aux->Prox;
    }
}