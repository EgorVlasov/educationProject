#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main () {
    string inputStr;
    cout << "enter a string to calculate ";
    getline(cin, inputStr);
    stringstream ssBuffer(inputStr);
    double a, b, result;
    char action;

    if(ssBuffer >> a && ssBuffer >> action && ssBuffer >> b){
        if(action == '+'){
            result = a + b;
        }
        else if(action == '-'){
            result = a - b;
        }
        else if(action == '*'){
            result = a * b;
        }
         else if(action == '/'){
            if (b == 0) {
                cout << "Error: division by zero";
                return 1;
            } else{
                result = a / b;
            }
        } else{
            cout << "incorrect action. Use '+' '-' '*' '/' symbols";
            return 1;
        }
        cout << a << " " << action << " " << b << " = " << result;
    } else {
        cout << "incorrect input format. Use: number number operator";
        return 1;
    }

}