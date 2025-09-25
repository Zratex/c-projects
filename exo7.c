#include <stdio.h>

int main()
{
    printf("Exo 7 : Triangle pascal par matrice\n");
    int n;
    printf("Entrez le nombre d'interation pour le triangle : ");
    scanf("%d",&n);
    int matrix[n][n];
    for (int i = 0; i<n; i++) {
        matrix[i][0] = 1;
        matrix[i][i] = 1;
        if (i>1)
        {
            for (int j=1; j<i; j++) {
                matrix[i][j] = matrix[i-1][j-1] + matrix[i-1][j];
            }
        }
    }
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<=i; j++) {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}
