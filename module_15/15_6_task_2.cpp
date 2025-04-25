#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> vec = {0, 2, 4, 5, 6, 9, 100, 13, 43, 678, 329, 11, 57};
    int num = 56;

    for(int i = 0; i < vec.size(); i++){
        if(vec[i] > num){
            vec.erase(vec.begin() + i);
        }
    }

    for(int i = 0; i <= num; i++){
        auto it = find(vec.begin(), vec.end(), i);
        auto it2 = find(vec.begin(), vec.end(), (num - i));

        if(*it + *it2 == num){
            cout << *it << " + " << *it2 << " = " << num; 
            break;
        }
    }

    

}