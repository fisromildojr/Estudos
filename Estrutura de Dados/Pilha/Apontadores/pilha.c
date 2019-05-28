#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void FPVazia(TipoPilha *Pilha){
	Pilha->Topo = (TipoApontador) malloc(sizeof(TipoCelula));
	Pilha->Base = Pilha->Topo;
	Pilha->Topo->Prox = NULL;
	Pilha->Tamanho = 0;
}

int Vazia(TipoPilha Pilha){
	return (Pilha.Topo == Pilha.Base);
}

void Empilhar(TipoPilha *Pilha, TipoItem x){
	TipoApontador Aux;
	Aux = (TipoApontador) malloc(sizeof(TipoCelula));
	Aux->Prox = Pilha->Topo;
	Pilha->Topo->Item = x;
	Pilha->Topo = Aux;
	Pilha->Tamanho++;
}

void Desempilhar(TipoPilha *Pilha, TipoItem *x){
	TipoApontador Aux;
	*x = Pilha->Topo->Prox->Item;
	Aux = Pilha->Topo;
	Pilha->Topo = Aux->Prox;
	free(Aux);
	Pilha->Tamanho--;
}

void Imprimir(TipoPilha Pilha){
	TipoApontador Aux;
	Aux = Pilha.Topo;
	while( Aux != Pilha.Base){
		printf("%d\n", Aux->Prox->Item.Chave);
		Aux = Aux->Prox;
	}
}
