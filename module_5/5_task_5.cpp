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
  
    if (a <= x && b <= y || a <= y && b <= x) message = "OK ab";
    else if (b <= x && c <= y || b <= y && c <= x) message = "OK bc";
    else if (a <= x && c <= y || a <= y && c <= x) message = "OK ac";
    
    cout << message;
}
