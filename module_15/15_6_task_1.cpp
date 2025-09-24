#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main(){
    int rInd = 0;
    int lInd = 0;
    vector<int> v = {-2, 1, -3, 4, -1 ,2 ,1 ,-5 ,4};
    vector<int> n(v.size());
    int sum = 0;

    for(int i = 0; i < v.size(); i++){
        sum = accumulate(v.begin(), (v.end() - i), 0);
        n[i] = sum;
    }
    
    auto itRmax = max_element(n.begin(), n.end());
    rInd = v.size() - distance(n.begin(), itRmax) - 1;

    for(int i = 0; i < v.size(); i++){
        sum = accumulate((v.begin() + i), v.end(), 0);
        n[i] = sum;
    }

    auto itLmax = max_element(n.begin(), n.end());
    lInd = distance(n.begin(), itLmax);

    if(lInd >= rInd){
        n.clear();
        n.resize(v.size() - lInd);

        for(int i = 0; i < n.size(); i++){
            sum = accumulate((v.begin() + lInd), (v.end() - i), 0);
            n[i] = sum;
        }

        auto itRmax = max_element(n.begin(), n.end());
        rInd = v.size() - distance(n.begin(), itRmax) - 1;
    }

    std::cout << lInd << " - " << rInd;
}