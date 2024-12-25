// Убийца Steam
#include <iostream>
#include <locale.h>

using namespace std;

int main () {
    setlocale(LC_ALL,".UTF8");

    float fileSize, downloadSpeed;
    bool inputValidation;

    cout << "введите размер файла для скачиваня (мб): ";
    do{
        inputValidation = true;
        cin >> fileSize;
        if (cin.fail() || cin.peek() != '\n'){
            cerr << "Ошибка ввода данных. введите значение еще раз\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if(fileSize < 0){
            cerr << "Ошибка ввода данных. Размер файла не может быть меньше 0. Введите значение еще раз.\n";
        } else{
            inputValidation = false;
        }
    } while(inputValidation);

    
    cout << "Введите скорость вашего интернет соединения (мб/сек): ";
    do{
        inputValidation = true;
        cin >> downloadSpeed;
        if (cin.fail() || cin.peek() != '\n'){
            cerr << "Ошибка ввода данных. введите значение еще раз\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if(downloadSpeed <= 0){
            cerr << "Ошибка ввода данных. Скорость загрузки не может быть меньше, либо ровна 0. Введите значения еще раз.\n";
        } else{
            inputValidation = false;
        }
    } while(inputValidation);

    for(float downloadSize = 0, int timerSec = 1, float downloadPercentage; downloadSize >= fileSize; ++timerSec;){
        this_thread::sleep_for(chrono::seconds(1));
        downloadSize += downloadSpeed;
        downloadPercentage = downloadSize / fileSize * 100;
        cout << "прошло " << timerSec << ", загружено " << downloadSize << " из " << fileSize << " мб (" << downloadPercentage << ")\n";
    }





    return 0;
}