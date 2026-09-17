#include <stdio.h>

int main()
{
    printf("Exo 8 : Histogramme\n");
    //Initilialisation :
    int nEntiers = 0;
    printf("Nombre de nombres à entrer : ");
    scanf("%d",&nEntiers);
    int listeNombres[nEntiers];
    for (int i=0;i<nEntiers;i++) {
        printf("Entrez un nombre : ");
        scanf("%d",&listeNombres[i]);
    }
    //Affichage de la liste (c'est pas obligatoire mais c'est pour s'assurer qu'on est bon) :
    printf("Votre liste : [");
    for (int i=0;i<nEntiers;i++) {
        printf("%d, ",listeNombres[i]);
    }
    printf("]\n");
    //Affichage de l'histogramme :
    int findMax(int tab[],int len) { //On cherche d'abord
        int max = tab[0];
        for (int i=0;i<len;i++) {
            //printf("Current max : %d ; tab[i] : %d\n",max,tab[i]);
            if (tab[i] > max) {
                max = tab[i];
            }
        }
        return max;
    }
    int maxi=findMax(listeNombres,nEntiers);
    //printf("Le plus grand : %d\n",maxi);
    for (int i=maxi;i>0;i--){
        for (int j=0;j<nEntiers;j++) {
            if (listeNombres[j]>=i) {
                printf("=");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
