#include <stdio.h>

int main(){
    int s;
    float p;
    float t;

    printf("Digite o salario: \n");
    scanf("%d", &s);

    printf("Digite a %% do aumento: \n");
    scanf("%f", &p);
    
    p = (p/100) + 1;

    t = s * p;

    printf("O aumento foi de: %f\n", t);

    return 0;
}