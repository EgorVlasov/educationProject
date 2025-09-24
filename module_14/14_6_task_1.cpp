#include <iostream>

using namespace std;

int main(){
    int cutlery[2][12];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 12; j++){
            cutlery[i][j] = 3;
        }
    }
    int plates[2][12];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 12; j++){
            plates[i][j] = 2;
        }
    }
    int chairs[2][12];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 12; j++){
            chairs[i][j] = 1;
        }
    }
    
    // + 1 прибор для VIP
    for(int i = 0; i < 2; i++){
        cutlery[i][0] += 1;
    }
    // + 1 тарелка для VIP
    for(int i = 0; i < 2; i++){
        plates[i][0] += 1;
    }
    // Пришедшая на пятое место первого ряда дама привела с собой ребёнка + 1 стул
    chairs[0][4] += 1;
    // С третьего места во втором ряду в неизвестном направлении была украдена ложка
    cutlery[1][2] -= 1;
    // Одна из VIP-персон (любая) поделилась своей ложкой с тем, кто остался без ложки
    cutlery[1][0] -= 1;
    cutlery[1][2] += 1;
    // За ненадобностью официант забрал у VIP-гостя одну десертную тарелку
    plates[1][0] -= 1;
}

