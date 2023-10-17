/* Arquivo: lista.h
* Biblioteca de operações para lista implementada
* com vetor.
*/

#include <stdio.h>
#define VERDADEIRO 1
#define FALSO 0

#define TAM 10 // Defina o tamanho da lista

typedef float elemento;

struct tipo_lista {
    elemento vet[TAM];
    int inicio, fim;
};

typedef struct tipo_lista lista;

// Cria lista.
void CriarLista(lista *l) {
    l->inicio = -1; // Modificação: Inicia o início com -1
    l->fim = -1; // Modificação: Inicia o fim com -1
}

// Verifica se a lista está vazia.
int ListaVazia(lista *l) {
    return (l->inicio == -1);
}

// Verifica se a lista está cheia.
int ListaCheia(lista *l) {
    return (l->fim == TAM - 1);
}

// Insere um elemento na lista.
void Alistar(lista *l, elemento e, int pos) {
    int i;
    if (ListaCheia(l)) {
        printf("\n ERRO: lista cheia!");
    } else if (pos < 0 || pos > l->fim + 1) {
        printf("\n ERRO: posição não existe!");
        printf("\n Posicoes validas: [0, %d].", l->fim);
    } else {
        for (i = l->fim; i >= pos; i--) {
            l->vet[i + 1] = l->vet[i];
        }
        l->vet[pos] = e;
        l->fim++;
    }
}

// Retira um elemento da lista.
elemento Desalistar(lista *l, int pos) {
    int i;
    elemento e;
    if (ListaVazia(l)) {
        printf("\n ERRO: lista vazia!");
        return 0; // Retorna 0 como um valor padrão em caso de erro.
    } else if (pos < 0 || pos > l->fim) {
        printf("\n ERRO: posição não existe!");
        printf("\n Posicoes validas: [0, %d].", l->fim);
        return 0; // Retorna 0 como um valor padrão em caso de erro.
    } else {
        e = l->vet[pos];
        for (i = pos; i < l->fim; i++) {
            l->vet[i] = l->vet[i + 1];
        }
        l->fim--;
        return e;
    }
}

// Imprime o conteúdo da lista.
void ImprimeLista(lista *l) {
    if (ListaVazia(l)) {
        printf("Lista vazia.\n");
    } else {
        printf("Lista: ");
        for (int i = l->inicio; i <= l->fim; i++) {
            printf("%.2f ", l->vet[i]);
        }
        printf("\n");
    }
}
