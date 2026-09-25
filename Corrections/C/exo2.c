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


void main()
{
    int a,b,p;

    printf("Donnez le num‚rateur : ");
    scanf("%d",&a);
    printf("Donnez le d‚nominateur : ");
    scanf("%d",&b);

    p=pgcd(a,b);

    if(p==1)
    {
        printf("La fraction ne peut pas être simplifi‚e");
    }
    else
    {
        printf("Voici la version simplifi‚e : %d/%d",a/p,b/p);
    }
}
