#include <iostream>

using namespace std;

int main(){
    int arr[7] =  {-100, -50, -5, 0, 1, 10, 15};
    int indPosNum;

    for(int i = 0; i < 7; i++){
        if(arr[i] >= 0){
            indPosNum = i;
            break;
        }
    }
    int indNegNum = indPosNum - 1;
    
    if(indNegNum >= 0){
        while(indPosNum < 7 && indNegNum >= 0){
            if(abs(arr[indNegNum]) >= arr[indPosNum]){
                cout << arr[indPosNum] << " ";
                indPosNum++;
            } else{
                cout << arr[indNegNum] << " ";
                indNegNum--;
            }
        }
        if(indPosNum > 5){
            for(;indNegNum >= 0; indNegNum--){
                cout << arr[indNegNum] << " ";
            }
        }
        if(indNegNum <= 0){
            for(;indPosNum < 7; indPosNum++){
                cout << arr[indPosNum] << " ";
            }
        }
    }else{
        for(int i = 0; i < 7; indPosNum++){
            cout << arr[i] << " ";
        }
    }
}