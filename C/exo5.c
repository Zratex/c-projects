#include <stdio.h>

int isPrime(int x) {
    if (x <= 3 && x > 1)
    {
        return 1;
    } else if (x % 2 == 0 || x % 3 == 0)
    {
        return 0;
    } else
    {
        for (int i=5; i*i<x; i+=6)
        {
            if (x % i == 0 || x%(i + 2) == 0)
            {
                return 0;
            }
        }
        return 1;
    }
}

int main()
{
    printf("Exo 5 : Calcul décomposition nombres premiers\n");
    int number;
    printf("Entrez un nombre : ");
    scanf("%d", &number);
    for (int i=1; i<number; i++) {
        if (isPrime(i) && number%i == 0)
        {
            printf("%d est un facteur premier\n", i);
        }
    }
}
