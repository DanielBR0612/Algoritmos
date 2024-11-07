#include <stdio.h>

int main(){
    int campo[5][5] = {
        {0, -1, -1, 0, 0},
        {-1, 0, 0, -1, 0},
        {0, 0, 0, -1, -1},
        {0, -1, 0, 0, -1},
        {-1, 0, -1, 0, 0}
    };

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (campo[i][j] == -1) {
                continue;
            }

            int qtd = 0;

            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    int ni = i + x;
                    int nj = j + y;


                    if (ni >= 0 && ni < 5 && nj >= 0 && nj < 5 && campo[ni][nj] == -1) {
                        qtd++;
                    }
                }
            }
    
            campo[i][j] = qtd;
        }
    }


    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (campo[i][j] == -1) {
                printf(" * ");
            } else {
                printf(" %d ", campo[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
