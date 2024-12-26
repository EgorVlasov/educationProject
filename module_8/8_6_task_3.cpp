// Игрушечная история
#include <iostream>
#include <locale.h>

using namespace std;

int main () {
    setlocale(LC_ALL,".UTF8");

    float workpieceWidth, workpieceHight, workpieceDeep;
    bool inputValidation;

    cout << "введите ВxШxГ (см) заготовки: ";
    do{
        inputValidation = true;
        cin >> workpieceWidth >> workpieceHight >> workpieceDeep;
        if (cin.fail() || cin.peek() != '\n'){
            cerr << "Ошибка ввода данных. введите значение еще раз\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if(workpieceWidth < 5 || workpieceHight < 5 || workpieceDeep < 5 ){
            cerr << "Ошибка ввода данных. ВxШxГ не может быть меньше 5 см. Введите значения еще раз.\n";
        } else{
            inputValidation = false;
        }
    } while(inputValidation);
    // объем заготовки делим на объем 1 кубика, получаем количество вмещаемых кубиков в заготовку
    int cubeCount = ((int)workpieceWidth * (int)workpieceHight * (int)workpieceDeep) / (125);
    int setCubeCount = cubeCount;
    for(int rest = setCubeCount % 3; rest > 0; rest = setCubeCount % 3){
        --setCubeCount;
    }
    if(cubeCount >= 8){
    cout << "из заготовки " << workpieceWidth << "x" << workpieceHight << "x" << workpieceDeep << "см \n"
                            << "можно изготовить " << cubeCount << " кубиков 5х5х5 см \n"
                            << "из них можно составить набор из " << setCubeCount << " кубиков \n";
    } else{
        cout << "к сожалению, из " << cubeCount << " кубиков не получится составить полноценный набор \n";
    }

    return 0;
}