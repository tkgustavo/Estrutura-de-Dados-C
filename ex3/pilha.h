/* Arquivo: pilha.h
* Biblioteca de operações para pilha implementada com alocação dinâmica de memória.
*/
#define VERDADEIRO 1
#define FALSO 0

typedef struct nodo *pilha;
typedef struct nodo *pt_nodo;

typedef struct nodo {
    elemento e;
    pt_nodo prox;
    pt_nodo ant;  // Ponteiro para o nodo antecessor
} tnodo;

/*
* Cria uma pilha vazia.
*/
void CriarPilha(pilha *topo) {
    *topo = NULL;
}

/*
* Verifica se a pilha está vazia.
*/
int PilhaVazia(pilha *topo) {
    return (*topo == NULL);
}

/*
* Insere um novo elemento na pilha.
*/
void Empilhar(pilha *topo, elemento x) {
    pt_nodo aux;
    aux = (pt_nodo)malloc(sizeof(tnodo));
    aux->e = x;
    aux->prox = *topo;
    aux->ant = NULL;  // O antecessor do primeiro elemento é nulo

    if (*topo != NULL)
        (*topo)->ant = aux;  // Atualiza o antecessor do nodo anterior
    *topo = aux;
}

/*
* Retira um elemento da pilha.
*/
elemento Desempilhar(pilha *topo) {
    elemento x;
    pt_nodo aux;
    aux = *topo;

    if (*topo == NULL) {
        printf("A pilha está vazia.\n");
        exit(1);
    }

    *topo = (*topo)->prox;
    if (*topo != NULL)
        (*topo)->ant = NULL;  // Atualiza o antecessor do novo topo

    x = aux->e;
    free(aux);
    return x;
}
