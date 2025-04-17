#include <iostream>
#include <string>

using namespace std;

bool input_validation_errors(){
    if (cin.fail() || cin.peek() != '\n'){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Input error. Try again" << endl;
        return true;
    } else{
        return false;
    }
}

string enter_players_name(string playerName){
    cout << "enter player name: " << endl;
    do{
        cin >> playerName;
    } while (input_validation_errors());
    return playerName;
}

void field_creation(bool field_1[][10], bool field_2[][10]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            field_1[i][j] = false;
            field_2[i][j] = false;
        }
    }
}

void add_field_creation(bool field_1_2[][10], bool field_2_2[][10]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            field_1_2[i][j] = false;
            field_2_2[i][j] = false;
        }
    }
}

void ship_coordinates_request(unsigned int coordinates[][2], int &shipDeckCount){
    cout << "Enter coordinates for " << shipDeckCount << "-decked Ship." << endl;
    for(int i = 0; i < 2; i++){
        if(i == 0){
            cout << "Enter coordinates (y,x) of the beginning of the ship" << endl;
        } else{
            cout << "Enter coordinates (y,x) of the end of the ship" << endl;
        }
        do{
            cin >> coordinates[i][0] >> coordinates[i][1];
            if(coordinates[i][0] > 9 || coordinates[i][1] > 9){
                cerr << "Error. Coordinate is out of scope! Try again." << endl;;
            }
        }while (input_validation_errors() || coordinates[i][0] > 9 || coordinates[i][1] > 9);
    }
    if(coordinates[1][1] < coordinates[0][1]){
        swap(coordinates[1][1], coordinates[0][1]);
    } else if(coordinates[1][0] < coordinates[0][0]){
        swap(coordinates[1][0], coordinates[0][0]);
    }
}

bool ship_coordinates_are_correct(unsigned int coordinates[][2], int &shipType){
    if(coordinates[0][0] == coordinates[1][0]){
        int j = 0;
        for(int i = coordinates[0][1]; i <= coordinates[1][1]; i++){
            j++;
        }

        if(j == shipType){
            return true;
        } else{
            cerr << "incorrect coordinates. Enter the coordinates for " << shipType << "-decked Ship" << endl;;
            return false;
        }    
    } else if(coordinates[0][1] == coordinates[1][1]){
        int j = 0;
        for(int i = coordinates[0][0]; i <= coordinates[1][0]; i++){
            j++;
        }

        if(j == shipType){
            return true;
        } else{
            cerr << "incorrect coordinates. Enter the coordinates for " << shipType << "-decked Ship" << endl;;
            return false;
        }   
    } else{
        cerr << "incorrect coordinates. Enter the coordinates for " << shipType << "-decked Ship" << endl;;
        return false;
    }
}

bool ship_coordinates_are_free(bool field[][10], unsigned int coordinates[][2]){
    for(int i = coordinates[0][0]; i <= coordinates[1][0]; i++){
        for(int j = coordinates[0][1]; j <= coordinates[1][1]; j++){
            if(field[i][j]){
                cerr << "This point (" << i << ", " << j << ") is occupied, plese enter another interval " << endl;
                return false; 
            }
        }
    }
    return true;
}

void print_field(bool field[10][10]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
}

