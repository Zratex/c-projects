#include <stdio.h>

int main()
{
    printf("Exo 3 : Min et Max");
    int findMin(int tab[]) {
        int min = tab[0];
        for (int i=0;i<sizeof(tab);i++) {
            if (tab[i] < min) {
                min = tab[i];
            }
        }
        return min;
    }
    int findMax(int tab[]) {
        int max = tab[0];
        for (int i=0;i<sizeof(tab);i++) {
            if (tab[i] > max) {
                max = tab[i];
            }
        }
        return max;
    }
    int tab[10];
    for (int i; i<9;i++) { //Euh flemme de supporter comment est ce que je sais si une case est vide ou non
        tab[i]=i*i;
    }
    printf("Le plus petit du tableau : %d\nLe plus grand du tableau : %d",findMin(tab),findMax(tab));
    return 0;
}
