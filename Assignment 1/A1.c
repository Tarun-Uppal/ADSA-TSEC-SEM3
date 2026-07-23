// Online C compiler to run C program online
#include <stdio.h>

void main() {
    int a[3][3];
    int b[3][3];
    printf("Array A");
    for (int i=0;i<3;i++){
        for (int j = 0; j<3;j++){
            scanf("%d", &a[i][j]);
        }
    }
    printf("Array B");
    for (int i=0;i<3;i++){
        for (int j = 0; j<3;j++){
            scanf("%d", &b[i][j]);
        }
    }
    
    for (int i=0;i<3;i++){
        for (int j = 0; j<3;j++){
            a[i][j] -= b[i][j];
        }
    }
    
    for (int i=0;i<3;i++){
        for (int j = 0; j<3;j++){
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
}