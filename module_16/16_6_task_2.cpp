#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1;
    string s2;
    string sBuffer;
    double fNum;

    cout << "enter first num part: " << endl;
    cin >> s1;
    cout << "enter second num part: " << endl;
    cin >> s2;
    sBuffer = s1 + "." + s2;
    fNum = stod(sBuffer);
    cout << fNum;
}