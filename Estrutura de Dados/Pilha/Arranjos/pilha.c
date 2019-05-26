#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void FPVazia(TipoPilha *Pilha) {
	Pilha->Topo = 0;
}

int Vazia(TipoPilha Pilha){
	return (Pilha.Topo == 0);
}

void Inserir(TipoPilha *Pilha, TipoItem x){
	Pilha->Topo++;
	Pilha->Item[Pilha->Topo-1]=x;
}

void Remover(TipoPilha *Pilha){
	Pilha->Topo--;
}

int Tamanho(TipoPilha Pilha){
	return (Pilha.Topo);
}