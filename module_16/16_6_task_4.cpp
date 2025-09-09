#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    enum note {
        DO = 1 << 0, // 00000001
        RE = 1 << 1, // 00000010
        MI = 1 << 2, // 00000100
        FA = 1 << 3, // 00001000
        SOL = 1 << 4,// 00010000
        LA = 1 << 5, // 00100000
        SI = 1 << 6  // 01000000
    };               

    int accord;
    cout << "Enter accord:" << endl;
    cin >> accord;

    // разбираем аккорд по нотам и записываем как отдельные ноты в массив
    vector<int> accordNotes;
    while (accord > 0) {
        int accordNote = accord % 10;
        if(accordNote > 7){
           cout << "incorrect note number:" << accordNote << endl;
        } else{
            accordNotes.push_back(accordNote);
        }
        accord /= 10;
    }
    if(accordNotes.size() > 0){
        reverse(accordNotes.begin(), accordNotes.end());
        // создаем битовую маску всего аккорда
        int accordBitMask = 0;
        for(int n : accordNotes){
            accordBitMask |= (1 << (n - 1));
        }

        if (accordBitMask & DO){
            cout << "DO ";
        }
        if (accordBitMask & RE){
            cout << "RE ";
        }
        if (accordBitMask & MI){
            cout << "MI ";
        }
        if (accordBitMask & FA){
            cout << "FA ";
        }
        if (accordBitMask & SOL){
            cout << "SOL ";
        }
        if (accordBitMask & LA){
            cout << "LA ";
        }
        if (accordBitMask & SI){
            cout << "SI";
        }
    } else{
        cout << "No notes in accord" << endl;
    }

}