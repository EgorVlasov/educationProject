// Биолаборатория* (дополнительное задание)
#include <iostream>
#include <locale.h>

using namespace std;

int main (){
    setlocale(LC_ALL,".UTF8");

    int bacteriums;
    int antibioticDrops;
    cout << "Введите количество бактерий: ";
    cin >> bacteriums;
    cout << "Введите количество антибиотика: ";
    cin >> antibioticDrops;

    for(int hours = 0, activeAntibioticDrops = 0; bacteriums > 0 && antibioticDrops > 0;) {
        bacteriums *= 2;
        if(bacteriums >= 1375698999) {
            cout << "бактерий слишком много! Антибиотик не справляется. Опыт прерван.";
            break;
        }
        --antibioticDrops;
        ++activeAntibioticDrops;
        for(int counter = 0; counter < activeAntibioticDrops; counter++) {
            if((10 - counter) > 0 && bacteriums > 0){
                bacteriums -= (10 - counter);
            } else {
                break;
            }
        }
        ++hours;
        if(bacteriums < 0){
            bacteriums = 0;
        }
        cout << "После " << hours << " часа(ов) бактерий осталось: " << bacteriums << "\n";
    }

}