bool ships_arrangement(bool field[10][10]){
    int oneDeckedShipCnt = 4;
    int twoDeckedShipCnt = 3;
    int threeDeckedShipCnt = 2;
    int fourDeckedShipCnt = 1;

    unsigned int coordinates[2][2];
    print_field(field);
    for(int i = 1; i <= (oneDeckedShipCnt + twoDeckedShipCnt + threeDeckedShipCnt + fourDeckedShipCnt); i++){
        int shipType;
        if(i <= oneDeckedShipCnt){
            shipType = 1;
        } else if(i > oneDeckedShipCnt && i <= oneDeckedShipCnt + twoDeckedShipCnt){
            shipType = 2;
        } else if(i > (oneDeckedShipCnt + twoDeckedShipCnt) && i <= (oneDeckedShipCnt + twoDeckedShipCnt + threeDeckedShipCnt)){
            shipType = 3;
        } else{
            shipType = 4;
        }

        do{
            ship_coordinates_request(coordinates, shipType);
        } while(!ship_coordinates_are_correct(coordinates, shipType) || !ship_coordinates_are_free(field, coordinates));
        
        for(int i = coordinates[0][0]; i <= coordinates[1][0]; i++){
            for(int j = coordinates[0][1]; j <= coordinates[1][1]; j++){
                field[i][j] = true;
            }
        }

        print_field(field);
    }
    return field[10][10];
}

int check_for_winner(bool field_1[][10], bool field_2[][10], int &round){
    int realShipCnt = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(round % 2){
                if(field_2[i][j]){
                    realShipCnt++;
                }    
            } else{
                if(field_1[i][j]){
                    realShipCnt++;
                }   
            }    
       }
    }
    if(realShipCnt == 0){
        if(round % 2){
            return 1;
        } else{
            return 2;
        }
    } else{
        return 0;
    }
}

void shot_coordinates_request(int coordinates[2]){
    do{
        cin >> coordinates[0] >> coordinates[1];
        if(coordinates[0] > 9 || coordinates[1] > 9){
            cerr << "Error. Coordinate is out of scope! Try again." << endl;
        }
    } while (input_validation_errors() || coordinates[0] > 9 || coordinates[1] > 9);
}

bool player1_shot(bool field_2[][10], bool field_1_2[][10]){
    print_field(field_1_2);
    int coordinates[2];
    shot_coordinates_request(coordinates);
    if(field_2[coordinates[0]][coordinates[1]]){
        field_2[coordinates[0]][coordinates[1]] = false;
        field_1_2[coordinates[0]][coordinates[1]] = true;
        cout << endl << "HIT!" << endl;
        return true;
    } else{
        cout << endl << "Miss!" << endl;
        return false;
    }
}
bool player2_shot(bool field_1[][10], bool field_2_2[][10]){
    print_field(field_2_2);
    int coordinates[2];
    shot_coordinates_request(coordinates);
    if(field_1[coordinates[0]][coordinates[1]]){
        field_1[coordinates[0]][coordinates[1]] = false;
        field_2_2[coordinates[0]][coordinates[1]] = true;
        cout << endl << "HIT!" << endl;
        return true;
    } else{
        cout << endl << "Miss!" << endl;
        return false;
    }
}

int main(){
    string playerName1;
    playerName1 = enter_players_name(playerName1);
    string playerName2;
    playerName2 = enter_players_name(playerName2);

    bool field_1[10][10]; 
    bool field_2[10][10];
    field_creation(field_1, field_2);

    bool field_1_2[10][10]; 
    bool field_2_2[10][10];
    add_field_creation(field_1, field_2);
    
    cout << playerName1 << ", arrange your ships" << endl;
    field_1[10][10] = ships_arrangement(field_1);

    cout << playerName2 << ", arrange your ships" << endl;
    field_2[10][10] = ships_arrangement(field_2);

    int round = 1;
    int winner = 0;
    while(winner == 0){
        if(round % 2){
            cout << playerName1 << ", your turn to hit!" << endl;
            if(player1_shot(field_2, field_1_2)){
                round++;
            }
        } else{
            cout << playerName2 << ", your turn to hit!" << endl;
            if(player2_shot(field_1, field_2_2)){
                round++;
            }
        }
        round ++;
        winner = check_for_winner(field_1, field_2, round);
    }
    if(winner == 1){
        cout << "Congratulation," << playerName1 << "! You are WIN!" << endl;
    } else{
        cout << "Congratulation," << playerName2 << "! You are WIN!" << endl;
    }
}