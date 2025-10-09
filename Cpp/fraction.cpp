#include<iostream>
#include<string>
#include<math.h>
using namespace std;

class Fraction
{
    public:
        Fraction(const float d,const float D) {
            this->dividende=d;
            this->diviseur=D;
        }
        Fraction(const int d,const int D) {
            this->dividende=d;
            this->diviseur=D;
        }
        float getDividende() {
            return this->dividende;
        }
        void setDividende(const float d) {
            this->dividende=d;
        }
        float getDiviseur() {
            return this->diviseur;
        }
        void setDiviseur(const float d) {
            this->diviseur=d;
        }
        string display() {
            return std::to_string(dividende)+"/"+std::to_string(diviseur);
        }
        void simplification() {
            int pgcdValue = pgcd(this->getDividende(),this->getDiviseur());
            this->setDividende(this->getDividende()/pgcdValue);
            this->setDiviseur(this->getDiviseur()/pgcdValue);
        }
        float result() {
            return this->getDividende()/this->diviseur;
        }
        Fraction operator+(Fraction &f) {
            simplification();
            f.simplification();
            return Fraction(this->getDividende()+f.getDividende(),this->getDiviseur()+f.getDiviseur());
        }
        Fraction operator-(Fraction &f) {
            this->simplification();
            f.simplification();
            float pgcdValue = pgcd(this->getDividende(),f.getDiviseur());
            this->setDiviseur(pgcdValue);
            f.setDiviseur(pgcdValue);
            this->simplification();
            f.simplification();
            return Fraction(this->getDividende()-f.getDividende(),this->getDiviseur());
        }
    private:
        float dividende;
        float diviseur;
        float pgcd(float n1, float n2) {
            int mini = n1;
            if (n2 < n1)
            {
                mini = n2;
            }
            float currentPGCD = mini;
            if (round(n1) != n1 || round(n2) != n2) { //Soit si ils ne sont pas des nombres exacts, on ne peut pas calculer le PGCD :
                return currentPGCD;
            }
            for (int i = 1; i < mini; i++)
            {
                if ((int)n2%i == 0 && (int)n1%i == 0)
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
    fResult = f1-f2;
    cout << f1.display() << " - " << f2.display() << " = " << fResult.display() << endl;
}
