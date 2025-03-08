
//Задание 3. Использование assert
#include <iostream>
#include <assert.h>

using namespace std;

float travelTime(float distance, float speed){
    assert(speed > 0);
    
    float time = distance / speed;
    return time;
}

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

int main() {
    float speed;
    float distance;

    cout << "input speed value (km/h): ";
    do{
        cin >> speed;
    }while(input_validation_errors());

    cout << "input distance value (km): ";
    do{
        cin >> distance;
    }while(input_validation_errors());

    cout << "time (h) = " << travelTime(distance, speed);
}