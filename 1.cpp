/* Programa com duas funções, uma que percorre uma matriz tridimensional e 
conta o número de primos, e outra que recebe 5 primos e 
retorna a soma dos primos. Uso de estrutura composta multidimensional,
for loops e switch case para escolha da função pelo usuário.*/

#include <iostream>
using namespace std;

#define DIM1 3
#define DIM2 3
#define DIM3 3

// Função para verificar se um número é primo
bool ehPrimo(int numero) {
    if (numero <= 1) return false;
    
    int divisores = 0;
    for (int testDivisor = 1; testDivisor <= numero; testDivisor++) {
        if (numero % testDivisor == 0) {
            divisores++;
        }
    }
    
    return divisores == 2;
}

// Função para contar a quantidade de números primos na matriz tridimensional
int contaPrimos() {
    int matriz[DIM1][DIM2][DIM3] = {
        {
            {2, 34, 77},
            {51, 3, 46},
            {29, 88, 19}
        },
        {
            {17, 54, 91},
            {11, 65, 43},
            {23, 7, 58}
        },
        {
            {37, 96, 13},
            {25, 5, 64},
            {41, 85, 31}
        }
    };

    int quantidadePrimos = 0;
    
    for (int i = 0; i < DIM1; i++) {
        for (int j = 0; j < DIM2; j++) {
            for (int k = 0; k < DIM3; k++) {
                if (ehPrimo(matriz[i][j][k])) {
                    quantidadePrimos++;
                }
            }
        }
    }

    return quantidadePrimos;
}

// Função para somar cinco números primos fornecidos pelo usuário
int somaPrimos() {
    int soma = 0;
    int contador = 0;

    cout << "Digite 5 números:" << endl;
    while (contador < 5) {
        int numero;
        cin >> numero;

        if (ehPrimo(numero)) {
            soma += numero;
        }
        contador++;
    }

    return soma;
}

int main() {
    char escolha;
    do {
        cout << "Escolha uma função:\n";
        cout << "1. Contar a quantidade de primos na matriz tridimensional\n";
        cout << "2. Somar 5 números (considerando apenas primos)\n";
        cout << "Pressione E para sair.\n";
        cin >> escolha;

        switch (escolha) {
            case '1':
                cout << "Quantidade de primos na matriz: " << contaPrimos() << endl;
                break;
            case '2': {
                int soma = somaPrimos();
                cout << "A soma dos primos é: " << soma << endl;
                break;
            }
            case 'E':
            case 'e':
                cout << "Saindo do programa..." << endl;
                break;
            default:
                cout << "Escolha inválida!" << endl;
                break;
        }

        cout << endl; // Adiciona uma linha em branco para separar as iterações

    } while (escolha != 'E' && escolha != 'e');

    return 0;
}
