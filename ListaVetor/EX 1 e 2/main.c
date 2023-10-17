#include <stdio.h>
#include <stdlib.h>

#define TAM 10
typedef float elemento;

struct tipo_lista {
    elemento vet[TAM];
    int inicio, fim;
};

typedef struct tipo_lista lista;

void CriarLista(lista *l) {
    l->inicio = 0;
    l->fim = -1;
}

int ListaVazia(lista *l) {
    return (l->fim < l->inicio);
}

int ListaCheia(lista *l) {
    return (l->fim == TAM - 1);
}

void Alistar(lista *l, elemento e) {
    if (ListaCheia(l)) {
        printf("\n ERRO: lista cheia!");
    } else {
        l->fim++;
        l->vet[l->fim] = e;
    }
}

elemento Desalistar(lista *l) {
    elemento e;
    if (ListaVazia(l)) {
        printf("\n ERRO: lista vazia!");
        return 0; // Retorna 0 como um valor padrão em caso de erro.
    } else {
        e = l->vet[l->inicio];
        l->inicio++;
        return e;
    }
}

void GravarListaEmArquivo(lista *l, const char *nomeArquivo) {
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("\n ERRO: Não foi possível abrir o arquivo para escrita!");
    } else {
        for (int i = l->inicio; i <= l->fim; i++) {
            fprintf(arquivo, "%f\n", l->vet[i]);
        }
        fclose(arquivo);
        printf("\nLista gravada no arquivo com sucesso!");
    }
}

void LerListaDoArquivo(lista *l, const char *nomeArquivo) {
    FILE *arquivo;
    elemento num;
    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("\n ERRO: Não foi possível abrir o arquivo para leitura!");
    } else {
        while (fscanf(arquivo, "%f", &num) != EOF && !ListaCheia(l)) {
            Alistar(l, num);
        }
        fclose(arquivo);
    }
}

void ImprimirLista(lista *l) {
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

int main() {
    lista l;
    CriarLista(&l);

    // Leitura de números reais a partir do teclado e enfileiramento.
    printf("Informe 10 numeros reais:\n");
    for (int i = 0; i < TAM; i++) {
        elemento num;
        printf("Numero %d: ", i + 1);
        scanf("%f", &num);
        Alistar(&l, num);
    }

    // Gravação da lista em um arquivo de texto.
    GravarListaEmArquivo(&l, "lista.txt");

    // Leitura da lista a partir do arquivo e enfileiramento.
    CriarLista(&l); // Reinicializa a lista.
    LerListaDoArquivo(&l, "lista.txt");

    // Impressão da lista na tela.
    ImprimirLista(&l);

    return 0;
}
