#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Exo 7 : Triangle pascal par tableau 1D\n");
    int n;
    printf("Entrez le nombre d'interration pour le triangle : ");
    scanf("%d",&n);
    int *table = malloc(sizeof(int));;
    for (int i=0; i<n;i++) {
        if (i>1) {
            int *nextTable = malloc(i * sizeof(int));
            nextTable[0] = 1;
            nextTable[i] = 1;
            for (int j=1;j<i;j++) {
                nextTable[j] = table[j-1] + table[j];
            }
            free(table);
            table = nextTable;
        } else {
            table[0] = 1;
            table[i] = 1;
        }
        for (int k=0;k<=i;k++) {
            printf("%d ",table[k]);
        }
        printf("\n");
    }

    /* Version abandonnée et pas encore fonctionnelle :
    int somme = 0;
    for (int i=1;i<=n;i++) {
        somme +=i;
    }
    int matrix[somme+1]; // +1 pour la fin de caractère
    // Calcul du triangle :
    for (int i = 0; i<n; i++) {
        matrix[i] = 1;
        matrix[i+i] = 1;
        if (i>1)
        {
            for (int j=1; j<i; j++) {
                matrix[i+j] = matrix[(i-1)+(j-1)] + matrix[(i-1)+j];
            }
        }
    }
    // Affichage du triangle :
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<=i; j++) {
            printf("%d ",matrix[i+j]);
        }
        printf("\n");
    }
    */
}
