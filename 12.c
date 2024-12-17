#include <stdio.h>
#define TAM 10

void registraDados(int vetor[]) {
    int i = 0, input;
    printf("Digite os elementos do vetor (Digite -1 para finalizar o registro e voltar ao menu):\n");
    while (i < TAM) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &input);
        
        if (input == -1) {  // Condição para finalizar a entrada de dados
            printf("Finalizando registro de dados...\n");
            break;  // Sai do loop e retorna ao menu
        }
        
        vetor[i] = input;  // Armazena o valor no vetor
        i++;
    }

    // Preenche os elementos restantes com 0 se o usuário sair antes de preencher todos
    for (int j = i; j < TAM; j++) {
        vetor[j] = 0;
    }
}

void mostrarVetor(int vetor[]) {
    printf("Elementos do vetor: ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void dobrarNumeros(int vetor[]) {
    for (int i = 0; i < TAM; i++) {
        vetor[i] *= 2;
    }
}

void imprimirPares(int vetor[]) {
    printf("Imprimindo numeros pares no vetor: ");
    for (int i = 0; i < TAM; i++) {
        if (vetor[i] % 2 == 0) {
            printf("%d ", vetor[i]);
        }
    }
    printf("\n");
}

void imprimirMaiorMenorNumero(int vetor[]) {
    int maior = vetor[0], menor = vetor[0];
    for (int i = 1; i < TAM; i++) {
        if (vetor[i] > maior) maior = vetor[i];
        if (vetor[i] < menor) menor = vetor[i];
    }
    printf("Maior elemento: %d\n", maior);
    printf("Menor elemento: %d\n", menor);
}

void contarImpares(int vetor[]) {
    int contador = 0;
    for (int i = 0; i < TAM; i++) {
        if (vetor[i] % 2 != 0) {
            contador++;
        }
    }
    printf("Quantidade de numeros impares eh: %d\n", contador);
}

void posicoesPares(int vetor[]) {
    printf("Elementos nas posicoes pares: ");
    for (int i = 0; i < TAM; i += 2) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void copiarInvertido(int vetor[], int aux[]) {
    for (int i = 0; i < TAM; i++) {
        aux[i] = vetor[TAM - 1 - i];
    }          
    printf("Vetor auxiliar invertido: ");
    mostrarVetor(aux);
}

int main() {
    int vetor[TAM], aux[TAM];
    int opcao;
    int dadosRegistrados = 0;  // Flag para verificar se os dados foram registrados

    do {
        // Primeiro, registra os dados obrigatoriamente
        if (!dadosRegistrados) {
            printf("\nÉ necessário registrar os dados no vetor primeiro.\n");
            registraDados(vetor);
            dadosRegistrados = 1;  // Marca como registrado
            continue;  // Pula o resto do loop e exibe o menu novamente
        }

        // Menu de opções
        printf("\nMenu de opcoes:\n");
        printf("1- Registrar dados do vetor\n");
        printf("2- Mostrar vetor\n");
        printf("3- Dobrar os numeros registrados no vetor\n");
        printf("4- Imprimir os pares\n");
        printf("5- Imprimir o maior e menor elemento\n");
        printf("6- Imprimir a quantidade de numeros impares\n");
        printf("7- Imprimir os elementos que estao nas posicoes pares\n");
        printf("8- Copiar os elementos invertidos em um vetor auxiliar e imprimir\n");
        printf("9- Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                registraDados(vetor);
                break;
            case 2:
                mostrarVetor(vetor);
                break;
            case 3:
                dobrarNumeros(vetor);
                break;
            case 4:
                imprimirPares(vetor);
                break;
            case 5:
                imprimirMaiorMenorNumero(vetor);
                break;
            case 6:
                contarImpares(vetor);
                break;
            case 7:
                posicoesPares(vetor);
                break;
            case 8:
                copiarInvertido(vetor, aux);
                break;
            case 9:
                printf("Saindo.\n");
                break;
            default:
                printf("Opcao Invalida\n");
        }
    } while (opcao != 9);

    return 0;
}

