#include <iostream>
#include <fstream>

using namespace std;

bool input_validation_errors(){
    if (cin.fail() || cin.peek() != '\n'){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Input error. Try again" << endl;
        return true;
    } else{
        return false;
    }
}

int main(){
    ifstream inputFile;
    string filePath;
    do{
        cout << "input file path:  ";
        cin >> filePath;
    }while(input_validation_errors());
    inputFile.open(filePath, ios::binary);
    if(inputFile){
        char buffer[100];
        size_t bufferRealSize = 0;
        do{
            inputFile.read(buffer, sizeof(buffer));
            bufferRealSize = inputFile.gcount();
            cout.write(buffer, bufferRealSize); 
        }while (bufferRealSize > 0);
        return 1;
    } else{
        cerr << "Error. Can't open the file" << endl;
        return 0;
    }
}