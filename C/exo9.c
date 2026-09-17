#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    printf("Exo 9 : Duplication caractères\n");
    char string[256];
    printf("Entrez une chaîne de caractères avec des chiffres : ");
    scanf("%s", &string);

    for (int i = 0; i < strlen(string); i++) {
        if (string[i] >= '0' && string[i] <= '9') { //Comparaison sur des caractères chiffres, sinon on skip
            int number = string[i] - '0'; //Cette soustraction mets en entier la valeur du caractère en se basant sur la valeur du caractère 0 en tant que référentiel
            char c = string[i+1]; //Normalement le caractère suivant est une lettre
            for (int j = 0; j < number; j++) { //On peut déjà afficher en plusieurs fois les lettres
                printf("%c", c); //On fait pas de \n car on veut un enchainement dans cette boucle
            }
            i++; // sauter le caractère déjà traité
        }
    }

    return 0;
}
