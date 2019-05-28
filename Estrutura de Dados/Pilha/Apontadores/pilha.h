typedef int TipoChave;
typedef struct TipoCelula *TipoApontador;

typedef struct {
	TipoChave Chave;
}TipoItem;

typedef struct TipoCelula{
	TipoItem Item;
	TipoApontador Prox;
}TipoCelula;

typedef struct {
	TipoApontador Base, Topo;
	int Tamanho;
}TipoPilha;

void FPVazia(TipoPilha *Pilha);

int Vazia(TipoPilha Pilha);

void Empilhar(TipoPilha *Pilha, TipoItem x);

void Desempilhar(TipoPilha *Pilha, TipoItem *x);

void Imprimir(TipoPilha Pilha);
