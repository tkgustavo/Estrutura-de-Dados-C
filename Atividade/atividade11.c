#include <stdio.h>

int main() {
    int numero;
    
    printf("Informe um número: ");
    scanf("%d", &numero);
    
    for (int i = 0; i <= 10; i++) {
        printf("%d x %d = %d\n", numero, i, numero * i);
    }

    return 0;
}
