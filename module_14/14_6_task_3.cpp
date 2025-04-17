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

void print_arr(int a[][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int fill_out_arr(int arr[4][4]){
    cout << "fill the array: " << endl;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            do{
                cin >> arr[i][j];
            } while (input_validation_errors());
        }
    }
    return arr[4][4];
}

bool equality_check(int a[][4], int b[][4]){
    bool equality = 1; 
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(a[i][j] != b[i][j]){
                cout << "a != b" << endl;
                return equality = 0; 
            }
        }
    }
    return equality;
}

void сonv_to_diag_matrix(int a[][4], int b[][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            a[i][j] =0;
        }
        a[i][i] = b[i][i];
    }
}

int main(){
    int a[4][4];
    int b[4][4];
    a[4][4] = fill_out_arr(a);
    b[4][4] = fill_out_arr(b);
    if(equality_check(a, b)){
        сonv_to_diag_matrix(a, b);
        print_arr(a);
    }
}