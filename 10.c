#include <stdio.h>

int main () {
    float peso, altura, imc;
    float maior_peso = 0;
    float menor_peso = 0;
    float maior_altura = 0;
    float menor_altura = 0;
    float maior_imc = 0;
    float menor_imc = 0;
    float soma_pesos = 0;
    float soma_alturas = 0;
    float soma_imcs = 0;
    int contador = 0;  // Variável para contar o número de entradas
    char continuar;  // Variável para controlar o loop

    do {
        printf("Digite o peso da pessoa em kg: ");
        scanf(" %f", &peso);
        printf("Digite a altura da pessoa em metros: ");
        scanf(" %f", &altura);

        // Calcula IMC
        imc = peso / (altura * altura);

        // Atualizar maior e menor peso
        if (contador == 0 || peso < menor_peso) menor_peso = peso;
        if (contador == 0 || peso > maior_peso) maior_peso = peso;

        // Atualizar maior e menor altura
        if (contador == 0 || altura < menor_altura) menor_altura = altura;
        if (contador == 0 || altura > maior_altura) maior_altura = altura;

        // Atualizar maior e menor IMC
        if (contador == 0 || imc > maior_imc) maior_imc = imc;
        if (contador == 0 || imc < menor_imc) menor_imc = imc;
        
        // Acumula para médias
        soma_pesos += peso;
        soma_alturas += altura;
        soma_imcs += imc;
        contador++;
      
        printf("Deseja inserir os dados de outra pessoa? [s]im ou [n]ao: ");
        scanf(" %c", &continuar);

    } while(continuar == 's' || continuar == 'S');

    // Calcula as médias
    float media_pesos = soma_pesos / contador;
    float media_alturas = soma_alturas / contador;
    float media_imcs = soma_imcs / contador;

    // Mostra os resultados
    printf("\nResultados:\n");
    printf("Maior peso: %.2f kg\n", maior_peso);
    printf("Menor peso: %.2f kg\n", menor_peso);
    printf("Maior altura: %.2f metros\n", maior_altura); 
    printf("Menor altura: %.2f metros\n", menor_altura);
    printf("Maior IMC: %.2f\n", maior_imc);
    printf("Menor IMC: %.2f\n", menor_imc);
    printf("Media dos pesos: %.2f kg\n", media_pesos);
    printf("Media das alturas: %.2f metros\n", media_alturas);
    printf("Media dos IMCs: %.2f\n", media_imcs);

    return 0;
}

