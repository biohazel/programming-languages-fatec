#include <stdio.h>

int main () {
	int n;
	float media=0;
	float total_media=0;
	printf("Vamos calcular a media de temperaturas. Quantas temperaturas vc quer checar?");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		float temperatura=0;
		printf("Escreva suas temperaturas na sequencia separadas por Enter.");
		scanf("%f", &temperature);
		total_media = total_media + temperatura;
	}
	media = total_media/n;
	printf("A media eh de %f \n", media);


return 0;
}


