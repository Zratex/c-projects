#include <stdio.h>
#include <string.h>

int isPalindrome(char* mot) {
    int longueurMot = strlen(mot);
    if (longueurMot%2!=0) {
        int i=0;
        int result=1; //Tant que la condition est vraie
        while (i<(longueurMot-1)/2 && result==1) {
            if (mot[i]!=mot[longueurMot-i-1]) {
                result=0;
            }
            i++;
        }
        return result;
    } else { //Si c'est pair ça ne peut pas être un palindrome
        return 0;
    }
}

int main()
{
    printf("Exo 4 : Palindromes\n");
    char mot[255];
    printf("Entrez un mot : ");
    scanf("%s",mot);

    int ResultPalindrome = isPalindrome(mot);
    if (ResultPalindrome==1) {
        printf("C'est un palindrome");
    } else {
        printf("Ce n'est PAS un palindrome");
    }
    return 1;
}
