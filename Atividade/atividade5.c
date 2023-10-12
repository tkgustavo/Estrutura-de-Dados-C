#include <stdio.h>

int main() {
    float diagonalMaior, diagonalMenor;

    printf("Digite a diagonal maior e a diagonal menor do losango: ");
    scanf("%f %f", &diagonalMaior, &diagonalMenor);

    float areaLosango = (diagonalMaior * diagonalMenor) / 2;
    printf("Área do losango: %.2f\n", areaLosango);

    return 0;
}
