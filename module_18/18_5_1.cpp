#include <iostream>
#include <vector>

using namespace std;

void swapVec(vector<int> &c, int (&d)[9]){
    for(int i = 0; i < 9; i++){
        int temp = c[i];
        c[i] = d[i];
        d[i] = temp;
    }
}
void printVec(const vector<int> &c){
    for(int i : c){
        cout << i << " ";
    }
}
void printArr(const int (&d)[9]){
    for(int i : d){
        cout << i << " ";
    }
}


int main(){
    vector<int> a = {1,2,3,4,5,6,7,8,9};
    int b[] = {12,42,63,88,12,32,23,34,74};
    swapVec(a, b);
    printVec(a);
    cout << endl;
    printArr(b);
}