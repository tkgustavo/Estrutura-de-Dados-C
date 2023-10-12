#include <stdio.h>

// Função recursiva para calcular a potência de um número
int potencia(int base, int expoente) {
    if (expoente == 0) {
        return 1;
    } else if (expoente > 0) {
        return base * potencia(base, expoente - 1);
    } else {
        // Lidando com expoentes negativos
        return 1.0 / (base * potencia(base, -expoente - 1));
    }
}

int main() {
    int base, expoente;
    
    printf("Digite a base: ");
    scanf("%d", &base);
    printf("Digite o expoente: ");
    scanf("%d", &expoente);
    
    int resultado = potencia(base, expoente);
    printf("%d elevado a %d é igual a %d\n", base, expoente, resultado);
    
    return 0;
}
