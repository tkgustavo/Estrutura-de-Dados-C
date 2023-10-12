#include <stdio.h>

int main() {
    float cotacaoDolar, valorDolar;

    printf("Digite a cotação do dólar em reais: ");
    scanf("%f", &cotacaoDolar);

    printf("Digite o valor em dólares: ");
    scanf("%f", &valorDolar);

    float valorEmReais = cotacaoDolar * valorDolar;
    printf("Valor em reais: %.2f\n", valorEmReais);

    return 0;
}
