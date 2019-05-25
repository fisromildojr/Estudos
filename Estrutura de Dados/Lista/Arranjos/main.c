#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char const *argv[])
{
	TipoLista Lista;
	TipoItem x;
	TipoElemento i;

	FLVazia(&Lista);

	//Entrada de dados na lista;
	for(i=1;i<=TAM;i++){
		x.Elemento=i;
		Inserir(&Lista, x);
	}

	printf("Antes de remover posicao [3]\n");
	Imprimir(Lista);

	Remover(&Lista, &x, 3);

	printf("Depois de remover posicao [3]\n");
	Imprimir(Lista);
	
	return 0;
}