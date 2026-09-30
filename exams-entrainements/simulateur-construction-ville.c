#include <stdio.h>
#include <stdlib.h>

void initMap(int longueur, int largeur, int map[longueur][largeur]) {
    for (int i=0;i<longueur;i++) {
        for (int j=0;j<largeur;j++) {
            if ((rand()%100)<=20) {
                map[i][j]=-1;
            } else {
                map[i][j]=0;
            }
        }
    }
}

void printMap(int longueur, int largeur,int map[longueur][largeur]) {
    //Affichage séparation première ligne :
    for (int j=0;j<largeur;j++) {
        printf("==");
    }
    printf("\n");
    for (int i=0;i<longueur;i++) {
        for (int j=0;j<largeur;j++) {
            printf("|");
            if (map[i][j] == -1) {
                printf("X");
            } else if (map[i][j]==0) {
                printf(".");
            } else {
                printf("%d",map[i][j]);
            }
        }
        printf("|\n");
        //Changement de ligne :
        for (int j=0;j<largeur;j++) {
            printf("--");
        }
        printf("\n");
    }
}

int checkIfUpgradePossible(int longueur, int largeur,int map[longueur][largeur], int coordX, int coordY) {
    //Retourne 0 si upgrade impossible
    //Retourne 1 si upgrade possible de 1->2, ou 2->3
    //Retourne 2 si upgrade possible de 3->4
    int result = 0;
    if (coordX-1 < 0 || coordX+1 > longueur || coordY-1 < 0 || coordY+1 > largeur) { //Si on est sur un bord, pas possible d'upgrade
        return 0;
    }
    //Vérification de respectivement haut, gauche, bas, droite
    if (map[coordX-1][coordY]==0 && map[coordX][coordY-1]==0 && map[coordX+1][coordY]==0 && map[coordX][coordY+1]==0) {
        result=1; //La construction d'une tour de 2 ou 3 est possible
    }
    //Vérification de respectivement haut-gauche, haut-droite, bas-gauche, bas-droite
    if (result==1 && (map[coordX-1][coordY-1]==0 && map[coordX-1][coordY+1]==0 && map[coordX+1][coordY-1]==0 && map[coordX+1][coordY+1]==0)) {
        result = 2; //La construction d'une tour de 4 est possible
    }
    return result;
}

void maxLevels(int longueur, int largeur,int map[longueur][largeur]) {
    for (int i=0;i<longueur;i++) {
        for (int j=0;j<largeur;j++) {
            int conditionResult = checkIfUpgradePossible(longueur,largeur,map,i,j);
            if (conditionResult == 2) {
                map[i][j]=4;
            } else if (conditionResult == 1) {
                map[i][j]=3;
            }
        }
    }
}

void maxBuildsWithMaxLevels(int longueur, int largeur,int map[longueur][largeur]) {
    maxLevels(longueur,largeur,map); //On construction les constructions les plus hautes possible
    //On fini par ajouter une construction sur toutes les cases constructibles restantes :
    for (int i=0;i<longueur;i++) {
        for (int j=0;j<largeur;j++) {
            if (map[i][j] == 0) {
                map[i][j] = 1;
            }
        }
    }
}

int main() {
    printf("Sujet exam (blanc) : simulateur construction de villes\n");
    int longueur;
    printf("Longueur taille ville : ");
    scanf("%d", &longueur);
    int largeur;
    printf("Largeur taille ville : ");
    scanf("%d", &largeur);
    int map[longueur][largeur];
    initMap(longueur, largeur,map);
    //Constructions avec un maximum de niveaux et de constructions
    printMap(longueur,largeur,map);
    maxBuildsWithMaxLevels(longueur,largeur,map);
    printMap(longueur,largeur,map);
    //Constructions avec un maximum de niveaux :
    initMap(longueur, largeur,map);
    maxLevels(longueur,largeur,map);
    printMap(longueur,largeur,map);
    return 1;
}
