#include <stdio.h>

int main()
{
    printf("Exo 2 : Min et max\n");
    int tab[12] = {1,2,3,4,45,28,2,1,9,10,11,12};
    int minimum;
    int maximum;
    for (int i=0; i < sizeof(tab) / sizeof(int) ; i++ )
    {
        if (i == 0 || tab[i] > maximum)
        {
            maximum = tab[i];
        }
        if (i == 0 || tab[i] < minimum) {
            minimum = tab[i];
        }
    }
    printf("Le plus grand élément du tableau est %d, et le plus petit est %d", maximum, minimum);
    return 1;
}
