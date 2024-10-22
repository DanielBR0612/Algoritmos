#include <stdio.h>

int main(){
    int peso;
    int g1;
    int g2;
    int t;

    printf("Digite o peso do saco em KG: \n");
    scanf("%d", &peso);

    printf("Digite a quantidade do Primeiro gato: \n");
    scanf("%d", &g1);

    printf("Digite a quantidade do segundo gato: \n");
    scanf("%d", &g2);

    peso = peso * 1000;
    t = (g1 + g2) * 5;
    t = peso - t;

    printf("Resto da racao apos 5 dias: %d\n", t);

    return 0;
}
