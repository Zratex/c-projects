#include<stdio.h>

int main()
{
    char mot[100];
    int i,taille;

    printf("Saisissez un mot : ");
    scanf("%s",mot);

    taille=strlen(mot);
    i=0;
    while(mot[i]==mot[taille-1-i] && i<=taille/2)
        i++;
    if(i<=taille/2)
        printf("Le mot n'est pas un palyndrome");
    else
        printf("Le mot est un palyndrome");

    return 1;
}
