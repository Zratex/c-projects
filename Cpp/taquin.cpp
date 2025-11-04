#include<iostream>
#include<string>
using namespace std;

class Taquin
{
    private:
        int cells[4][4];
        int voidCellCoord[2] = {0,0};
    public:
        Taquin() {
            int compteur = 0;
            for (int i=0; i<4; i++) {
                for (int j=0;j<4; j++) {
                    this->setCell(i,j,compteur);
                    compteur+=1;
                }
            }
            this->shuffle(1000);
        }
        Taquin(Taquin& t) {
            this->setVoidCellCoord(t.getVoidCellCoord()[0],t.getVoidCellCoord()[1]);
            for (int i=0; i<4;i++) {
                for (int j=0; j<4;j++) {
                    this->setCell(i,j,t.getCell(i,j));
                }
            }
        }
        int* getVoidCellCoord() {
            return this->voidCellCoord;
        }
        void setVoidCellCoord(int x, int y) {
            this->voidCellCoord[0] = x;
            this->voidCellCoord[1] = y;
        }
        void setCell(int x,int y,int value) {
            this->cells[x][y] = value;
        }
        int getCell(int x, int y) {
            return this->cells[x][y];
        }
        void moveCell(int initX, int initY, int destinationX, int destinationY) {
            if (this->isMovePossible(initX, initY, destinationX, destinationY)) {
                int temp = this->getCell(destinationX,destinationY);
                this->setCell(destinationX, destinationY, this->getCell(initX,initY));
                this->setCell(initX,initY,temp);
            }
        }
        bool isMovePossible(int initX, int initY, int destinationX, int destinationY) {
            if (destinationX == destinationY && destinationX == 3) {
                return false;
            }
            if (this->getCell(initX,initY) == 0) {
                return (initX-1 == destinationX && initY == destinationY) || (initX+1 == destinationX && initY == destinationY) || (initY-1 == destinationY && initX == destinationX) || (initY+1 == destinationY && initX == destinationX);
            } else {
                return false;
            }
        }

        void display() {
            for (int i=0; i<4;i++) {
                printf("=============\n");
                for (int j=0; j<4; j++) {
                    printf("|");
                    if (this->getCell(i,j) != 0) {
                        printf("%d",this->getCell(i,j));
                    } else {
                        printf(" ");
                    }
                    if (this->getCell(i,j) < 10) {
                        printf(" ");
                    }
                }
                printf("|\n");
            }
            printf("=============\n");
        }

        void shuffle(int repetitions) {
            while (repetitions > 0) {
                int nextPosition[2] = {rand()%4,rand()%4};
                if (isMovePossible(this->getVoidCellCoord()[0],this->getVoidCellCoord()[1],nextPosition[0],nextPosition[1])) {
                    this->moveCell(this->getVoidCellCoord()[0],this->getVoidCellCoord()[1],nextPosition[0],nextPosition[1]);
                    this->setVoidCellCoord(nextPosition[0],nextPosition[1]);
                }
                repetitions -= 1;
            }
        }

        int amountCorrectCells() {
            int compteur = 0;
            int result = 0;
            for (int i=0;i<4;i++) {
                for (int j=0;j<4;j++) {
                    if (this->getCell(i,j) == compteur) {
                        result += 1;
                    }
                    compteur +=1;
                }
            }
            return result;
        }
};

int main() {
    printf("Exo 2 : Taquin\n");
    Taquin t;
    t.display();
    Taquin t1 = t;
    t1.display();
    cout << "Nombre de cellules correctes : " << t1.amountCorrectCells() << endl;

    return 0;
}
