typedef int TipoElemento;

typedef struct TipoCelula *TipoApontador;

typedef struct {
	TipoElemento Elemento;
} TipoItem;

typedef struct TipoCelula {
	TipoItem Item;
	TipoApontador Prox;
}TipoCelula;

typedef struct {
	TipoApontador Topo, Fundo;
	int Tamanho;
}TipoPilha;

void FPVazia(TipoPilha *Pilha);

int Vazia(TipoPilha Pilha);

void Empilhar(TipoPilha *Pilha, TipoItem x);