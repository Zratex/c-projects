#include <stdlib.h>
#include <stdio.h>

void moveCircleFromATowerToAnother(int size, int towers[3][size], int d, int a) {
    // Pour des questions de lisibilité, d et a seront +1 en entrée :
    d--;
    a--;
    //Commencement de la fonction :
    int isMoved = 0;
    int i=0;
    //On regarde à quel case se trouve le prochain disque
    while (i<size && towers[d][i] == 0) {
        i++;
    }
    if (i < size) { //Car si i==size ça veut dire que la tour est vide
        if (towers[d][i] != 0) {
            int j = 0;
            //On regarde à quel case est ce qu'il y a un emplacement libre dans la tour cible
            while (j<size && towers[a][j] == 0) {
                j++;
            }
            // Déplacement du cercle
            towers[a][j-1] = towers[d][i];
            towers[d][i] = 0;
            isMoved = 1;
        }
    }
}

void display_towers(int size, int towers[3][size]) {
    for (int i=0; i<size;i++) {
        for (int j=0;j<3; j++) {
            int moitie = (size-towers[j][i])/2;
            for (int a=0;a<moitie;a++) {
            printf(" ");
            }
            if (towers[j][i] != 0) {
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
            } else {
                printf("+");
            }
            for (int a=0;a<moitie;a++) {
                printf(" ");
            }
            printf("|");
        }
        printf("\n");
    }
}

void hanoiSolver(int n,int d,int a,int size, int towers[3][size]) {
    if (n==1) {
        printf("Déplacement de %d vers %d :\n",d,a);
        moveCircleFromATowerToAnother(size,towers,d,a);
        display_towers(size,towers);
    } else {
        hanoiSolver(n-1,d,6-a-d, size, towers);
        hanoiSolver(1,d,a, size, towers);
        hanoiSolver(n-1,6-a-d,a, size, towers);
    }
}

void hanoi_init(int size) {
    int towers[3][size];
    for (int i=0; i<3; i++) {
        for (int j=0; j<size; j++) {
            if (i==0) {
                towers[i][j] = j+1;
            } else {
                towers[i][j] = 0;
            }
        }
    }
    display_towers(size,towers);
    hanoiSolver(size,1,3,size,towers);
}

int main() {
    printf("Exo 12 : Tours d'Hanoi\n");
    //H(3,1,3);
    int entier;
    printf("Entrez la taille de la tour d'Hanoi : ");
    scanf("%d", &entier);
    hanoi_init(entier);

    return 1;
}
