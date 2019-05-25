#define TAM 10

typedef int TipoApontador;
typedef int TipoElemento;
typedef struct
{
	TipoElemento Elemento;
}TipoItem;
typedef struct
{
	TipoItem Item[TAM];
	TipoApontador Inicio, Fim;
}TipoLista;

void FLVazia(TipoLista *Lista);

int Vazia(TipoLista *Lista);

int Cheia(TipoLista *Lista);

void Inserir(TipoLista *Lista, TipoItem x);

void Remover(TipoLista *Lista, TipoItem *Item, TipoApontador p);

void Imprimir(TipoLista Lista);