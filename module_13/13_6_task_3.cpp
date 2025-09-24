#include <iostream>
#include <vector>

using namespace std;

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

void print_vec(vector<int> vec) {
    cout << "vec: " << endl;
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}

vector<int> add_to_vec(vector<int> vec, int capacity){
    int k = 0;
    cout << "Input how many numbers do you want to add to the vector: " << endl;
    do{
        cin >> k;
        if(k <= 0){
            cout << "Error. Input positive number > 0" << endl;
        }
    } while (input_validation_errors() || k <= 0);
    
    unsigned int realSize = 0;
    for(int i = 0, x = 0; i < k; i++){
        cout << "Input number ('-1' - to print vector): " << endl;
        do{
            cin >> x;
        } while (input_validation_errors());
        if(x == -1){
            print_vec(vec);
        } else{
            vec[realSize % capacity] = x;
            realSize++;
        }
        
    }
    return vec;
}

int main(){
    unsigned const int capacity = 20;
    vector<int> vec(capacity);
    vec = add_to_vec(vec, capacity);
}