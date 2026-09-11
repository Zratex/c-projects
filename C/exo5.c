#include <stdio.h>
#include <string.h>

int PGCD(int n1, int n2) {
    int min = n2;
    if (n1 > n2) {
        min = n1;
    }
    int result = 1;
    for (int i=1; i<min;i++) {
        if (n1%i == 0 && n2%i == 0) {
            if (i>result) {
                result = i;
            }
        }
    }
    return result;
}

void getFacteurs(int n) {
    int result[n];
    for (int i=0; i<n; i++) {
        if (i!=0 && n%i==0 && PGCD(i,i)==1) {
            printf("%d\n",i);
        }
    }
}

int main()
{
    printf("Exo 5 : Facteurs premiers\n");
    printf("Choisissez un nombre : ");
    int n;
    scanf("%d",&n);
    getFacteurs(n);
    return 0;
}
