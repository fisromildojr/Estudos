#include <stdlib.h>
#include <stdio.h>
#define n 29

int dist [n][n];
typedef int tour[n];
struct indtour{
	tour s;
	int avaliacao;
	double probabilidade;
};

void carregarMatrizDist(FILE *arquivo){
	int i,j;
	char str[201];
	FILE *arq = fopen(arquivo,"r");
		if(arq==NULL){
			printf("nao foi possivel abri o arquivo");
			return 0;
		}
		for (i=0;i<8;i++){
			fgets (str,200,arq);
		}
		
		for (i=0;i<n;i++){
			for (j=i+1;j<n;j++){
				dist[i][j]=0;
				dist [j][i]=0;
			}
		}
		for (i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				fscanf(arq,"%d",&dist[i][j]);
				dist[j][i]=dist[i][j];
			}
		}
		fclose(arq);
}

void mostrarMatrizDist(){
	int i,j;
	for (i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			printf("%d ",dist[i][j]);
		}
		printf("\n");
	}
}
//inicializar população
void initPop (struct indtour *pop, int tamPop){//algoritmo tipo chafor
	int i,j,p,q,k;
	tour s;
	for (i=0;i<tamPop;i++){
		pop[i].avaliacao = 0;
		pop[i].probabilidade = 0;
	}
	i=0;
	while(i<tamPop){
		for(j=0;j<n;j++){// coloca em sequencia
			s[j]=j;
		}
		for(j=0;j<tamPop*n;j++){ //embaralha 
			p=rand()%n;
			q=rand()%n;
			k=s[p];
			s[p]=s[q];
			s[q]=k;
		}
		for(j=0;j<n;j++){// cria a propulacao
			pop[i].s[j]=s[j];
		}
		i++;
	}
}

void mostrarIndTour(int ind,struct indtour *pop){
	int i;
	printf("\n");
	for(i=0;i<n;i++){
		printf("%d\n",pop[ind].s[i]);
	}
}

int avaliar(tour rota){
	int i=0;
	int custo=0;
	for(i=0;i<n-1;i++){
		custo+=dist[rota[i]][rota[i+1]];
	}
	custo=custo+dist[rota [n-1]][rota[0]];
	return custo;
}
/*função de avaliacao
funcao de probabilidade
ordenar a populacao
roleta mecamismo de seleção do individiu da selecao*/
void calcprobabilidade(struct indtour *pop, int tamPop){
	double somaprobabilidade =0;
	int i;
	for(i=0; i<tamPop; i++){
		pop[i].avaliacao = avaliar(pop[i].s);
		pop[i].probabilidade = (double) 1/pop[i].avaliacao;
		somaprobabilidade += pop[i].probabilidade;
	}
	for(i=0; i<tamPop; i++){
		pop[i].probabilidade = (double) pop[i].probabilidade/somaprobabilidade;
	}
}

void mostrarcustoProb(struct indtour *pop, int tamPop){
	int i;
	for(i=0; i<tamPop; i++){
		printf("\nCusto %d\n", pop[i].avaliacao);
		printf("Probabilidade %f\n", pop[i].probabilidade);
		printf("--------------------\n");
	}
}
// qsort(base, tam, tour_ind, funcao);
int compararCusto(const void *a, void *b){
	struct indtour *e1 = (struct indtour *) a;	
	struct indtour *e2 = (struct indtour *) b;
	return e1->avaliacao - e2->avaliacao;
}

int roleta(struct indtour *pop, int tamPop){
	int i, selecao=0;
	double rntNum = rand() / (double) RAND_MAX, limite=0;
	for(i=0; i<tamPop; i++){
		limite+= pop[i].probabilidade;
		if(rntNum < limite){
			selecao = i; break;
		}
	} 	
	return selecao;
}

void cruzamentoOX(struct indtour pai1,struct indtour pai2,struct indtour *filho1, struct indtour *filho2){
	int iniPos,fimPos,i,j;
	do{
		iniPos=rand ()% n;
		fimPos=rand ()% n;
	}while(iniPos==fimPos);
	
	if(iniPos>fimPos){
		i=iniPos;
		iniPos=fimPos;
		fimPos=i;
	}
	for(i=iniPos;i<fimPos;i++){
		filho1->s[i]=pai1.s[i];
		filho2->s[i]=pai2.s[i];
	}
		
		for(i=0;i<n;i++){
			if(!(possuiCidade(*filho1,pai2.s[i]))){
				for (j=0;j<n;j++){
					if(filho1->s[j]==-1){
						filho1->s[j]=pai2.s[i];
						break;
					}
				}
			}	
		
			if(!(possuiCidade(*filho2,pai1.s[i]))){
				for(j=0;j<n;j++){
					if(filho2->s[j]==-1){
						filho2->s[j]=pai1.s[i];
						break;
					}
				}
			}
		}
}


int possuiCidade (struct indtour filho, int cidade ){
	int i, encontrado =0;
	for(i=0;i<n;i++){
		if(filho.s[i]==cidade){
			encontrado=1;
			break;
		}
	}
	return encontrado;
}


void mutacao(struct indtour *ind){
	int cidade1, cidade2, aux;

	do{
		cidade1=rand()%n;
		cidade2=rand()%n;
	}while(cidade1==cidade2);

	aux = ind->s[cidade1];
	ind->s[cidade1]=ind->s[cidade2];
	ind->s[cidade2]=aux;
}


int main(int argc, char *argv[]){
	
	int geracoes, tamPop, i, j, s, tamElitismo;
	double probCross, probMut, rndCross, rndMut, txElitismo;

	tamPop = atoi(argv[2]);
	geracoes = atoi(argv[3]);
	probCross = atof(argv[4]);
	probMut = atof(argv[5]);
	txElitismo = atof(argv[6]);

	struct indtour pop[tamPop];
	struct indtour popTemp[tamPop];

	carregarMatrizDist(argv[1]);

	srand((unsigned) time(NULL) * getpid());

	initPop(pop, tamPop);

	calcprobabilidade(pop, tamPop);

	qsort(pop, tamPop, sizeof(struct indtour), compararCusto);

	tamElitismo = txElitismo * tamPop;

	s = 0;

	while(geracoes > s){
		
		j=0;

		while(j < (tamPop/2)){
			struct indtour filho1, filho2;
			int pai1=roleta(pop,tamPop);
			int pai2=roleta(pop,tamPop);
			memset(filho1.s,-1,n*sizeof(filho1.s[0]));
			memset(filho2.s,-1,n*sizeof(filho2.s[0]));

			rndCross=rand()/(double)RAND_MAX;

			if(rndCross < probCross){
				cruzamentoOX(pop[pai1],pop[pai2],&filho1,&filho2);
				rndMut=rand()/(double)RAND_MAX;
				if(rndMut < probMut){
					mutacao(&filho1);
					mutacao(&filho2);
				}
			}else{
				filho1 = pop[pai1];
				filho2 = pop[pai2];
			}
			
			filho1.avaliacao = avaliar(filho1.s);
			filho2.avaliacao = avaliar(filho2.s);
			
			popTemp[2*j] = filho1;
			popTemp[2*j+1] = filho2;
			
			j++;
		}

		calcprobabilidade(pop,tamPop);
		qsort(pop, tamPop, sizeof(struct indtour), compararCusto);

		for(i=tamElitismo;i<tamPop;i++){
			pop[i]=popTemp[i-tamElitismo];
		}

		printf("Geracao: %d - Melhor: %d\n", s, pop[0].avaliacao);

		s++;

	}

	mostrarIndTour(0, pop);

	return 0;
}
