#include <stdio.h>

// Função recursiva para calcular a soma dos primeiros n números naturais
int somaNaturais(int n) {
    if (n <= 0) {
        return 0;
    } else {
        return n + somaNaturais(n - 1);
    }
}

int main() {
    int n;
    
    printf("Digite um número n: ");
    scanf("%d", &n);
    
    int resultado = somaNaturais(n);
    printf("A soma dos primeiros %d números naturais é igual a %d\n", n, resultado);
    
    return 0;
}
