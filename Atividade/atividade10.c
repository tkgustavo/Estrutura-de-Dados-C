#include <stdio.h>
#include <math.h>

int main() {
    double raio;
    const double PI = 3.14159265359;
    
    printf("Informe o raio da esfera: ");
    scanf("%lf", &raio);
    
    double comprimento = 2 * PI * raio;
    double area = PI * raio * raio;
    double volume = (3.0 / 4.0) * PI * raio * raio * raio;
    
    printf("Comprimento da esfera: %.2lf\n", comprimento);
    printf("Área da esfera: %.2lf\n", area);
    printf("Volume da esfera: %.2lf\n", volume);

    return 0;
}
