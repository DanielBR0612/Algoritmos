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
            int qtd = 0;
            if(campo[i][j] == -1){
                campo[i][j] = -1;
            }
            else{
                    if(campo[i] != 0){
                        if(campo[i - 1][j] == -1){
                            qtd += 1;
                        }
                        if(campo [i] < 5){
                            if(campo[i + 1][j] == -1){
                                qtd += 1;
                            }
                        }
                        if(campo[j] != 0){
                            if(campo[i][j - 1] == -1){
                                qtd += 1;
                            }
                            if(campo[i - 1][j - 1] == -1){
                                qtd += 1;
                            }
                            if(campo[j] < 5){
                                if(campo[i][j + 1] == -1){
                                    qtd += 1;
                                }
                                if(campo[i + 1][j + 1] == -1){
                                    qtd += 1;
                                }
                                if(campo[i + 1][j + 1] == -1){
                        qtd += 1;
                    }
                            }
                        }
                    }
    
                    
                    
                

                
                
            
            campo[i][j] = qtd;
            }
            
        }
    }

     for (int i = 0; i < 5; i++){
        for (int x = 0; x < 5; x++){
            printf("%d, ", campo[i][x]);
        }
        printf("\n");
    }

    return 0;
}