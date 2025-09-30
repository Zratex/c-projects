#include <stdlib.h>
#include <stdio.h>

int facto_iterative(int entier) {
    int result = 1;
    for (int i = 1; i<entier; i++) {
        result *= i+1;
    }
    return result;
}

int facto_recursive(int entier) {
    if (entier>1) {
        return entier*facto_recursive(entier-1);
    } else {
        return entier;
    }
}

int main() {
    printf("Exo 10 : Factorielle\n");
    int entier;
    printf("Entrez un nombre pour calculer sa factorielle : ");
    scanf("%d", &entier);
    printf("Factoriel de %d en itératif : %d",entier,facto_iterative(entier));
    printf("\nFactoriel de %d en récursif : %d",entier,facto_recursive(entier));
}
