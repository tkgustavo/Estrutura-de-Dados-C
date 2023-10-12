#include <stdio.h>
#include <stdlib.h>

struct Pessoa {
    long long cpf;
    char nome[50];
    double salario;
};

struct Pessoa *alocarPessoas(int n) {
    struct Pessoa *pessoas = (struct Pessoa *)calloc(n, sizeof(struct Pessoa));
    if (pessoas == NULL) {
        printf("Falha na alocação de memória.\n");
        exit(1);
    }
    return pessoas;
}

void imprimirPessoas(struct Pessoa *pessoas, int n) {
    printf("Pessoas:\n");
    for (int i = 0; i < n; i++) {
        printf("CPF: %lld, Nome: %s, Salário: %.2f\n", pessoas[i].cpf, pessoas[i].nome, pessoas[i].salario);
    }
}

int main() {
    struct Pessoa *pessoas;
    int n;
    printf("Digite o número de pessoas: ");
    scanf("%d", &n);

    pessoas = alocarPessoas(n);

    imprimirPessoas(pessoas, n);

    free(pessoas);
    return 0;
}
