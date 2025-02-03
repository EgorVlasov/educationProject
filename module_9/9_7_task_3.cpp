//Подсчёт количества слов
#include <iostream>
#include <string>

using namespace std;

int main () {
    string text;

    cout << "Enter the text:\n";
    getline(cin, text);
    bool inputValidation;
    do{
        if (cin.fail() || cin.peek() != '\n'){
            cerr << "Input error. Try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else{
            inputValidation = false;
        }
    } while(inputValidation);

    int wordCnt = 0;
    for(int i = 0; i < text.length(); ++i){
        if(i + 1 < text.length()){
            if((text[i] == 32 && text[i + 1] != 32) || (i == 0 && text[0] != 32)){
                ++wordCnt;
            }
        } else if(text.length() < 2 && text[0] != 32){
            ++wordCnt;
        }
    }
    cout << "word count: " << wordCnt << "\n";
    
    return 0;
}