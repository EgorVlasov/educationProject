#include <iostream>
#include <string>

using namespace std;

int main () {
    string word;
    bool inputValidation;

    cout << "Enter text:\n";

     do{
        inputValidation = true;            
        cin >> word;
        if (cin.fail() || cin.peek() != '\n'){
            cerr << "Input error. Try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else{
            inputValidation = false;
        }
    } while(inputValidation);
    
    bool wordLengthIsPrimeNum = true;
    if (word.length() == 1) { wordLengthIsPrimeNum = false; }
    for (int i = 2; i <= word.length() / 2; ++i) {
        if (word.length() % i == 0) { wordLengthIsPrimeNum = false; break; }
    }

    bool match = false;
    string matchChars = "";
    matchChars = word[0];
    while(match != true){ 
        int matchCharsPos = 0;
        for(int wordCharPos = 0; matchChars.length() + wordCharPos + 1 <= word.length(); wordCharPos++){
            match = true;
            if(matchCharsPos + 1 > matchChars.length()){
                matchCharsPos = 0;
            } 
            if(matchChars[matchCharsPos] != word[wordCharPos + matchChars.length()]){
                match = false;
                break;
            }
            ++matchCharsPos;
        }
        if((matchChars.length() > word.length() / 2) || (match && word.length() % matchChars.length() !=0
                || matchChars.length() > 1 && wordLengthIsPrimeNum)){
            match = false;
            break;
        }
        if(!match){
            matchChars += word[matchChars.length()];
        }
    }
    if(match){
        cout << "YES, repeated chars: " << matchChars << "\n";
    } else{
        cout << "NO \n";
    }
    return 0;
}