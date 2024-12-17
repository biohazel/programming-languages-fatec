//Escreva um programa que leia x números (o usuário deve entrar com o valor de x) e, por meio do laço for, o programa retorne a somatória dos números pares digitados.



# include <stdio.h>
int main () {
	int x;
	int valor;
	int soma = 0;
	int i;
	printf("Quantos inteiros voce quer somar?");
	scanf("%d", &x);
	for (i = 0; i < x; i++) {
		printf("Escreva seus numeros separando-os por Enter que eu vou armazenar os %d numeros \n", x);
		scanf("%d", &valor);
		if (valor % 2 == 0);
		soma = soma + valor;
	}
        printf("A soma resultou em %d \n", soma);

return 0;
}
