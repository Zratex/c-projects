#include<stdio.h>

int pgcd(int aa,int bb)
{
    int c;

    if(aa<bb)
        c=aa;
    else
        c=bb;

    while(!(aa%c==0 && bb%c==0))
    {
        c--;
    }

    return c;
}

int main()
{
    int a,b;

    printf("Donnez un nombre entier : ");
    scanf("%d",&a);
    printf("Donnez un nombre entier : ");
    scanf("%d",&b);

    printf("Le PGCD de %d et %d vaut %d",a,b,pgcd(a,b));

    return 1;
}