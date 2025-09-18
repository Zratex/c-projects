#include <stdio.h>

int isYearBissextile(int year) {
    if (year%400 == 0) {
        return 1;
    }
    if (year%100 == 0) {
        return 0;
    }
    if (year%4 == 0) {
        return 1;
    }
}

int main()
{
    printf("Exo 6 : Date lendemain\n");
    int day, month, year;
    printf("\nEntrez le jour (numériquement) : ");
    scanf("%d", &day);
    printf("\nEntrez le mois (numériquement) : ");
    scanf("%d", &month);
    printf("\nEntrez l'année (numériquement) : ");
    scanf("%d", &year);
    int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (isYearBissextile(year) == 1) {
        daysInMonth[1] = 29;
    }
    int nJours = 1;
    day = day+nJours;
    while (day > daysInMonth[month-1]) {
        day -= daysInMonth[month-1];
        month +=1;
        if (month == 13) {
            month=1;
            year+=1;
            if (isYearBissextile(year) == 1) {
                daysInMonth[1] = 29;
            }
        }
    }
    printf("\nLa nouvelle date est %d/%d/%d\n",day,month,year);
}
