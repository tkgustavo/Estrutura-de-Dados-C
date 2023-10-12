#include <stdio.h>

int main() {
    double peso, novoPeso;
    
    printf("Informe o peso da pessoa: ");
    scanf("%lf", &peso);
    
    novoPeso = peso * 1.15;
    printf("Se a pessoa engordar 15%%, o novo peso será: %.2lf\n", novoPeso);
    
    novoPeso = peso * 0.8; 
    printf("Se a pessoa emagrecer 20%%, o novo peso será: %.2lf\n", novoPeso);

    return 0;
}
