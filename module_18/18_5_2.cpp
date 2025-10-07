#include <iostream>

using namespace std;

int сalc_num_options(int sum, int min, int max = 2){ 
    if(sum <= min) return 1;
    int count = 0;
    for(int i = min; sum >= i; i++){
        if(i > max){
            return count;
        }
        count += сalc_num_options(sum - i, min);
    }
    return count;
}

int main(){
    int finish = 5;
    int startPos = 0;
    int minJumpLen = 1;
    int maxJumpLen;
    int totalSteps = finish - startPos;
    cout << сalc_num_options(totalSteps, minJumpLen);
}