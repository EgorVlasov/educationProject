#include <iostream>

using namespace std;

void swap(int* c, int* d){
    int e = *c;
    *c = *d;
    *d = e;
}

int main(){
    
    int a = 10;
    int b = 20;
    swap(&a, &b);
    cout << a << " " << b;
}