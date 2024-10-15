#include <stdio.h>

int main(){
    float s;
    float v;
    float c;
    float t;

    printf("Salario fixo do funcionario: R$ ");
    scanf("%f", &s);

    printf("Valor das vendas: R$ ");
    scanf("%f", &v);

    c = v * 0.04;

    t = s + c;

    printf("Valor da comissao: R$ %f\n", c);
    printf("Valor do salario final: R$ %f\n", t);

    return 0;
}