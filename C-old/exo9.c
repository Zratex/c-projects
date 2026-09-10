#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    printf("Exo 9 : Duplication caractères\n");
    char string[256];
    printf("Entrez une chaîne de caractères avec des chiffres : ");
    scanf("%s", &string);

    for (int i = 0; i < strlen(string); i++) {
        if (string[i] >= '0' && string[i] <= '9') {
            int number = string[i] - '0';
            char c = string[i+1];
            for (int j = 0; j < number; j++) {
                printf("%c", c);
            }
            i++; // sauter le caractère déjà traité
        }
    }

    return 0;
}
