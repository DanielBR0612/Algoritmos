#include <stdio.h>
//deu certo
int mod(int a, int b){
    if (a < b){
        return a;
    }
    else{
        return mod(a - b, b);
    }
}

int div(int a, int b){
    if (a < b){
        return 0;
    }
    else{
        div 1 + (a - b, b);
    }
}

int main(){
    int m = mod(10,4);
    int d = div(10,1,0);

    printf("%d", d);

    return 0;
}
