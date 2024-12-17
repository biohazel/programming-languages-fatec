#include <stdio.h>

#define TAM 4 // Definindo o tamanho da matriz como uma constante

// Função para registrar dados na matriz
void registrarDados(int matriz[TAM][TAM]) {
    printf("Digite os elementos da matriz (%d x %d):\n", TAM, TAM);
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

// Função para imprimir a matriz
void imprimirMatriz(int matriz[TAM][TAM]) {
    printf("Matriz:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para retornar a somatória dos elementos da matriz
int somatoriaElementos(int matriz[TAM][TAM]) {
    int soma = 0;
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            soma += matriz[i][j];
        }
    }
    return soma;
}

// Função para contar a quantidade de números pares na diagonal principal
int contarParesDiagonalPrincipal(int matriz[TAM][TAM]) {
    int contador = 0;
    for (int i = 0; i < TAM; i++) {
        if (matriz[i][i] % 2 == 0) {
            contador++;
        }
    }
    return contador;
}

// Função para encontrar o maior número na diagonal secundária
int maiorDiagonalSecundaria(int matriz[TAM][TAM]) {
    int maior = matriz[0][TAM - 1]; // Inicializa com o primeiro elemento da diagonal secundária
    for (int i = 1; i < TAM; i++) {
        if (matriz[i][TAM - 1 - i] > maior) {
            maior = matriz[i][TAM - 1 - i];
        }
    }
    return maior;
}

int main() {
    int matriz[TAM][TAM] = {0}; // Inicializa a matriz com zeros
    int opcao;

    do {
        // Exibindo o menu de opções
        printf("\nMenu:\n");
        printf("1. Registrar dados na matriz\n");
        printf("2. Imprimir a matriz\n");
        printf("3. Retornar a somatória dos elementos da matriz\n");
        printf("4. Retornar a quantidade de números pares da diagonal principal\n");
        printf("5. Retornar o maior número da diagonal secundária\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                registrarDados(matriz);
                break;
            case 2:
                imprimirMatriz(matriz);
                break;
            case 3:
                printf("Somatória dos elementos da matriz: %d\n", somatoriaElementos(matriz));
                break;
            case 4:
                printf("Quantidade de números pares na diagonal principal: %d\n", contarParesDiagonalPrincipal(matriz));
                break;
            case 5:
                printf("Maior número da diagonal secundária: %d\n", maiorDiagonalSecundaria(matriz));
                break;
            case 6:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 6); // Continua até que o usuário escolha a opção de sair

    return 0;
}
