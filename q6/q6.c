#include <stdio.h>

float media(float n1, float n2){
    float m = ((n1 * 6) + (n2 * 4)) / 10;

    return m;
}

int main(){
    float n1, n2;

    printf("Digite 2 notas:\n");
    scanf("%f %f", &n1, &n2);

    printf("Sua media é: %f", media(n1,n2));

    return 0;
}