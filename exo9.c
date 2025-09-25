#include <stdlib.h>
#include <stdio.h>

int main() {
    printf("Exo 9 : Duplication caractères\n");
    char string[256];
    printf("Entrez une chaîne de caractères avec des chiffres : ");
    scanf("%s", &string);
    //Duplication des caractères :
    char* result[sizeof(string)/sizeof(char)];
    for (int i=0;i<sizeof(string)/sizeof(char);i++) {
        int number=atoi(&string[i]);
        if (number!=0) {
            char characters[number];
            for (int j=0;j<number;j++) {
                characters[j] = string[i+1];
            }
            result[i] = characters;
            i++;
        }
    }
    //Affichage :
    for (int i=0;i<sizeof(result)/sizeof(char*);i++) {
        for (int j=0;i<sizeof(result[i])/sizeof(char);j++) {
            printf("%c",result[i][j]);
        }
    }

    return 0;
}
