//Задание 1. Шифр Цезаря
#include <iostream>
#include <string>

using namespace std;

bool input_validation_errors(){
    if (cin.fail() || cin.peek() != '\n'){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Input error. Try again\n";
        return true;
    } else{
        return false;
    }
}

bool is_code_correct(int code){
    if(!input_validation_errors() && code > 0 && code < 27){
        return true;
    } else{
        return false;
        cerr << "Input error. Try again\n";
    }
}

int find_out_letter_case(char charCode){
    if(charCode >= 65 && charCode <= 90){
        // uppercase
        return 1; 
    } else if(charCode >= 97 && charCode <= 122){
        // lowercase
        return 0; 
    } else{
        // not a letter
        return -1;
    }
}

string encrypt_caesar(string encryptedWord, int code){
    string decodedWord = encryptedWord;
    for(int i = 0, newCharPos = 0; i < encryptedWord.length(); i++){
        if(find_out_letter_case(encryptedWord[i]) == 1){
            if(find_out_letter_case((int)encryptedWord[i] + code) == 1){
                decodedWord[i] = (int)encryptedWord[i] + code;
            }  else{
                newCharPos = 64 + (code - (90 - (int)encryptedWord[i]));
                decodedWord[i] = newCharPos;
            }
        } else if(find_out_letter_case(encryptedWord[i]) == 0){
            if(find_out_letter_case((int)encryptedWord[i] + code) == 0){
                decodedWord[i] = (int)encryptedWord[i] + code;
            }  else{
                newCharPos = 64 + (code - (90 - (int)encryptedWord[i]));
                decodedWord[i] = newCharPos;
            }
        } else{
            decodedWord[i] = encryptedWord[i];
        }
    }
    return decodedWord;
}

int main () {
    string encryptedWord;
    cout << "Enter the encrypted word:\n";
    do{
        cin >> encryptedWord;
    } while(input_validation_errors());

    int code;
    cout << "Enter the code:\n";
    do{
        cin >> code;
    } while(!is_code_correct(code));

    cout << "Encrypted word: " << encryptedWord << "\n";
    cout << "Decoded word: " << encrypt_caesar(encryptedWord, code) << "\n";


}