// Ход конём
#include <iostream>
#include <locale.h>
#include <cmath>

using namespace std;

int main () {
    setlocale(LC_ALL,".UTF8");

    float xFigurePosition, yFigurePosition, xSquarePosition, ySquarePosition;

    cout << "введите координаты местоположения коня: ";
    cin >> xFigurePosition >> yFigurePosition;

    cout << "введите координаты местоположения клетки: ";
    cin >> xSquarePosition >> ySquarePosition;

    if(xFigurePosition <= 0.8f || yFigurePosition <= 0.8f || xSquarePosition <= 0.8f || ySquarePosition <= 0.8f){
        xFigurePosition *= 10;
        yFigurePosition *= 10;
        xSquarePosition *= 10;
        ySquarePosition *= 10;

        cout << "Фигура находится в клетке (" << (int)xFigurePosition << ", " << (int)yFigurePosition << ")\n"
            << "Точка в клетке (" << (int)xSquarePosition << ", " << (int)ySquarePosition << ")\n";

        
        float r = sqrt(pow((xSquarePosition - xFigurePosition), 2) + pow((ySquarePosition - yFigurePosition), 2));
        float angleCos = (xSquarePosition - xFigurePosition) / r;
        float angleSin = (ySquarePosition - yFigurePosition) / r;
        if (angleCos != 0 && angleCos != -1 && angleCos != 1){
            float checkXsquarePosition = xFigurePosition + r * angleCos;
            float checkYsquarePosition = yFigurePosition + r * angleSin;

            if((int)checkXsquarePosition == (int)xSquarePosition && (int)checkYsquarePosition == (int)ySquarePosition){
                cout << "Да, конь может ходить в эту точку.\n";
            } else{
                cout << "Нет, конь не может ходить в эту точку.\n";
            }
        }else{
            cout << "Нет, конь не может ходить в эту точку.\n";
        }
    } else{
        cout << "ошибка. Координаты вне зоны поля.";
    }

}