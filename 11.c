#include <stdio.h>

int main () {
    int number, i;
    unsigned long long factorial = 1;

    printf("Digite um numero para calcular o fatorial? ");
    scanf("%d", &number);

    if(number < 0) {
      printf("Fatorial nao esta definido para numeros negativos. \n");

} else {
    i = number;
    while (i > 0) {
    factorial *= i;
    i--;
}

     printf("Fatorial de %d eh %llu\n", number, factorial);

}
    return 0;



}
