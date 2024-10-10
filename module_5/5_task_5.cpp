#include<iostream>
#include<string>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_ALL,".UTF8");

    cout << "=== Банкомат — 2 ===\n";
  
    int a;
    int b;
    int c;
    cout << "введите размеры AxBxC коробки 1 через пробел : ";
    cin >> a >> b >> c;

    int x;
    int y;
    int z;
    cout << "введите размеры XxYxZ коробки 2 через пробел : ";
    cin >> x >> y >> z;

    string message = "Errroor";

    if (a <= x && b <= y && c <= z || a <= y && b <= x && c <= z) message = "OK AxBxC";
    else if (a <= x && c <= y && b <= z || a <= y && c <= x && b <= z) message = "OK AxCxB";
    else if (b <= x && c <= y && a <= z || b <= y && c <= x && a <= z) message = "OK BxCxA";
    
    cout << message;
}
