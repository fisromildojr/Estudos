typedef int TipoElemento;

typedef struct TipoItem *TipoApontador;

typedef struct TipoItem {
	TipoElemento Elemento;
	TipoApontador Prox;
} TipoItem;

typedef struct {
	TipoItem Topo;
}TipoPilha;

void FPVazia(TipoPilha *Pilha);

int Vazia(TipoPilha Pilha);
