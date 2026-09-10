#include <stdlib.h>
#include <stdio.h>

int fibonacci(int entier) {
    if (entier <=2) {
        return 1;
    } else {
        return fibonacci(entier-1) + fibonacci(entier-2);
    }
}

void display_fibo(int entier) {
    for (int i = 1; i<entier; i++) {
        printf("%d ",fibonacci(i));
    }
}

int main() {
    printf("Exo 11 : Fibonacci\n");
    int entier;
    printf("Entrez un nombre pour calculer la suite de fibonacci : ");
    scanf("%d", &entier);
    display_fibo(entier);
    return 1;
}
