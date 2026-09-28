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
            for (int x=0;x<((n-length)/2);x++) { //Vide à afficher AVANT le disque de la la tour :
                printf(" ");
            }
            if (length!=0) {
                if (length%2==0) { //On ajoute un charactère pour que ce soit centré
                    printf("-");
                }
                for (int x=0;x<length;x++) { //On affiche le cercle de la tour :
                    if (length%2==0) {
                        printf("-");
                    } else {
                        printf("=");
                    }
                }
            } else {
                printf("|");
            }
            for (int x=0;x<((n-length)/2);x++) { //Vide à afficher APRES le disque de la tour :
                printf(" ");
            }
            //Changement de tour :
            printf(".");
        }
        printf("\n");
    }
}

int getIndexFromChar(char t) {
    if (t=='a') {
        return 0;
    } else if (t=='b') {
        return 1;
    } else if (t=='c') {
        return 2;
    }
}

void updateTowersToMove(char t[2]) {
    if (t[0]=='a' && t[1]=='b') {
        t[0]='b';
        t[1]='c';
    } else if (t[0]=='b' && t[1]=='c') {
        t[0]='c';
        t[1]='a';
    } else if (t[0]=='c' && t[1]=='a') {
        t[0]='a';
        t[1]='b';
    }
}

int ifHanoiResolved(int** towers, int n) {
    for (int i=0;i<n;i++) {
        if (towers[2][i]!=i) { //ça veut dire que la tour n'est pas complète
            return 0;
        }
    }
    return 1;
}

int getTopCircleIndexFromSingularTower(int* tower,int n) {
    for (int i=0;i<n;i++) {
        if (tower[i]!=0) { //On a trouvé le premier élément qui n'est pas vide
            return i;
        }
    }
    return n;
}

void moveCircles(int** towers,int indexA,int indexB, int n) {
    int tempIndex = getTopCircleIndexFromSingularTower(towers[indexA],n);
    towers[indexB][getTopCircleIndexFromSingularTower(towers[indexB],n)-1]=towers[indexA][tempIndex];
    towers[indexA][tempIndex]=0;
}

void round(int**towers,char towersToMove[2], int n) {
    moveCircles(towers,getIndexFromChar(towersToMove[0]),getIndexFromChar(towersToMove[1]),n);
    printHanoi(towers,n);
    updateTowersToMove(towersToMove);
    updateTowersToMove(towersToMove);
    moveCircles(towers,getIndexFromChar(towersToMove[0]),getIndexFromChar(towersToMove[1]),n);
    printHanoi(towers,n);
    updateTowersToMove(towersToMove);
    moveCircles(towers,getIndexFromChar(towersToMove[0]),getIndexFromChar(towersToMove[1]),n);
    printHanoi(towers,n);
}

void resolutionHanoi(int** towers, int n) {
    char towersToMove[2]={'c','a'}; //J'ai appris après coup que je peux juste faire un "enum towersToMove{A,B,C};" plutôt que ça et les fonctions que j'ai codé avec
    int compteur = 0;
    while (ifHanoiResolved(towers,n)==0 && compteur < 5) { //La condition n'est pas bonne
        updateTowersToMove(towersToMove);
        round(towers,towersToMove,n);

        compteur++;
    }
}

int main() {
    printf("Exo 12 : Tours de Hanoi\n");
    int n;
    printf("Entrez un nombre pour définir la taille de la tour de Hanoi : ");
    scanf("%d", &n);
    int** towers = initTowers(n);
    printHanoi(towers,n);
    resolutionHanoi(towers,n);
}
