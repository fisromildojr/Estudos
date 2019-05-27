#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void FPVazia(TipoPilha *Pilha){
	Pilha->Topo = (TipoApontador) malloc(sizeof(TipoItem));
	Pilha->Fundo = Pilha->Topo;
	Pilha->Topo->Prox = NULL;
	Pilha->Tamanho = 0;
}

int Vazia(TipoPilha Pilha){
	return (Pilha.Topo == Pilha.Fundo);
}

void Empilhar(TipoPilha *Pilha, TipoItem x){
	TipoApontador Aux;
	Aux = (TipoApontador) malloc(sizeof(TipoItem));
	Pilha->Topo->Item = x;
	Aux->Prox = Pilha->Topo;
	Aux->Topo = Aux;
	Pilha->Tamanho++;
}