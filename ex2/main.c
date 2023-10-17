#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITULO 100
#define MAX_AUTOR 50
#define MAX_EDICAO 10

typedef struct {
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    char edicao[MAX_EDICAO];
} Livro;

typedef struct Nodo {
    Livro livro;
    struct Nodo* proximo;
} Nodo;

typedef struct {
    Nodo* topo;
} Pilha;

void CriarPilha(Pilha* pilha) {
    pilha->topo = NULL;
}

int PilhaVazia(Pilha* pilha) {
    return (pilha->topo == NULL);
}

void EmpilharLivro(Pilha* pilha, Livro livro) {
    Nodo* novoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (novoNodo == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o nodo.\n");
        exit(EXIT_FAILURE);
    }

    novoNodo->livro = livro;
    novoNodo->proximo = pilha->topo;
    pilha->topo = novoNodo;
}

void Desempilhar(Pilha* pilha) {
    if (PilhaVazia(pilha)) {
        printf("A pilha está vazia. Nenhum livro para desempilhar.\n");
        return;
    }

    Nodo* nodoRemovido = pilha->topo;
    pilha->topo = nodoRemovido->proximo;
    free(nodoRemovido);
}

void ImprimirConteudoPilha(Pilha* pilha) {
    Nodo* nodoAtual = pilha->topo;
    printf("Conteúdo da pilha:\n");
    while (nodoAtual != NULL) {
        Livro livro = nodoAtual->livro;
        printf("Título: %s, Autor: %s, Edição: %s\n", livro.titulo, livro.autor, livro.edicao);
        nodoAtual = nodoAtual->proximo;
    }
    printf("\n");
}

void SalvarPilhaEmArquivoBinario(Pilha* pilha, const char* nome_arquivo) {
    FILE* arquivo = fopen(nome_arquivo, "wb");
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    Nodo* nodoAtual = pilha->topo;
    while (nodoAtual != NULL) {
        Livro livro = nodoAtual->livro;
        fwrite(&livro, sizeof(Livro), 1, arquivo);
        nodoAtual = nodoAtual->proximo;
    }

    fclose(arquivo);
}

void LerArquivoParaPilha(Pilha* pilha, const char* nome_arquivo) {
    FILE* arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    Livro livro;
    while (fread(&livro, sizeof(Livro), 1, arquivo) == 1) {
        EmpilharLivro(pilha, livro);
    }

    fclose(arquivo);
}

int QuantidadeLivrosAteTitulo(Pilha* pilha, const char* tituloDesejado) {
    Nodo* nodoAtual = pilha->topo;
    int contador = 0;

    while (nodoAtual != NULL) {
        contador++;
        if (strcmp(nodoAtual->livro.titulo, tituloDesejado) == 0) {
            return contador;
        }
        nodoAtual = nodoAtual->proximo;
    }

    return -1;  // Livro não encontrado
}

int main() {
    Pilha acervo;
    CriarPilha(&acervo);

    int opcao;
    Livro novoLivro;

    do {
        printf("Menu:\n");
        printf("1. Adicionar um livro\n");
        printf("2. Imprimir o acervo na tela\n");
        printf("3. Salvar o acervo em um arquivo binário\n");
        printf("4. Carregar o acervo de um arquivo binário\n");
        printf("5. Consultar a posição de um livro pelo título\n");
        printf("0. Encerrar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Informe o título do livro: ");
                scanf(" %[^\n]s", novoLivro.titulo);

                printf("Informe o autor do livro: ");
                scanf(" %[^\n]s", novoLivro.autor);

                printf("Informe a edição do livro: ");
                scanf(" %[^\n]s", novoLivro.edicao);

                EmpilharLivro(&acervo, novoLivro);
                break;
            case 2:
                ImprimirConteudoPilha(&acervo);
                break;
            case 3: {
                char nome_arquivo[100];
                printf("Informe o nome do arquivo para salvar: ");
                scanf(" %[^\n]s", nome_arquivo);
                SalvarPilhaEmArquivoBinario(&acervo, nome_arquivo);
                break;
            }
            case 4: {
                char nome_arquivo[100];
                printf("Informe o nome do arquivo para carregar: ");
                scanf(" %[^\n]s", nome_arquivo);
                LerArquivoParaPilha(&acervo, nome_arquivo);
                break;
            }
            case 5: {
                char tituloDesejado[MAX_TITULO];
                printf("Informe o título do livro que deseja buscar: ");
                scanf(" %[^\n]s", tituloDesejado);
                int posicao = QuantidadeLivrosAteTitulo(&acervo, tituloDesejado);
                if (posicao == -1) {
                    printf("Livro não encontrado no acervo.\n");
                } else {
                    printf("O livro '%s' está na posicao %d na pilha.\n", tituloDesejado, posicao);
                }
                break;
            }
            case 0:
                // Encerra o programa
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
