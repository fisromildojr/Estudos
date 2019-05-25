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

void Imprimir(TipoLista Lista){
	TipoApontador Aux;
    Aux = Lista.Inicio->Prox;    
    while(Aux != NULL){
        printf("%d\n", Aux->Item.Elemento);
        Aux=Aux->Prox;
    }
}