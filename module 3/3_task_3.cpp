#include <iostream>

int main(){
    int fullDaysCount = 2;
    int beginHeight = 100;
    int dailyGrowth = 50;
    int nightFade = 20;
    int totalheight = beginHeight + (dailyGrowth - nightFade) * fullDaysCount + (dailyGrowth / 2);

    std::cout << "bamboo height in the middle of the third day:" << totalheight;
}