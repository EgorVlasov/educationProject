#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<float> prices {2.5, 4.25, 3.0, 10.0};
    vector<int> items {1, 1, 0, 3, 4};
    float sum = 0;

    for(int i = 0; i < items.size(); i++){
        if(items[i] < prices.size()){
            sum += prices[items[i]];
        } else{
            cout << "Price for " << items[i] << " index not found" << endl;
        }
    }

    cout << "sum: " << sum << endl;
}