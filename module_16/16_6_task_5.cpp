#include <iostream>
#include <sstream>
#include <string>

using namespace std;

enum switches {
    LIGHTS_INSIDE = 1 << 0,      // 00000001
    LIGHTS_OUTSIDE = 1 << 1,     // 00000010
    HEATERS = 1 << 2,            // 00000100
    WATER_PIPE_HEATING = 1 << 3, // 00001000
    CONDITIONER = 1 << 4         // 00010000
};

bool input_validation_errors(){
    if (cin.fail() || cin.peek() != '\n'){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Input error_3. Try again" << endl;
        return true;
    } else{
        return false;
    }
}
bool check_monitoringState(){
    string strMonitoringState;
    bool check1;
    bool check2;
    do{
        cout << "Continue monitoring?(yes/no) ";
        cin >>  strMonitoringState;
        check1 = input_validation_errors();
        if(!check1){
            if(strMonitoringState == "yes" || strMonitoringState == "no"|| strMonitoringState == "Yes" || strMonitoringState == "No"){
                check2 = true;
            } else{
                check2 = false;
                cerr << "Input error_2. Try again" << endl;
            }
        }else{
            check2 = false;
        }
    } while(!check2);

    if(strMonitoringState == "yes" || strMonitoringState == "Yes" ){
        return true;
    } else{
        cout << "Goodbye!" << endl;
        return false;
    }
}
bool str_to_bool(string strState){
    if(strState == "yes" || strState == "Yes" || strState == "on" || strState == "On"){
        return true;
    }else{
        return false;
    }

}
void switch_WATER_PIPE_HEATING(int &tempOutside, int &switchesState){
    if(tempOutside < 0){
        switchesState |= WATER_PIPE_HEATING;
    }
    if(tempOutside > 5 && (switchesState & WATER_PIPE_HEATING)){
        switchesState &= ~WATER_PIPE_HEATING;
    }
}
void switch_HEATERS(int &tempInside, int &switchesState){
    if(tempInside < 22){
        switchesState |= HEATERS;
    }else if(tempInside >= 25){
        switchesState &= ~HEATERS;
    }
}
void switch_CONDITIONER(int &tempInside, int &switchesState){
    if(tempInside >= 30){
        switchesState |= CONDITIONER;
    }else if(tempInside <= 25){
        switchesState &= ~CONDITIONER;
    }
}
void switch_LIGHTS_OUTSIDE(bool &movement, int &currentTime, int &switchesState){
    if(movement && (currentTime > 16 || currentTime < 5)){
        switchesState |= LIGHTS_OUTSIDE;
    } else{
        switchesState &= ~LIGHTS_OUTSIDE;
    }
}
void switch_LIGHTS_INSIDE(bool &lights, int &currentTime, int &lightTemp, int &switchesState){
    if(lights){
        switchesState |= LIGHTS_INSIDE;
    if(currentTime >= 16 && currentTime <= 20){
        lightTemp = 2700 + 575 * (20 - currentTime);
    }
    } else{
        switchesState &= ~LIGHTS_INSIDE;
    }
}
void show_switchesState(int &switchesState, int &lightTemp){
    cout << "WATER PIPE HEATING: " << ((switchesState & WATER_PIPE_HEATING) ? "ON" : "OFF") << endl
        << "HEATERS: " << ((switchesState & HEATERS) ? "ON" : "OFF") << endl
        << "CONDITIONER: " << ((switchesState & CONDITIONER) ? "ON" : "OFF") << endl
        << "LIGHTS INSIDE: " << ((switchesState & LIGHTS_INSIDE) ? "ON" : "OFF") << endl;
    if(switchesState & LIGHTS_INSIDE){
        cout << "LIGHT TEMPERATURE: " << lightTemp << "K" << endl;
    }
    cout << "LIGHT OUTSIDE: " << ((switchesState & LIGHTS_OUTSIDE) ? "ON" : "OFF") << endl;
}

int main () {

    string strMovementState, strLightsState;
    bool movement, lights;
    bool monitoring = true;
    int tempOutside, tempInside;
    int lightTemp = 5000;
    int switchesState = 0;
    int currentTime = 0;

    do{
        string inputStr;
        cout << "Temperature outside, temperature inside, movement(yes/no), lights(on/off):";
        getline(cin, inputStr);
        stringstream ssBuffer(inputStr);
        if(
            ssBuffer >> tempOutside && 
            ssBuffer >> tempInside && 
            ssBuffer >> strMovementState && 
            ssBuffer >> strLightsState &&
            (strMovementState == "yes" || strMovementState == "Yes" || strMovementState == "no" || strMovementState == "No")  &&
            (strLightsState == "on" || strLightsState == "On" || strLightsState == "off" || strLightsState == "Off")
        ){
            movement = str_to_bool(strMovementState);
            lights = str_to_bool(strLightsState);
            switch_WATER_PIPE_HEATING(tempOutside, switchesState);
            switch_HEATERS(tempInside, switchesState);
            switch_CONDITIONER(tempInside, switchesState);
            switch_LIGHTS_OUTSIDE(movement, currentTime, switchesState);
            switch_LIGHTS_INSIDE(lights, currentTime, lightTemp, switchesState);
            cout << "Time: " << currentTime << endl;
            show_switchesState(switchesState, lightTemp);

            if(currentTime == 24){
                cout << "Next day." << endl;
                currentTime = 0;
                lightTemp = 5000;
                monitoring = check_monitoringState();
            }
            currentTime++;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }else{
            cerr << "input error_1! try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }while(monitoring);
}