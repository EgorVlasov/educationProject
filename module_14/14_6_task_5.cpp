#include <iostream>

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

void initialization(bool shell[][12]){
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            shell[i][j] = true;
        }
    }
}
void print_arr(bool shell[][12]){
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            if(shell[i][j]){
                cout << "o ";
            }else{
                cout << "x ";
            }
        }
        cout << endl;
    }
}

void coordinates_request(int coordinates[][2]){
    cout << "input coordinates: ";
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            do{
                cin >> coordinates[i][j];
                if(coordinates[i][j] > 11 || coordinates[i][j] < 0){
                    cerr << "Error. coordinates out of scope! Try again.";
                }
            }while (input_validation_errors() || coordinates[i][j] > 11 || coordinates[i][j] < 0);
        }
    }
}

void burst(bool shell[][12], int &capacity){
    int coordinates[2][2];
    coordinates_request(coordinates);
    for(int i = coordinates[0][0]; i <= coordinates[1][0]; i++){
        for(int j = coordinates[0][1]; j <= coordinates[1][1]; j++){
            if(shell[i][j]){
                shell[i][j] = false;
                cout << "pop!" << endl;
                capacity--;
            }
        }
    }
}

int main(){
    bool shell[12][12];
    int capacity = 144;
    initialization(shell);
    print_arr(shell);
    while (capacity > 0)
    {
        burst(shell, capacity);
        print_arr(shell);
    }

}