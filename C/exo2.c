#include <stdio.h>

int main()
{
    printf("Exo 2 : Simplification Fraction\n");
    int denom,div;
    printf("Entrez le denominateur : ");
    scanf("%d",&denom);
    printf("Entrez le diviseur : ");
    scanf("%d",&div);

    int PGCD(int n1, int n2) {
        int min = n2;
        if (n1 > n2) {
            min = n1;
        }
        int result = 1;
        for (int i=1; i<min;i++) {
            if (n1%i == 0 && n2%i == 0) {
                if (i>result) {
                    result = i;
                }
            }
        }
        return result;
    }
    int comm=PGCD(denom,div);
    printf("%d/%d = %d/%d",denom,div,denom/comm,div/comm);
    return 1;
}
