#include <iostream>

using namespace std;

void reverse(int* pa, int lenght){
    for(int i = 0; i < lenght / 2; i++){
        int temp = *(pa + i);
        *(pa + i) = *(pa + lenght - 1 - i);
        *(pa + lenght - 1 - i) = temp;
    }
}

int main(){  
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int c = sizeof(a) / sizeof(a[0]);

    for(int i = 0; i < (c); i++){
        cout << a[i] << endl;
    }
    reverse(a, c);

    cout << endl;

    for(int i = 0; i < c; i++){
        cout << a[i] << endl;
    }
    
    return 1;
}