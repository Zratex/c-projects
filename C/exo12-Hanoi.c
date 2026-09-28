#include <stdio.h>
#include <stdlib.h>

int** initTowers(int n) {
    //Initialise les tours de Hanoi
    int** towers = malloc(3 * sizeof(int*));
    for (int i=0;i<3;i++) {
        towers[i] = malloc(n * sizeof(int));
        for (int j=0;j<n;j++) {
            if (i==0) { //Dans l'initialisation on a besoin que la première tour soit remplie
                towers[i][j]=j;
            } else {
                towers[i][j]=0; //Signifie que c'est vide
            }
        }
    }
    return towers;
}

void printHanoi(int** towers, int n) {
    //Affiche la tour de Hanoi
    for (int j=0;j<n;j++) {
        for (int i=0;i<3;i++) {
            int length=towers[i][j];
            for (int x=0;x<(((n-1)-length)/2);x++) { //Vide à afficher AVANT le disque de la la tour :
                printf(" ");
            }
            if (length!=0) {
                if (length%2==0) { //On ajoute un charactère pour que ce soit centré
                    printf("-");
                }
                for (int x=0;x<length;x++) { //On affiche le cercle de la tour :
                    if (length%2==0) {
                        printf("-"); //Pair
                    } else {
                        printf("="); //Impair
                    }
                }
            } else {
                printf("|");
            }
            for (int x=0;x<(((n-1)-length)/2);x++) { //Vide à afficher APRES le disque de la tour :
                printf(" ");
            }
            //Changement de tour :
            printf(".");
        }
        printf("\n");
    }
}

int getTopCircleIndexFromSingularTower(int* tower,int n) {
    //Retourne le cercle le plus haut d'UNE tour (int* tower)
    for (int i=0;i<n;i++) {
        if (tower[i]!=0) { //On a trouvé le premier élément qui n'est pas vide
            return i;
        }
    }
    return n;
}

void moveCircles(int** towers,int indexA,int indexB, int n) {
    //Execute le déplacement d'un cercle vers un autre emplacement, à partir de son index
    int tempIndex = getTopCircleIndexFromSingularTower(towers[indexA],n);
    towers[indexB][getTopCircleIndexFromSingularTower(towers[indexB],n)-1]=towers[indexA][tempIndex];
    towers[indexA][tempIndex]=0;
}

void moveCirclesFromTowerToTower(int nbCircles, int originTowerIndex, int destinationTowerIndex, int** towers, int n) {
    //Déplace des cercles (nbCircles) d'une tour (originTowerIndex) vers une autre (destinationTowerIndex)
    if (nbCircles == 1) { //On est arrivé au bout de la factorielle, donc on déplace le cercle :
        moveCircles(towers,originTowerIndex,destinationTowerIndex,n);
        //Affichage de la tour à jour :
        for (int i=0;i<n*3;i++) {
            printf("-");
        }
        printf("\n");
        printHanoi(towers,n);
    } else {
        //Soustraction sur 3 car on peut obtenir des nombres négatifs, et qu'il n'y a pas de fonction abs() par défaut
        //On doit faire cette formule pour prendre en compte la transposition pour les cas où A=B et A=C
        moveCirclesFromTowerToTower(nbCircles-1,originTowerIndex,3-originTowerIndex-destinationTowerIndex,towers,n); //A->B
        moveCirclesFromTowerToTower(1,originTowerIndex,destinationTowerIndex,towers,n); //A->C
        moveCirclesFromTowerToTower(nbCircles-1,3-originTowerIndex-destinationTowerIndex,destinationTowerIndex,towers,n); //B->C
    }
}

int main() {
    printf("Exo 12 : Tours de Hanoi\n");
    int n;
    printf("Entrez un nombre pour définir la taille de la tour de Hanoi : ");
    scanf("%d", &n);
    if (n%2==1) { //Euh c'est trop relou les nombres impairs pour l'affichage, flemme hein
        n++;
    }
    int** towers = initTowers(n);
    printHanoi(towers,n);
    moveCirclesFromTowerToTower(n-1,0,2,towers,n);
}
