#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Funcionario {
    char nome[50];
    float salario;
} Funcionario;

typedef struct Nodo {
    Funcionario funcionario;
    struct Nodo* prox;
} Nodo;

Nodo* criarNodo(Funcionario funcionario) {
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    if (!novo) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    novo->funcionario = funcionario;
    novo->prox = NULL;
    return novo;
}

void inserirNaPosicao(Nodo** inicio, Funcionario funcionario, int posicao) {
    Nodo* novo = criarNodo(funcionario);

    if (*inicio == NULL || posicao == 0) {
        novo->prox = *inicio;
        *inicio = novo;
        return;
    }

    Nodo* atual = *inicio;
    int contador = 0;

    while (contador < posicao - 1 && atual->prox != NULL) {
        atual = atual->prox;
        contador++;
    }

    novo->prox = atual->prox;
    atual->prox = novo;
}

void listarFuncionarios(Nodo* inicio) {
    if (inicio == NULL) {
        printf("Nenhum funcionário cadastrado.\n");
        return;
    }

    Nodo* atual = inicio;
    int contador = 0;

    printf("\nLista de Funcionários:\n");
    while (atual != NULL) {
        printf("Posição: %d | Nome: %s | Salário: %.2f\n", contador, atual->funcionario.nome, atual->funcionario.salario);
        atual = atual->prox;
        contador++;
    }
}

void apagarTodosFuncionarios(Nodo** inicio) {
    Nodo* atual = *inicio;

    while (atual != NULL) {
        Nodo* temp = atual;
        atual = atual->prox;
        free(temp);
    }

    *inicio = NULL;
    printf("Todos os registros foram apagados.\n");
}

void menu() {
    printf("\nOpções:\n");
    printf("1 - Cadastrar Funcionário\n");
    printf("2 - Listar Funcionários\n");
    printf("3 - Apagar Todos os Registros\n");
    printf("4 - Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    Nodo* inicio = NULL;
    int opcao;

    do {
        menu();
        scanf("%d", &opcao);
        getchar();  // Limpar o buffer do teclado

        switch (opcao) {
            case 1: {
                Funcionario funcionario;
                int posicao;

                printf("Digite o nome do funcionário: ");
                fgets(funcionario.nome, 50, stdin);
                funcionario.nome[strcspn(funcionario.nome, "\n")] = '\0';  // Remover o \n do final

                printf("Digite o salário do funcionário: ");
                scanf("%f", &funcionario.salario);

                printf("Digite a posição para inserir o funcionário: ");
                scanf("%d", &posicao);

                inserirNaPosicao(&inicio, funcionario, posicao);
                printf("Funcionário cadastrado com sucesso!\n");
                break;
            }
            case 2:
                listarFuncionarios(inicio);
                break;
            case 3:
                apagarTodosFuncionarios(&inicio);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                apagarTodosFuncionarios(&inicio);
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

