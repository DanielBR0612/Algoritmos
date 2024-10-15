#include <stdio.h>

int multi(int a, int b){
    int r;
    r = a * b;
    return r;
}

int main(){
    int a, b;

    printf("Digite dois numeros: \n");
    scanf("%d %d", &a, &b);

    printf("%d\n", multi(a, b));

    return 0;
}