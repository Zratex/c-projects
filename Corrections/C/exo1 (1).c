#include<stdio.h>

int main()
{
    int a,b,i;

    printf("Donnez un nombre entier : ");
    scanf("%d",&a);
    printf("Donnez un nombre entier : ");
    scanf("%d",&b);

    if(a>b)
        i=b;
    else
        i=a;

    while(!(a%i==0 && b%i==0))
        i--;

    printf("Le PGCD de %d et %d est %d",a,b,i);

    return 1;
}