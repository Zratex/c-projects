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
        if(j==1)
        {
            if(m==1)
            {
                j=31;
                m=12;
                a--;

            }
            else
            {
                m--;
                if(m==2)
                {
                    if((a%4==0 && !a%100==0) || a%400==0)
                    {
                        j=29;
                    }
                    else
                    {
                        j=28;
                    }
                }
                else if(m==4 || m==6 || m==9 || m==11)
                {
                    j=30;
                }
                else
                {
                    j=31;
                }
            }
        }
        else
        {
            j--;
        }
    }

    printf("%02d/%02d/%04d",j,m,a);

    return 1;
}
