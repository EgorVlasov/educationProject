#include <iostream>

using namespace std;

void print_arr(int arr[][5]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void initialization(int arr[][5]){
    int number = 1;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            int multiplier = (i % 2) ? 1 : -1;
            arr[i][(4 * (i % 2)) - (j * multiplier)] = number; 
            number++;
        }
    }
}

int main(){
    int arr[5][5];
    initialization(arr);
    print_arr(arr);
}