#include<stdio.h>

int main(void)
{
    int n,i=2,premier=1;

    printf("Donnez un nombre entier positif >1 : ");
    scanf("%d",&n);

    printf("D‚composition en facteurs premiers : ");
    while(n!=1)
    {
        if(n%i==0)
        {
            if(premier)
            {
                premier=0;
            }
            else
            {
                printf("x ");
            }
            printf("%d ",i);
            n/=i;
        }
        else
            i++;
    }

    return 1;
}
