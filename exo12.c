#include <stdlib.h>
#include <stdio.h>

void H(int n,int d,int a) {
    if (n==1) {
        printf("%d -> %d\n",d,a);
    } else {
        H(n-1,d,6-a-d);
        H(1,d,a);
        H(n-1,6-a-d,a);
    }
}

void display_towers(int size, int towers[3][size]) {
    for (int i=0; i<size;i++) {
        for (int j=0;j<3; j++) {
            int moitie = (size-towers[j][i])/2;
            for (int a=0;a<moitie;a++) {
                printf(" ");
            }
            for (int b=0;b<towers[j][i];b++) {
                if (towers[j][i]%2 == 0) {
                    printf("-");
                } else {
                    printf("=");
                }
            }
            if (towers[j][i]%2 == 0) {
                printf("-");
            }
            for (int a=0;a<moitie;a++) {
                printf(" ");
            }
            printf("|");
        }
        printf("\n");
    }
}

void hanoi_init(int size) {
    int towers[3][size];
    for (int i=0; i<3; i++) {
        for (int j=0; j<size; j++) {
            towers[i][j] = j;
        }
    }
    display_towers(size,towers);
}

int main() {
    printf("Exo 12 : Tours d'Hanoi\n");
    H(3,1,3);
    /*
    int entier;
    printf("Entrez la taille de la tour d'Hanoi : ");
    scanf("%d", &entier);
    hanoi_init(entier);
    */

    return 1;
}
