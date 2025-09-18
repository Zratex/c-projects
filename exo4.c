#include <stdio.h>

int main()
{
    printf("Exo 4 : Simplification fraction\n");
    int dividende,diviseur;
    printf("Entrez le dividende : ");
    scanf("%d", &dividende);
    printf("Entrez le diviseur : ");
    scanf("%d", &diviseur);
    printf("Simplification de %d/%d...\n",dividende,diviseur);
    if (dividende == diviseur)
    {
        printf("Fraction simplifiee : 1");
    } else if (dividende%diviseur == 0)
    {
        printf("Fraction simplifiee : %d", dividende/diviseur);
    } else {
        int plusPetit;
        int i = 1;
        while(i<plusPetit) {
            if (plusPetit!=dividende && plusPetit!=diviseur) {
                i=1;
                if (diviseur<dividende)
                {
                    plusPetit = diviseur;
                } else {
                    plusPetit = dividende;
                }
            }
            if (dividende%i == 0 && diviseur%i == 0) {
                dividende /= i;
                diviseur /= i;
            }
            i++;
        }
        printf("Fraction simplifiee : %d/%d", dividende,diviseur);
    }
}
