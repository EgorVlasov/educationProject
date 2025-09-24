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

void print_2d_arr(bool slice[][5]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << slice[i][j] << " ";
        }
        cout << endl;
    }
}

void print_3d_arr(unsigned int world[][5][3]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 3; k++){
                cout << world[i][j][k] << " ";
            }
            cout << " | ";
        }
        cout << endl;
    }
}

void word_initialization(unsigned int world[][5][3]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << i << "." << j << ") Enter width, length, hieght of the block: " << endl;
            for(int k = 0; k < 3; k++){
                do{
                    cin >> world[i][j][k];
                    if(world[i][j][k] > 10){
                        cerr << "Error. Value out of scope" << endl;
                    }
                }while(input_validation_errors() || world[i][j][k] > 10);    
            }
        }
    }
    print_3d_arr(world);
}

void get_slice_axis(unsigned int &sliceAxis){
    cout << "Enter the slice axis(0 - x, 1 - y, 2 - z): " << endl;
    do{
        cin >> sliceAxis;
        if(sliceAxis > 2){
            cerr << "Error. Avalible slice axis: 0 - x(length), 1 - y(width), 2 - z(height)" << endl;
        }
    }while(input_validation_errors() || sliceAxis > 2);
}

void get_slice_level(unsigned int &sliceLevel){
    cout << "Enter the slice level: " << endl;
    do{
        cin >> sliceLevel;
        if(sliceLevel > 10){
            cerr << "Error. Max level = 10" << endl;
        }
    }while(input_validation_errors() || sliceLevel > 10);
}

void slice(unsigned int world[][5][3]){
    unsigned int sliceAxis;
    get_slice_axis(sliceAxis);

    unsigned int sliceLevel;
    get_slice_level(sliceLevel);
    
    bool slice[5][5];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(world[i][j][sliceAxis] >= sliceLevel){
                if(world[i][j][sliceAxis] != 0){
                    slice[i][j] = true;
                } else{
                    slice[i][j] = false;
                }
            } else{
                slice[i][j] = false;
            }
        }
    }
    cout << "slice axis: " << sliceAxis << endl
         << "slice level: " << sliceLevel << endl;
    print_2d_arr(slice);

}

int main(){
    unsigned int world[5][5][3];
    word_initialization(world);
    bool continuing = 1;
    while(continuing){
        slice(world);
        cout << "continuing? (1 - yes / 0 - no) " << endl;
        do{
            cin >> continuing;
        }while(input_validation_errors());
    }
}