#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    float speed = 0;
    do{
        string inputStr;
        float speedDelta = 0;
        cout << "Input speed delta: ";
        getline(cin, inputStr);
        stringstream ssBuffer(inputStr);
        cout << endl;
        while(ssBuffer >> speedDelta){
            char buffer [3];
            cout << "speed delta: " << speedDelta << endl;
            if(speed + speedDelta > 150){
                cout << "speed limit!" << endl;
                speed = 150;
            } else{
                speed += speedDelta;
            }
            if(speed + speedDelta > 0){
                sprintf(buffer, "%.1f", speed);
                cout << "speed: " << buffer << endl; 
            } else{
                cout << "speed: 0" << endl 
                << "car stoped";
            }
        }
        ssBuffer.clear();
        ssBuffer.str("");
        cout << endl;
    } while(speed > 0);
}