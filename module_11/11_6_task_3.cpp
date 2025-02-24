//Задание 3. Валидация IP-адреса
#include <iostream>
#include <string>
#include <cmath>

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

bool is_points_place_correct_in_string(string str){
     if(str[0]== '.' || str[str.length() - 1] == '.'){
        return false;
     }
    int pointsCnt = 0;
    for(int i = 1; i < (str.length() - 1); i++){
        if(str[i] == '.'){
            pointsCnt++;
            if(str[i - 1] == '.'){
                return false; 
            }
        }
    }
    if(pointsCnt == 3){
        return true;
    } else{
        return false;
    }
}

string cut_string_by_point(string str, int searchPos){
    string cuttedStrPart;
    if(str.find('.', searchPos) != string::npos){
        for(int i = searchPos; i < str.find('.', searchPos); i++){
            cuttedStrPart += str[i];
        }
        return cuttedStrPart;
    } else{
        for(int i = searchPos; i < str.length(); i++){
            cuttedStrPart += str[i];
        }
        return cuttedStrPart;
    }
}

int convert_string_to_int(string str){
    int convertedStrToInt = 0;
    for(int i = 0; i < str.length(); i++){
        convertedStrToInt += (str[i] - 48) * pow(10, (str.length()-1 - i));
    }
    return convertedStrToInt;
}

bool is_string_contain_allowed_symbols(string IPv4){
    string allowedSymbols = "0123456789.";
    for(int i = 0; i < IPv4.length(); i++){
        if(allowedSymbols.find(IPv4[i]) == string::npos){
            return false;
        }
    }
    return true;
}

bool IPv4_input_correctness(string IPv4){
    if(!input_validation_errors()){
        if(IPv4.length() < 7 || IPv4.length() > 15 || !is_string_contain_allowed_symbols(IPv4) || !is_points_place_correct_in_string(IPv4)){
            cerr << "Input error. Try again\n";
            return false;
        } else{
            for(int searchPos = 0; searchPos < IPv4.length();){
                string cuttedIPv4Part = cut_string_by_point(IPv4, searchPos);
                int convertedToIntIPv4Part = convert_string_to_int(cuttedIPv4Part);
                searchPos += cuttedIPv4Part.length() + 1;
                if(convertedToIntIPv4Part == 0 && cuttedIPv4Part.length() > 1 || convertedToIntIPv4Part > 255){
                    cerr << "Input error. Try again\n";
                    return false;
                }
            }
            return true;
        }
    } else{
        cerr << "Input error. Try again\n";
        return false;       
    }
}

int main() {
    string IPv4;
    IPv4.resize (15);
    cout << "Enter IPv4: ";
    do{
        cin >> IPv4;
    } while(!IPv4_input_correctness(IPv4));
    cout << "done";
}