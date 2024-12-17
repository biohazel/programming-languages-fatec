#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Definindo o tamanho máximo da pilha

typedef struct {
    float elementos[MAX];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p) {
    p->topo = -1; // Inicializando topo
}

int pilhaVazia(Pilha *p) {
    return (p->topo == -1);
}

int pilhaCheia(Pilha *p) {
    return (p->topo == MAX - 1);
}

void push(Pilha *p, float valor) {
    if (pilhaCheia(p)) {
        printf("Pilha cheia! Não é possível inserir mais elementos.\n");
    } else {
        p->topo++;
        p->elementos[p->topo] = valor;
        printf("%.2f inserido na pilha.\n", valor);
    }
}

float pop(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia! Não há elementos para remover.\n");
        return -1;
    } else {
        float valorRemovido = p->elementos[p->topo];
        p->topo--;
        return valorRemovido;
    }
}

void imprimirPilha(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia!\n");
    } else {
        printf("Conteúdo da pilha:\n");
        for (int i = p->topo; i >= 0; i--) {
            printf("%.2f\n", p->elementos[i]);
        }
    }
}

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);

    int opcao;
    float valor;

    do {
        printf("\nMenu:\n");
        printf("1 - Push (inserir)\n");
        printf("2 - Pop (remover)\n");
        printf("3 - Imprimir\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%f", &valor);
                push(&pilha, valor);
                break;
            case 2:
                valor = pop(&pilha);
                if (valor != -1)
                    printf("%.2f removido da pilha.\n", valor);
                break;
            case 3:
                imprimirPilha(&pilha);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}
