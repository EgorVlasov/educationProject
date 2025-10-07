#include <iostream>
#include <vector>

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

void сalc_even_num_cnt(int &evenNumCnt, long long number){
    if (((number % 10) % 2) == 0) evenNumCnt++ ;
    if((number / 10) > 0) сalc_even_num_cnt(evenNumCnt, number / 10);
}

int main(){
    long long bigNumber;
    int ans = 0;

    do{
        cin >> bigNumber;
    }while (input_validation_errors());
    сalc_even_num_cnt(ans, bigNumber);

    cout << ans;

}