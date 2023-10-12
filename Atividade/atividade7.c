#include <stdio.h>

int main() {
    float salarioMinimo, salario;

    printf("Digite o valor do salário mínimo: ");
    scanf("%f", &salarioMinimo);

    printf("Digite o valor do salário do funcionário: ");
    scanf("%f", &salario);

    float quantidadeSalariosMinimos = salario / salarioMinimo;
    printf("O funcionário recebe %.2f salários mínimos\n", quantidadeSalariosMinimos);

    return 0;
}
