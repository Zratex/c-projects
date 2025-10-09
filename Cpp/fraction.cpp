#include<iostream>
#include<string>
#include<math.h>
using namespace std;

class Fraction
{
    public:
        float dividende;
        float diviseur;
        Fraction(const float d,const float D) {
            dividende=d;
            diviseur=D;
        }
        Fraction(const int d,const int D) {
            dividende=d;
            diviseur=D;
        }
        string display() {
            return std::to_string(dividende)+"/"+std::to_string(diviseur);
        }
        void simplification() {
            int pgcdValue = pgcd();
            dividende=dividende/pgcdValue;
            diviseur=diviseur/pgcdValue;
        }
        float result() {
            return dividende/diviseur;
        }
        Fraction operator+(Fraction &f) {
            simplification();
            f.simplification();
            return Fraction(dividende+f.dividende,diviseur+f.diviseur);
        }
    private:
        float pgcd() {
            int mini = dividende;
            if (diviseur < dividende)
            {
                mini = diviseur;
            }
            float currentPGCD = mini;
            if (round(dividende) != dividende || round(diviseur) != diviseur) { //Soit si ils ne sont pas des nombres exacts, on ne peut pas calculer le PGCD :
                return currentPGCD;
            }
            for (int i = 1; i < mini; i++)
            {
                if ((int)diviseur%i == 0 && (int)dividende%i == 0)
                {
                    if (i > currentPGCD)
                    {
                        currentPGCD = i;
                    }
                }
            }
            return currentPGCD;
        }
};

int main() {
    printf("Exo 1 : Fractions\n");
    Fraction f1(4.0f,2.0f);
    cout << f1.display() << endl;
    f1.simplification();
    cout << "Après simplification : " << f1.display() << " = " << f1.result() << endl;
    Fraction f2(6.0f,2.0f);
    Fraction fResult = f1+f2;
    cout << f1.display() << " + " << f2.display() << " = " << fResult.display() << endl;
}
