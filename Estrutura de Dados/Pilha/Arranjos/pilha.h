
#define TAM 5

typedef int TipoElemento;
typedef int TipoApontador;

typedef struct {
	TipoElemento Elemento;
}TipoItem;

typedef struct {
	TipoItem Item[TAM];
	TipoApontador Topo;
}TipoPilha;

void FPVazia(TipoPilha *Pilha);

int Vazia(TipoPilha Pilha);

void Inserir(TipoPilha *Pilha, TipoItem x);

void Remover(TipoPilha *Pilha);

int Tamanho(TipoPilha Pilha);