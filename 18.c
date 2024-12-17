#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct {
    int itens[TAM];
    int frente;
    int tras;
} Fila;

void inicializarFila(Fila *f) {
    f->frente = 0;
    f->tras = 0;
}

int filaCheia(Fila *f) {
    return (f->tras == TAM);
}

int filaVazia(Fila *f) {
    return (f->frente == f->tras);
}

void inserir(Fila *f, int valor) {
    if (filaCheia(f)) {
        printf("Erro: a fila está cheia!\n");
    } else {
        f->itens[f->tras] = valor;
        f->tras++;
        printf("Inserido: %d\n", valor);
    }
}

void remover(Fila *f) {
    if (filaVazia(f)) {
        printf("Erro: a fila está vazia!\n");
    } else {
        printf("Removido: %d\n", f->itens[f->frente]);
        for (int i = 0; i < f->tras - 1; i++) {
            f->itens[i] = f->itens[i + 1];
        }
        f->tras--;
    }
}

void imprimir(Fila *f) {
    if (filaVazia(f)) {
        printf("A fila está vazia.\n");
    } else {
        printf("Fila: ");
        for (int i = f->frente; i < f->tras; i++) {
            printf("%d ", f->itens[i]);
        }
        printf("\n");
    }
}

int main() {
    Fila fila;
    inicializarFila(&fila);
    int opcao, valor;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir\n");
        printf("2. Remover\n");
        printf("3. Imprimir\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um valor para inserir: ");
                scanf("%d", &valor);
                inserir(&fila, valor);
                break;
            case 2:
                remover(&fila);
                break;
            case 3:
                imprimir(&fila);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 4);

    return 0;
}
