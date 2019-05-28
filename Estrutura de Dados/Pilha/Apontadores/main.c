#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	TipoPilha Pilha;
	TipoItem x;
	
	FPVazia(&Pilha);
	
	x.Chave=2;
	Empilhar(&Pilha, x);
	
	x.Chave=3;
	Empilhar(&Pilha, x);
	
	x.Chave=5;
	Empilhar(&Pilha, x);
	
	if(Vazia(Pilha)){
		printf("A pilha esta vazia...");
	}
	else{
		printf("O tamanho da pilha e de %d itens...\n", Pilha.Tamanho);
		Imprimir(Pilha);
	}
	
	Desempilhar(&Pilha, &x);
	
	printf("\nO Item desempilhado foi %d ...\n", x.Chave);
	
	Imprimir(Pilha);
	
	return 0;
}
