typedef int TipoElemento;
typedef struct TipoCelula *TipoApontador;

typedef struct {
	TipoElemento Elemento;
} TipoItem;

typedef struct TipoCelula {
	TipoItem Item;
	TipoApontador Prox;
} TipoCelula;

typedef struct {
	TipoApontador Inicio;
	TipoApontador Fim;
}TipoLista;

void FLVazia(TipoLista *Lista);

int Vazia(TipoLista Lista);

void Inserir(TipoLista *Lista, TipoItem x);

//void Remover(TipoLista *Lista, TipoItem *x, TipoApontador p);

void Imprimir(TipoLista Lista);
