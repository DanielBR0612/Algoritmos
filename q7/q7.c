#include <stdio.h>


int main(){
    int n;
    int u, d, c;

    printf("Digite um numero de 3 digitos:\n");
    scanf("%d", &n);

    c = n/100;
    d = (n / 10) % 10;
    u = n % 10;

    printf("seu numero invertido %d%d%d", u,d,c);

    return 0;
}