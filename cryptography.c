#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "texto.txt"

// Função para criptografar o texto usando a cifra de César
void criptografarTexto() {
    FILE *file = fopen(FILE_NAME, "r+");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char ch;
    long pos;

    // Lê e criptografa o texto, deslocando 3 caracteres para frente
    while ((pos = ftell(file)) != -1 && (ch = fgetc(file)) != EOF) {
        if ((ch >= 'a' && ch <= 'z')) {
            ch = ((ch - 'a' + 3) % 26) + 'a';
        } else if ((ch >= 'A' && ch <= 'Z')) {
            ch = ((ch - 'A' + 3) % 26) + 'A';
        }
        fseek(file, pos, SEEK_SET);
        fputc(ch, file);
    }

    fclose(file);
    printf("Texto criptografado com sucesso!\n");
}

// Função para descriptografar o texto usando a cifra de César
void descriptografarTexto() {
    FILE *file = fopen(FILE_NAME, "r+");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char ch;
    long pos;

    // Lê e descriptografa o texto, deslocando 3 caracteres para trás
    while ((pos = ftell(file)) != -1 && (ch = fgetc(file)) != EOF) {
        if ((ch >= 'a' && ch <= 'z')) {
            ch = ((ch - 'a' - 3 + 26) % 26) + 'a';
        } else if ((ch >= 'A' && ch <= 'Z')) {
            ch = ((ch - 'A' - 3 + 26) % 26) + 'A';
        }
        fseek(file, pos, SEEK_SET);
        fputc(ch, file);
    }

    fclose(file);
    printf("Texto descriptografado com sucesso!\n");
}

// Função para exibir o texto no arquivo
void mostrarTexto() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char ch;
    printf("Conteúdo do arquivo:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    putchar('\n');

    fclose(file);
}

int main() {
    int opcao;

    do {
        printf("\nMenu\n");
        printf("1 – Criptografar texto\n");
        printf("2 – Descriptografar texto\n");
        printf("3 – Mostrar texto\n");
        printf("9 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criptografarTexto();
                break;
            case 2:
                descriptografarTexto();
                break;
            case 3:
                mostrarTexto();
                break;
            case 9:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 9);

    return 0;
}

