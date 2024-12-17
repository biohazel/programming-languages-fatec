# include <stdio.h>

int tristyle(float a, float b, float c) {
	if (a == b && b == c) {
		printf("equilatero\n");
	} else if (a != b && b != c && a != c) {
		printf("escaleno\n");
	} else {
		printf("isosceles\n");
	}
	return 0;
}

int main() {
	float lado1, lado2, lado3;
	char tipo[11];

	printf("Digite o valor do primeiro, segundo, e terceiro lado do candidato a triangulo.\n");
	scanf("%f", &lado1);
	scanf("%f", &lado2);
	scanf("%f", &lado3);

	if ((lado1 + lado2) > lado3 && (lado2 + lado3) > lado1 && (lado3 + lado1) > lado2) {
		tristyle(lado1, lado2, lado3);
	} else {
		printf("Ops, nao eh um triangulo, tente novamente.\n");
	}

	return 0;
}

