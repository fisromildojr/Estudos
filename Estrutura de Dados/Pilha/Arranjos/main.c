#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(int argc, char const *argv[])
{
	TipoPilha Pilha;
	TipoItem x;

	FPVazia(&Pilha);

	x.Elemento = 2;
	Inserir(&Pilha, x);

	printf("%d\n", Tamanho(Pilha));

	Remover(&Pilha);

	printf("%d\n", Tamanho(Pilha));

	return 0;
}