#include <iostream>
#include <fstream>
#include <string>

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
void calc_subStr_cnt_in_str(int &matchesCnt, const string &buffStr, const string &subStr){
    for(size_t searchPos = 0; buffStr.find(subStr, searchPos) != string::npos; searchPos += subStr.size()){
        matchesCnt++;
        searchPos = buffStr.find(subStr, searchPos);
    }
}

int main(){
    ifstream inputFile;
    inputFile.open("/Users/evlasov/Documents/educationProject/module_19/fileForSearch.txt");
    if(inputFile){
        string activeStrLine;
        string subStrToFind;
        int subStrCnt = 0;

        do{
            cout << "input subString to find: ";
            getline(cin, subStrToFind);
        }while(input_validation_errors());
        
        while(getline(inputFile, activeStrLine)){
            calc_subStr_cnt_in_str(subStrCnt, activeStrLine, subStrToFind);
        }

        inputFile.close();
        cout << "I found: "<<  subStrCnt << " matches" << endl;
    }else{
        cerr << "Error. Can't open the file" << endl;
    }
}