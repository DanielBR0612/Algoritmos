#include <stdio.h>
#include <math.h>

float distancia(float x1, float x2, float y1, float y2){
    float t = ((x2 - x1) * (x2 - x1) + ((y2 - y1) * (y2 - y1)));
    float d = sqrt(t);

    return d;
}

int main(){
    float x1, x2, y1, y2;

    printf("Digit x1, x2, y1, y2:\n");
    scanf("%f %f %f %f", &x1, &x2, &y1, &y2);

    printf("A distancia é: %f", distancia(x1,x2,y1,y2));

    return 0;
}