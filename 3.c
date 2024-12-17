# include <stdio.h>

int main () 
{
	float  nota1, nota2, nota3, media, resultado;
	printf("Digite a primeira, segunda e terceira notas na sequencia: ");
	scanf("%f", &nota1);
        scanf("%f", &nota2);
        scanf("%f", &nota3);	
	media = (nota1 + nota2 + nota3)/3;
	if (media >= 6)
       	{
		printf("O aluno foi aprovado.");
	} else if (media < 3) 
	{
		printf("O aluno foi reprovado.");
	} else if (media >= 3 && media < 6) 
	{
	printf("O aluno esta de exame.");
	}
	return 0;
}

