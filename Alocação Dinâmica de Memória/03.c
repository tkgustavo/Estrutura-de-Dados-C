#include <stdio.h>
#include <stdlib.h>

struct Veiculo {
    int numeroChassi;
    char marca[50];
    char modelo[50];
    double preco;
};

struct Veiculo *alocarVeiculos(int n) {
    struct Veiculo *veiculos = (struct Veiculo *)malloc(n * sizeof(struct Veiculo));
    if (veiculos == NULL) {
        printf("Falha na alocação de memória.\n");
        exit(1);
    }
    return veiculos;
}

void imprimirVeiculos(struct Veiculo *veiculos, int n) {
    printf("Veículos:\n");
    for (int i = 0; i < n; i++) {
        printf("Chassi: %d, Marca: %s, Modelo: %s, Preço: %.2f\n", veiculos[i].numeroChassi, veiculos[i].marca, veiculos[i].modelo, veiculos[i].preco);
    }
}

int main() {
    struct Veiculo *veiculos;
    int n;
    printf("Digite o tamanho inicial do array de veículos: ");
    scanf("%d", &n);

    veiculos = alocarVeiculos(n);

    imprimirVeiculos(veiculos, n);

    int novo_tamanho = n + 5;
    veiculos = (struct Veiculo *)realloc(veiculos, novo_tamanho * sizeof(struct Veiculo));
    if (veiculos == NULL) {
        printf("Falha na realocação de memória.\n");
        exit(1);
    }

    imprimirVeiculos(veiculos, novo_tamanho);

    free(veiculos);
    return 0;
}
