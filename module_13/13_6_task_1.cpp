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

vector<int> add_to_vec(vector<int> vec){
    int k = 0;
    cout << "Input how many numbers do you want to add to the vector: " << endl;
    do{
        cin >> k;
        if(k <= 0){
            cout << "Error. Input positive number > 0" << endl;
        }
    } while (input_validation_errors() || k <= 0);
    
    for(int i = 0, x = 0; i < k; i++){
        cout << "Input number: " << endl;
        do{
            cin >> x;
        } while (input_validation_errors());
        vec.push_back(x);
    }
    return vec;
}

vector<int> delete_from_vec(vector<int> vec){
    int value;
    auto valueIter = vec.end();
    cout << "Input number to delete: " << endl;
    do{
        cin >> value;
        valueIter  = find(vec.begin(), vec.end(), value);
        if(valueIter == vec.end()){
            cout << "Value not found" << endl;
        }
    } while (input_validation_errors() || valueIter == vec.end());
    do{
        vec.erase(valueIter);
        valueIter = find(vec.begin(), vec.end(), value);
   } while(valueIter != vec.end());
    
    return vec;
}

void print_vec(vector<int> vec) {
    cout << "vec: " << endl;
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> vec(0);
    vec = add_to_vec(vec);
    if(vec.size() > 0){
        vec = delete_from_vec(vec);
    } else{
        cout << "vector is empty" << endl;
        return 0;
    }
    print_vec(vec);
}