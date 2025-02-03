//Подсчёт количества слов
#include <iostream>
#include <string>

using namespace std;

int main () {
    string secretNum;
    string inputNum;

    bool inputValidation;
    int errors;
    do{
        inputValidation = true;
        errors = 0;
        cout << "Input a four-digit secret number [0-9]:\n";
        cin >> secretNum;
        if (cin.fail() || cin.peek() != '\n'){
            cerr << "Input error. Try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if(secretNum.length() > 4){
            cerr << "Input error. It should be a four-digit secret number [0-9]. Try again\n";
        } else{
            for(int i = 0; i < secretNum.length(); ++i){
                if(secretNum[i] < '0' || secretNum[i] > '9'){
                    ++errors;
                }
            }
            if(errors == 0){
                inputValidation = false;
            } else{
                cerr << "Input error. It should be a four-digit secret number [0-9]. Try again\n";
            }
        }
    } while(inputValidation);

    int cows;
    int bulls;
    do{
        inputValidation = true;
        cows = 0;
        bulls = 0;
        errors = 0;
        cout << "Try to make a guess a four-digit secret number [0-9]:\n";
        cin >> inputNum;
        if (cin.fail() || cin.peek() != '\n'){
            cerr << "Input error. Try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if(inputNum.length() > 4){
            cerr << "Input error. It should be a four-digit secret number [0-9]. Try again\n";
        } else{
            for(int i = 0; i < inputNum.length(); ++i){
                if(inputNum[i] < '0' || inputNum[i] > '9'){
                    cerr << "Input error. It should be a four-digit secret number [0-9]. Try again\n";
                    ++errors;
                    break;
                } else{
                    if(inputNum[i] == secretNum[i]){
                        ++bulls;
                    } else {
                        for(int j = 0; j < secretNum.length(); ++j){
                            if(inputNum[i] == secretNum[j] && i != j){
                                ++cows;
                            }
                        } 
                    }
                }
            }
            if(!errors){
                cout << "cows: " << cows << "\n" 
                    << "bulls: " << bulls << "\n";
            }
            if(inputNum == secretNum){
                cout << "You guessed the number!\n";
                inputValidation = false;
            }
        }
    } while(inputValidation);

    return 0;
    
}