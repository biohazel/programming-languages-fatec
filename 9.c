#include <stdio.h>
#include <math.h>

int main() {
	int N;
	double S = 0.0;  
	 int i;
	 printf("Digite o valor de N: ");
	 scanf("%d", &N);
	 for (i = 1; i <= N; i++) {
	 double term = pow(i, (double)(i+1) / (2 * i));  
	 S += term;  
			                                              }
			
	 printf("A somatória dos %d primeiros termos da série é: %f\n", N, S);
			
	 return 0;
	 }
		
