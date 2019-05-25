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

	Imprimir(Lista);
	
	return 0;
}