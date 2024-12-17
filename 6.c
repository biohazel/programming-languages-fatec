#include <stdio.h>

int main() {
    double num1, num2, resultado;
    char operacao;
    printf("Digite o primeiro numero: ");
    scanf("%lf", &num1);

    printf("Digite o segundo numero: ");
    scanf("%lf", &num2);

    printf("Escolha a operacao (+, -, *, /): ");
    scanf(" %c", &operacao);  

    switch (operacao) {
        case '+':
            resultado = num1 + num2;
            printf("Resultado: %.2lf\n", resultado);
            break;

        case '-':
            resultado = num1 - num2;
            printf("Resultado: %.2lf\n", resultado);
            break;

        case '*':
            resultado = num1 * num2;
            printf("Resultado: %.2lf\n", resultado);
            break;

        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
                printf("Resultado: %.2lf\n", resultado);
            } else {
                printf("Erro: Divisao por zero nao permitida!\n");
            }
            break;

        default:
            printf("Operacao invalida!\n");
            break;
    }

    return 0;
}