#include <stdio.h>

int main()
{
    printf("Exo 7 : Triangle pascal par matrice\n");
    int n;
    printf("Entrez le nombre d'interration pour le triangle : ");
    scanf("%d",&n);
    int matrix[n][n];
    // Calcul du triangle :
    for (int i=0;i<n;i++) {
        for (int j=0;j<i+1;j++) {
            if (j==0 || j==i) {
                matrix[i][j]=1;
            } else {
                matrix[i][j]=matrix[i-1][j-1]+matrix[i-1][j];
            }
        }
    }
    // Affichage du triangle :
    for (int i=0;i<n;i++) {
        for (int j=0;j<i+1;j++) {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}
