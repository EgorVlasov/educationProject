//Задание 4. Ряд чисел* (дополнительное задание)
#include <iostream>

using namespace std;


int find_duplicate(int numbers[], int n){
    int max = numbers[0];
    int min = numbers[0];
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(numbers[i] < min){
            min = numbers[i];
        }
        if(numbers[i] > max){
            max = numbers[i];
        }
        sum += numbers[i];
    }

    int sum2 = 0;
    for(int i = min; i <= max; i++){
        sum2 += i;
    }
    int duplicate = sum - sum2;

    return duplicate;
}

int main() {
    int numbers[15] = {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    cout << "duplicate: " << find_duplicate(numbers, n);
}