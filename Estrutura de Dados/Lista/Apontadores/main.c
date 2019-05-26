#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char const *argv[])
{
	
	TipoLista Lista;
	TipoItem x;
	int i;

	FLVazia(&Lista);

	//Entrada de dados
	for(i=0;i<10;i++){
		x.Elemento=i;
		Inserir(&Lista, x);
	}

	//Saída de dados
//	printf("<<< Antes da Remocao >>>\n");
	if(Vazia(Lista)){
		printf("Lista vazia...\n");
	}else{
		Imprimir(Lista);
	}

	//Remover(&Lista, &x, p);
/*
	printf("<<< Depois da Remocao >>>\n");
	if(Vazia(Lista)){
		printf("Lista vazia...\n");
	}else{
		Imprimir(Lista);
	}
*/
	return 0;
}