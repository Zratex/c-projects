#include <stdio.h>
#include <string.h>

int main()
{
    printf("Exo 3 : Palindrome\n");
    char mot[256];
    printf("Entrez un mot palindrome : ");
    scanf("%s", mot);
    int result = 1;
    int i = 0;
    while (i < (strlen(mot))/2 && result != 0) {
        if (mot[i] != mot[strlen(mot)-1-i]) {
            result = 0;
        }
        i++;
    }
    if (result == 0) {
        printf("Ce mot n'est pas palindrome");
    } else {
        printf("Ce mot EST palindrome !");
    }

    return 1;
}
