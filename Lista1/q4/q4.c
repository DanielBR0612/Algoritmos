#include <stdio.h>

int media(int a, int b, int c, int d){
    int med = (a + b + c + d)/4;
    return med;
}

int main(){
    int a, b, c, d;

    printf("Digite 4 numeros:\n");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    printf("%d\n", media(a,b,c,d));

    return 0;
}