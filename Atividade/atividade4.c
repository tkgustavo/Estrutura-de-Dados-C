#include <stdio.h>

int main() {
    float salario;

    printf("Digite o salário do funcionário: ");
    scanf("%f", &salario);

    float novoSalario = salario + (0.25 * salario);
    printf("Novo salário com aumento de 25%%: %.2f\n", novoSalario);

    return 0;
}
