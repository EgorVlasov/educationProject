#include <iostream>
#include <vector>

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

void fill_out_arr(float a[][4]){
    cout << "fill the array: " << endl;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            do{
                cin >> a[i][j];
            } while (input_validation_errors());
        }
    }
}

void fill_out_vec(vector <float> &b){
    cout << "fill the vector: " << endl;
    for(int i = 0; i < b.size(); i++){
        do{
            cin >> b[i];
        } while (input_validation_errors());
    }
}

void multiplication(float a[][4], vector<float> &b, vector<float> &c){
    float temp = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            temp += a[i][j] * b[j];
        }
        c[i] = temp;
        temp = 0;
    }
}

void print_vec(vector<float> &c){
    for(int i = 0; i < c.size(); i++){
        cout << c[i] << " ";
    }
}

int main(){
    float a[4][4];
    vector<float> b(4);
    vector<float> c(4);
    fill_out_arr(a);
    fill_out_vec(b);
    multiplication(a, b, c);
    print_vec(c);
}

