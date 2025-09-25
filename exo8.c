#include <stdio.h>

int main() {
    printf("Exo 8 : Histogramme\n");
    int n[8];
    int maxi=0;
    //Initilialisation :
    for (int i=0; i<8; i++) {
        int temp;
        printf("Entrez un nombre : ");
        scanf("%d",&temp);
        if (temp>maxi) {
            maxi=temp;
        }
        n[i]=temp;
    }
    printf("\nVoici à quoi ressemble la liste : [");
    //Affichage de la liste :
    for (int i=0; i<8;i++) {
        printf("%d,",n[i]);
    }
    printf("]\n");
    //Affichage de l'histogramme :
    for (int i=maxi;i>0;i--) {
        for (int j=0;j<8;j++) {
            if (n[j] >= i ) {
                printf("Û");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
