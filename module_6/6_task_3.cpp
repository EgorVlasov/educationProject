#include <iostream>
#include <locale.h>
#include <string>

using namespace std;

int main (){
    setlocale(LC_ALL,".UTF8");

    string name;
    cout << "как вас зовут? ";
    getline(cin, name);

    int clientDebit = 0;
    int clientCredit;

    cout << "Какую сумму вы должны банку? ";
    cin >> clientCredit;

    int clientSaldo = clientDebit - clientCredit;

    if (clientCredit >= 0){
        while (clientSaldo < 0){
            cout << name << ", на вашем счете " << clientSaldo << " Заплатите долг банку!\n"
                << "внести сумму: ";
            cin >> clientDebit;
            clientSaldo += clientDebit;
        }
        cout << name << ", поздравляю, вы выплатили долг, на вашем балансе " << clientSaldo ;

    } else {
        cout << name << ", сумма кредита не может быть отрицательной";
    }
}