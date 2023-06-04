#include <stdio.h>

int main() {
    int I, J, length = 0;
    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &J);
    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &I);
    
    if (I >= 2 && J >= 2) {
        int tab[J][I];
        
        for (int i = 0; i < J; i++) {
            for (int j = 0; j < I; j++) {
                printf("Enter the element (%d, %d) of the matrix: ", i, j);
                scanf("%d", &tab[i][j]);
            }
        }
        
        if (tab[0][0] == 0 && tab[J - 1][I - 1] == 0) {
            length++;
            
            for (int k = 0; k < J; k++) {
                for (int n = 0; n < I; n++) {
                    if (tab[k][n] == 0) {
                        if ((n + 1 < I && tab[k][n + 1] == 0) ||
                            (k + 1 < J && tab[k + 1][n] == 0) ||
                            (k + 1 < J && n - 1 >= 0 && tab[k + 1][n - 1] == 0) ||
                            (k + 1 < J && n + 1 < I && tab[k + 1][n + 1] == 0)) {
                            length++;
                            
                            if ((tab[k][n + 1] == 0 && tab[k + 1][n] == 0) ||
                                (tab[k + 1][n] == 0 && tab[k + 1][n + 1] == 0) ||
                                (tab[k + 1][n - 1] == 0 && tab[k + 1][n + 1] == 0) ||
                                (tab[k][n + 1] == 0 && tab[k + 1][n + 1] == 0)) {
                                length--;
                            }
                        }
                    }
                }
            }
        }else{ length=-1;}
        
        printf("Length of the shortest clear path: %d\n", length);
    } else {
        printf("Invalid size of the matrix\n");
    }


}
