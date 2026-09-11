#include <stdio.h>
#include <string.h>

int isBesextile(int year) //Retourne 1 si bisextile
{
    if (year%100==0 && year%400!=0) {
        return 0;
    }
    if (year%4==0) {
        return 1;
    }
    return 0;
}

void nextDays(int day, int month, int year, int nJours, int result[3])
{
    //Initialisation des variables courantes directement dans le tableau de résultats
    result[0] = day;
    result[1] = month-1;
    result[2] = year;
    if (nJours != 0) {
        int everyDaysPerMonths[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if (isBesextile(year) == 1) {
            everyDaysPerMonths[1] = 29;
        }
        int nbDaysToAdd = nJours;
        while (nbDaysToAdd>0) {
            if (nbDaysToAdd<everyDaysPerMonths[result[1]]) {
                result[0]=result[0]+nbDaysToAdd; //On actualise le jour courant
                nbDaysToAdd=0;
            } else {
                nbDaysToAdd=(nbDaysToAdd+result[0]-1)-everyDaysPerMonths[result[1]]; //On actualise le nombre de jours à ajouter
                result[0]=1; //On reset le jour courant. Le -1 de la ligne précédente est représenté par ce reset à 1 au lieu de 0
                if (result[1]==11) { //Si on est en fin décembre :
                    result[1]=0; //On repasse en janvier
                    result[2]=result[2]+1; //On passe à l'année suivante
                } else { //Si on est à un autre mois de l'année que décembre :
                    result[1]=result[1]+1; //On passe au mois suivant
                }
            }
            //printf("%d jours restants. Date du jour : %d/%d/%d\n",nbDaysToAdd,result[0],result[1]+1,result[2]);
        }
    }
    result[1] += 1; //On repasse à un numéro de mois lisible par un humain
    return;
}

//Fonction de test, ne pas trop y faire attention
void testIfTodayYearIsBisextile(int year) {
    if (isBesextile(year)==1) {
        printf("Cette année est BISEXTILE !\n");
    }
}

int main()
{
    printf("Exo 6 : Date du lendemain ?\n");
    int day, month, year;
    printf("\nEntrez le JOUR d'aujourd'hui (numériquement) : ");
    scanf("%d", &day);
    printf("\nEntrez le MOIS d'aujourd'hui (numériquement, en excluant 0 exclus) : ");
    scanf("%d", &month);
    printf("\nEntrez l'ANNEE d'aujourd'hui (numériquement) : ");
    scanf("%d", &year);
    int nJours = 0;
    printf("\nEntrez le NOMBRE DE JOURS APRES la date que vous avez indiqué (numériquement, négatif supportés) : ");
    scanf("%d", &nJours);
    printf("Date d'aujourd'hui : %d/%d/%d\n",day,month,year);
    //testIfTodayYearIsBisextile(year);
    int nextDaysResult[3];
    nextDays(day,month,year,nJours,nextDaysResult);
    printf("Date dans %d jour(s) : %d/%d/%d\n",nJours,nextDaysResult[0],nextDaysResult[1],nextDaysResult[2]);
    return 0;
}
