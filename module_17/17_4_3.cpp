#include <iostream>
#include <cstring>

using namespace std;

bool substr(const char* s1, char* s2){
    int s1StrLen = strlen(s1);
    int s2StrLen = strlen(s2);
    if(s1StrLen >= s2StrLen){
        for(int i = 0; i <= (s1StrLen - s2StrLen); i++){
            char subStrS1[s2StrLen];
            for(int j = 0; j < s2StrLen; j++){
                *(subStrS1 + j) = *(s1 + j + i);
            }
            if(*subStrS1 == *s2){
                return true;
            }
        }
    }else{
        return false;
    }
    return false;
}

int main(){

const char* a = "Hello world";
char b[] = "worworworworworworworworworworworworworwor";
char c [] = " worl";
cout << substr(a, b) << " " << substr(a, c) << endl;

}