#include<stdio.h>

int main()
{
    int n=10,p[100][100];

    // printf("n = ");
    // scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        p[0][i]=1;
        p[i][i]=1;
    }
    for(int i=2;i<n;i++)
    {
        for(int j=1;j<i;j++)
        {
            p[j][i]=p[j-1][i-1]+p[j][i-1];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            printf("%d ",p[j][i]);
        }
        printf("\n");
    }

    return 1;

}
