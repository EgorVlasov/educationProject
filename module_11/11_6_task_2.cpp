//Задание 2. Проверка корректности email-адреса
// корректный email-адрес должен состоять из двух частей, разделённых знаком @
// Первая часть должна иметь длину не менее одного и не более 64 символов
// вторая часть — не менее одного и не более 63 символов
// Из символов допускаются только английские буквы, цифры и знак «-» (дефис), а также точка. 
// Точка не может быть первым или последним символом, две точки не могут идти подряд. 
// В первой части (перед символом @), кроме вышеперечисленных, разрешены ещё следующие символы: !#$%&'*+-/=?^_`{|}~


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
bool is_char_allowed_symbol_for_lpart(char emailChar){
    string allowedSymbols = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!#$%&'*+-/=?^_`{|}~.";
    if(allowedSymbols.find(emailChar) == string::npos){
        return false;
    } else{
        return true;
    }
}
bool is_char_allowed_symbol_for_rpart(char emailChar){
    string allowedSymbols = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-.";
    if(allowedSymbols.find(emailChar) == string::npos){
        return false;
    } else{
        return true;
    }
}
bool is_email_lpart_correct(string email){
    if(email.find('@') > 0 && email.find('@') < 66){
        for(int i = 0; i < email.find('@'); i++){
            if(is_char_allowed_symbol_for_lpart(email[i])){
                if(email[i] == 46){
                    if(i == 0 || (i == email.find('@') - 1)){
                        return false;
                    } else{
                        if(email[i - 1] == 46 || email[i + 1] == 46){
                            return false;
                        }
                    }
                }
            } else{
                return false;
            }
        }
        return true;
    } else{
        return false;
    }
}
bool is_email_rpart_correct(string email){
    int rpartLenth = (email.length() - 1) - email.find('@');
    if(rpartLenth > 0 && rpartLenth < 64){
        for(int i = email.find('@') + 1; i < email.length(); i++){
            if(is_char_allowed_symbol_for_rpart(email[i])){
                if(email[i] == 46){
                    if((i == email.find('@') + 1) || (i == email.length() - 1)){
                        return false;
                    } else{
                        if(email[i - 1] == 46 || email[i + 1] == 46){
                            return false;
                        }
                    }
                }
            } else{
                return false;
            }
        }
        return true;
    } else{
        return false;
    }
}
bool email_input_correctness(string email){
    if(!input_validation_errors()){
        if(email.find('@') == email.rfind('@')){
            if(is_email_lpart_correct(email)){
                if(is_email_rpart_correct(email)){
                    return true;
                } else{
                    cerr << "Input error. Try again\n";
                    return false;  
                }
            } else{
                cerr << "Input error. Try again\n";
                return false;           
            }
        } else{
            cerr << "Input error. Try again\n";
            return false;        
        }
    } else{
        cerr << "Input error. Try again\n";
        return false;    
    }
}

int main () {
    string email;
    email.resize (128);
    cout << "Enter your email [__@__.__]: ";
    do{
        cin >> email;
    } while(!email_input_correctness(email));
    cout << "done";
}