#include <stdio.h>

int main() {
    float nota1, nota2, nota3;

    printf("Digite três notas: ");
    scanf("%f %f %f", &nota1, &nota2, &nota3);

    float media = (nota1 + nota2 + nota3) / 3;
    printf("Média das notas: %.2f\n", media);

    return 0;
}
