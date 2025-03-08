//Задание 2. Сортировка
#include <iostream>

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

void heapify(float arr[], int n, int root){
    int max = root;   
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < n && arr[left] > arr[max]){
        max = left;
    }
    if (right < n && arr[right] > arr[max]){
        max = right;
    }
    if (max != root){
        swap(arr[root], arr[max]);
        heapify(arr, n, max);
    }
}

void heap_sort(float arr[], int n){
    // взяли за корень середину массива, построили кучу, нашли максимум
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
    // убрали максимум в конец массива, уменьшили длинну массива на 1, отсортировали уменьшенную кучу, нашли новый максимум итд по всей длинне массива
    for (int i = n - 1; i >= 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void fill_fNumArr(float fNumArr[]){
    cout << "Enter the float numbers: \n";
    for(int i = 0; i < 15; i++){
        do{
            cin >> fNumArr[i];
        } while (input_validation_errors());
    }
}

void print_array(float arr[], int n) {
    cout << "sorted array: \n";
    for (int i = 0; i < n; i++){
        cout << arr[i] << ", ";
    }
    cout << "\n";
}

int main() {
    float fNumArr[15];
    int n = sizeof (fNumArr) / sizeof (fNumArr[0]);
    
    fill_fNumArr(fNumArr);
    heap_sort(fNumArr, n);
    print_array(fNumArr, n);
}