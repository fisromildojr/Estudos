#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void FLVazia(TipoLista *Lista){
	Lista->Inicio = 0;
	Lista->Fim = Lista->Inicio;
}

int Vazia(TipoLista *Lista){
	return (Lista->Inicio == Lista->Fim);
}

int Cheia(TipoLista *Lista){
	return (Lista->Fim == TAM);
}

void Inserir(TipoLista *Lista, TipoItem x){
	if(Cheia(Lista)){
		printf("A lista esta cheia...\n");
	}else{
		Lista->Item[Lista->Fim]=x;
		Lista->Fim++;
	}
}

void Remover(TipoLista *Lista, TipoItem *Item, TipoApontador p){
	if(Vazia(Lista) || p > Lista->Fim){
		printf("A posicao nao existe...\n");
		return;
	}else{
		*Item = Lista->Item[p];
		Lista->Fim--;
		int i;
		for(i=p; i < Lista->Fim ;i++){
			Lista->Item[i] = Lista->Item[i+1];
		}
	}
}

void Imprimir(TipoLista Lista){
	TipoElemento i;

	for(i=0;i<Lista.Fim;i++){
		printf("[%d] = %d\n", i, Lista.Item[i].Elemento);
	}
}