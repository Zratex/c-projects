#include<stdio.h>

int main()
{
    int j,m,a,nbj,n;

    printf("Jour : ");
    scanf("%d",&j);
    printf("Mois : ");
    scanf("%d",&m);
    printf("Année : ");
    scanf("%d",&a);
    printf("n : ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        if(m==2)
        {
            if((a%4==0 && !a%100==0) || a%400==0)
            {
                nbj=29;
            }
            else
            {
                nbj=28;
            }
        }
        else if(m==4 || m==6 || m==9 || m==11)
        {
            nbj=30;
        }
        else
        {
            nbj=31;
        }
        if(j==nbj)
        {
            j=1;
            if(m==12)
            {
                m=1;
                a++;
            }
            else
            {
                m++;
            }
        }
        else
        {
            j++;
        }
    }

    printf("%02d/%02d/%04d",j,m,a);

    return 1;
}
