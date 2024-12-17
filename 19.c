#include <stdio.h>
#include <math.h>

// Funções para o cálculo dos valores necessários
double calcularDelta(double A, double B, double C) {
    return (B * B) - (4 * A * C);
}

void calcularRaizes(double A, double B, double delta, double *x1, double *x2) {
    if (delta < 0) {
        printf("As raízes são complexas e não reais.\n");
        *x1 = *x2 = 0;
    } else {
        *x1 = (-B + sqrt(delta)) / (2 * A);
        *x2 = (-B - sqrt(delta)) / (2 * A);
    }
}

double calcularVx(double A, double B) {
    return -B / (2 * A);
}

double calcularVy(double A, double delta) {
    return -delta / (4 * A);
}

// Funções para operações com matriz
void registrarDados(double matriz[3][3]) {
    printf("Insira os dados para a matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%lf", &matriz[i][j]);
        }
    }
}

void mostrarDados(double matriz[3][3]) {
    printf("Matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2lf ", matriz[i][j]);
        }
        printf("\n");
    }
}

double somatoriaDados(double matriz[3][3]) {
    double soma = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            soma += matriz[i][j];
        }
    }
    return soma;
}

// Lista de números inteiros
#define TAM 100
int lista[TAM];
int tamanho = 0;

void inserir(int valor) {
    if (tamanho < TAM) {
        lista[tamanho] = valor;
        tamanho++;
    } else {
        printf("Lista cheia!\n");
    }
}

void remover(int valor) {
    int encontrado = 0;
    for (int i = 0; i < tamanho; i++) {
        if (lista[i] == valor) {
            for (int j = i; j < tamanho - 1; j++) {
                lista[j] = lista[j + 1];
            }
            tamanho--;
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Valor não encontrado na lista.\n");
    }
}

void imprimirLista() {
    printf("Lista de números inteiros:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main() {
    // Cálculo de função de segundo grau
    double A, B, C, delta, x1, x2, Vx, Vy;
    printf("Insira os valores de A, B e C da função de segundo grau: ");
    scanf("%lf %lf %lf", &A, &B, &C);

    delta = calcularDelta(A, B, C);
    calcularRaizes(A, B, delta, &x1, &x2);
    Vx = calcularVx(A, B);
    Vy = calcularVy(A, delta);

    printf("Delta: %.2lf\n", delta);
    printf("x1: %.2lf\n", x2);
    printf("x2: %.2lf\n", x2);
    printf("Vx (Vértice x): %.2lf\n", Vx);
    printf("Vy (Vértice y): %.2lf\n", Vy);

    // Operações com matriz
    double matriz[3][3];
    registrarDados(matriz);
    mostrarDados(matriz);
    double soma = somatoriaDados(matriz);
    printf("Somatória dos dados da matriz: %.2lf\n", soma);

    // Operações com lista de inteiros
    inserir(10);
    inserir(20);
    imprimirLista();
    remover(10);
    imprimirLista();

    return 0;
}

