#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void FPVazia(TipoPilha *Pilha){
	Pilha->Topo = (TipoApontador) malloc(sizeof(TipoItem));
	Pilha->Topo->Prox = -1;
}

int Vazia(TipoPilha Pilha){
	return (Pilha->Topo->Prox == -1);
}
