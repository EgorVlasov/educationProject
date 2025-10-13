#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const unsigned char pngHeader[8] = {137, 80, 78, 71, 13, 10, 26, 10};
const string path= "/Users/evlasov/Documents/educationProject/module_19/";

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
string get_file_extention(string &fileName){
    size_t subStrStartPos = fileName.find('.');
    if(subStrStartPos != string::npos){
        return fileName.substr(subStrStartPos, string::npos);
    }else{
        cerr << "file name has no extention" << endl;
        return "0";
    }
}
bool check_png_ext(string &fileName){
    string fileExt = get_file_extention(fileName);
    if(fileExt == ".png" || fileExt == ".PNG"){
        return true;
    } else{
        cerr << "Error. File is not .png" << endl;
        return false;
    }
}

int main(){
    string fileName;
    do{
        cout << "input file name:  ";
        cin >> fileName;
    }while(input_validation_errors() || !check_png_ext(fileName));

    ifstream inputFile;
    inputFile.open(path + fileName, ios::binary);
    if(inputFile){
        char buffer[8];
        inputFile.read(buffer, 8);
        if (memcmp(buffer, pngHeader, 8) == 0) {
            cout << "This is correct .png file!";
            return 1;
        } else{
            cout << "This is an incorrect .png file! The extension is correct, but the file doesn't contain a valid PNG header.";
            return 0;           
        }
    } else{
        cerr << "Error. Can't open the file" << endl;
        return 0;
    }
}