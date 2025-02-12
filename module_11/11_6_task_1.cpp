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

bool is_char_letter(int charCode){
    if(charCode >= 65 && charCode <= 122){
        return true;
    } else if(charCode >= 91 && charCode <= 96){
        return false;
    } else{
        return false;
    }
}

int find_out_letter_case(char charCode){
    if(charCode >= 65 && charCode <= 90){
        return 1; 
    } else if(charCode >= 97 && charCode <= 122){
        return 0; 
    } else{
        return -1;
    }
}

string encrypt_caesar(string encryptedWord, int code){
    string decodedWord = encryptedWord;
    for(int i = 0; i < encryptedWord.length(); i++){
        if(is_char_letter(encryptedWord[i])){
            int newCharPos;
            if(is_char_uppercase_letter(encryptedWord[i])){
                if(is_char_uppercase_letter((int)encryptedWord[i] + code)){
                    decodedWord[i] = (int)encryptedWord[i] + code;
                } else{
                    newCharPos = 64 + (code - (90 - (int)encryptedWord[i]));
                }
            } else{
                if(is_char_uppercase_letter((int)encryptedWord[i] + code)){
                    decodedWord[i] = (int)encryptedWord[i] + code;
                } else{
                    newCharPos = 96 + (code - (122 - (int)encryptedWord[i]));
                }
            }
            decodedWord[i] = newCharPos;
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