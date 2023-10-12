#include <stdio.h>

int main() {
    int anoNascimento, anoAtual;

    printf("Digite o ano de nascimento e o ano atual: ");
    scanf("%d %d", &anoNascimento, &anoAtual);

    int idadeAtual = anoAtual - anoNascimento;
    int idade2050 = 2050 - anoNascimento;

    printf("Idade no ano atual: %d anos\n", idadeAtual);
    printf("Idade em 2050: %d anos\n", idade2050);

    return 0;
}
