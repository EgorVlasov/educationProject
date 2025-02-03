//Подсчёт количества слов
#include <iostream>
#include <string>

using namespace std;

int main () {
    string secretNum;
    string inputNum;

    bool inputValidation;
    cout << "Input a four-digit secret number [0-9]:\n";
    do{
        cin >> secretNum;
        if (cin.fail() || cin.peek() != '\n'){
            cerr << "Input error. It should be a four-digit secret number [0-9]. Try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if(secretNum[0] < '0' || secretNum[1] > '9' || secretNum.length() > 4){
            cerr << "Input error.  Try again\n";
        } else{
            inputValidation = false;
        }
    } while(inputValidation);

    return 0;
    
}