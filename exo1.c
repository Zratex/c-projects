#include <stdio.h>

int main()
{
    printf("Exo 1 : PGCD\n");
    int n1,n2;
    printf("Entrez le premier entier : ");
    scanf("%d",&n1);
    printf("Entrez le second entier : ");
    scanf("%d",&n2);

    int min = n2;
    if (n1 < n2)
    {
        min = n1;
    }

    int result = 1;
    /* Version efficace :
    result = min;
    while (!(n1%result==0 && n2%result==0))
        result--;
    */
    for (int i = 1; i < min; i++)
    {
        if (n1%i == 0 && n2%i == 0)
        {
            if (i > result)
            {
                result = i;
            }
        }
    }
    printf("Le PGCD est %d", result);

    return 1;
}
