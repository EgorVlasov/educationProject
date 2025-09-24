#include <iostream>
#include <string>

using namespace std;

int main () {
    string startTime;
    int startTimeHours;
    int startTimeMinutes;
    int startTimeTotalMinutes;

    bool inputValidation;
    cout << "Enter start time (HH:MM):\n";
     do{
        inputValidation = true;            
        cin >> startTime;
        if (cin.fail() || cin.peek() != '\n'){
            cerr << "Input error. Try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if(startTime[2] != ':' || startTime[0] < '0' || startTime[1] > '9' ||
                startTime[3] < '0' || startTime[4] > '9' || startTime.length() > 5){
            cerr << "Input error. Try again\n";
        } else{
            startTimeHours = (startTime[0] - '0') * 10 + (startTime[1] - '0');
            startTimeMinutes = (startTime[3] - '0') * 10 + (startTime[4] - '0');
            startTimeTotalMinutes = startTimeHours * 60 + startTimeMinutes;

            if(startTimeHours > 24 || startTimeMinutes > 59 || startTimeTotalMinutes > 1440){
                cerr << "Input error. Try again\n";
            } else{
                inputValidation = false;
            }
        }
    } while(inputValidation);

    string finishTime;
    int finishTimeHours;
    int finishTimeMinutes;
    int finishTimeTotalMinutes;

    cout << "Enter finish time (HH:MM):\n";
     do{
        inputValidation = true;            
        cin >> finishTime;
        if (cin.fail() || cin.peek() != '\n'){
            cerr << "Input error. Try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if(finishTime[2] != ':' || finishTime[0] < '0' || finishTime[1] > '9' ||
                finishTime[3] < '0' || finishTime[4] > '9' || finishTime.length() > 5){
            cerr << "Input error. Try again\n";
        } else{
            finishTimeHours = (finishTime[0] - '0') * 10 + (finishTime[1] - '0');
            finishTimeMinutes = (finishTime[3] - '0') * 10 + (finishTime[4] - '0');
            finishTimeTotalMinutes = finishTimeHours * 60 + finishTimeMinutes;

            if(finishTimeHours > 24 || finishTimeMinutes > 59 || finishTimeTotalMinutes > 1440){
                cerr << "Input error. Try again\n";
            } else{
                inputValidation = false;
            }
        }
    } while(inputValidation);

    if(startTimeTotalMinutes > finishTimeTotalMinutes){
        finishTimeTotalMinutes += 1440;
    }

    int travelTimeTotalMinutes = finishTimeTotalMinutes - startTimeTotalMinutes;
    int travelTimeHours = travelTimeTotalMinutes / 60;
    int travelTimelMinutes = travelTimeTotalMinutes % 60;

    cout << "travel time: " << travelTimeHours << " h " << travelTimelMinutes << " min \n";

return 0;
}