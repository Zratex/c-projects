#include<stdio.h>

int main()
{
    int tab[10]={3,6,8,9,6,9,4,2,5,7},min=tab[0],max=tab[0];

    for(int i=1;i<10;i++)
    {
        if(tab[i]<min)
            min=tab[i];
        if(tab[i]>max)
            max=tab[i];
    }
    printf("Voici le min : %d et le max : %d",min,max);
}
