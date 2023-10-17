/* Arquivo: pilha.h
* Biblicoteca de operações para pilha implementada com alocação dinâmica de memória.
*/
#define VERDADEIRO 1
#define FALSO 0
typedef struct nodo *pilha;
typedef struct nodo *pt_nodo;
typedef struct nodo {
elemento e;
pt_nodo prox;
} tnodo;
/*
* Cria uma pilha vazia.
*/
void CriarPilha (pilha *topo) {
*topo = NULL;
}
/*
* Verifica se a pilha está vazia.
*/
int PilhaVazia (pilha *topo) {
return (*topo == NULL);
}
/*
* Insere um novo elemento na pilha.
*/
void Empilhar (pilha *topo, elemento x) {
pt_nodo aux;
aux = (pt_nodo) malloc (sizeof (tnodo));
aux->e = x;
aux->prox = *topo;
*topo = aux;
}
/*
* Retira um elemento da pilha.
*/
elemento Desempilhar (pilha *topo) {
elemento x;
pt_nodo aux;
aux = *topo;
*topo = (*topo)->prox;
x = aux->e;
free (aux);
return (x);
}