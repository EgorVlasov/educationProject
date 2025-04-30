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

int main(){
    int num;
    int a[5] = {0, 0, 0, 0, 0};
    int i = 0;

    while (true){
        do{
            cout << "Enter number:" << endl;
            cin >> num;
        }while (input_validation_errors());

        if(i < 5){
            a[i] = num;
        }
        if(i == 4){
            for(int z = 0; z < 5; z++){
                for(int t = 0; t < 5; t++){
                    if(a[t] > a[t + 1]){
                        swap(a[t], a[t + 1]);
                    }  
                }
            }
        }
        
        if(num != -1 && num != -2 && num < a[4] && i > 4){
            for(int j = 0; j < 5; j++){
                if(a[j] > num){
                    swap(a[j], num);
                }
            }
        }

        if(num == -1){
            if(i > 4){
                cout << "the smallest 5th number: " << a[4] << endl;
                for(int k = 0; k < 5; k++){
                    cout << a[k] << " ";
                }
                cout << endl;
            } else{
                cout << "no 5th number" << endl;
            }
        }
        if(num == -2){
            break;
        }
        i++;
    }
}
