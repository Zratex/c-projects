#include <stdio.h>

int main()
{
    printf("Exo 1 : PGCD\n");
    int n1,n2;
    printf("Entrez le premier nombre : ");
    scanf("%d",&n1);
    printf("Entrez le second nombre : ");
    scanf("%d",&n2);

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
    printf("Plus grand diviseur commun est : %d",result);
    return 0;
}
