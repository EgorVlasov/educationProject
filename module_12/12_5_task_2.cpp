//Задание 2. Сортировка
#include <iostream>

using namespace std;

void heapify(float arr[], int arrSize, int root){
    int max = root;   
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < arrSize && arr[left] > arr[max]){
        max = left;
    }
    if (right < arrSize && arr[right] > arr[max]){
        max = right;
    }
    if (max != root){
        swap(arr[root], arr[max]);
        heapify(arr, arrSize, max);
    }
}

void heap_sort(float arr[], int arrSize){
    // взяли за корень середину массива, построили кучу, нашли максимум
    for (int i = arrSize / 2 - 1; i >= 0; i--){
        heapify(arr, arrSize, i);
    }
    // убрали максимум в конец массива, уменьшили длинну массива на 1, отсортировали уменьшенную кучу, нашли новый максимум итд по всей длинне массива
    for (int i = arrSize - 1; i >= 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


void fill_fNumArr(float fNumArr[]){
    cout << "Enter the float numbers: \n";
    for(int i = 0; i < 15; i++){
        cin >> fNumArr[i];
    }
}

void print_array(float arr[], int arrSize) {
    cout << "sorted array: \n";
    for (int i = 0; i < arrSize; i++){
        cout << arr[i] << ", ";
    }
    cout << "\n";
}

int main() {
    float fNumArr[15];
    int fNumArrSize = sizeof (fNumArr) / sizeof (fNumArr[0]);
    
    fill_fNumArr(fNumArr);
    heap_sort(fNumArr, fNumArrSize);
    print_array(fNumArr, fNumArrSize);
}