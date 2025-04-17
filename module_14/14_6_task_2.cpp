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

string input_player_name(){
    string playerName;
    cout << "enter player name: " << endl;
    do{
        cin >> playerName;
    } while (input_validation_errors());
    return playerName;
}

void player_move(string playerName, int playerIndex, char field[][4]){
    int x;
    int y;
    bool validation = 0;
    cout << playerName << ", your turn, enter coordinates: ";
    do{
        cin >> x >> y;
        if(x < 1 || x > 3 || y < 1 || y > 3){
            cerr << "coordinates are out of scope! Try again" << endl;
        } else {
            if(field[x][y] == '_'){
                validation = 1;
            } else{
                cerr << "this cell is occupied! Try again" << endl;
            }
        }
    } while (input_validation_errors() || x < 1 || x > 3 || y < 1 || y > 3 || !validation);
    if(playerIndex == 1){
        field[x][y] = 'x';
    } else{
        field[x][y] = 'o';
    }
}

void print_field(char field[][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << field[i][j] << " | ";
        }
        cout << endl;
    }
}

int win_checking(char field[][4], string playerName1, string playerName2){
    int winner = 0;
    int xXcounter = 0;
    int xOcounter = 0;
    int yXcounter = 0;
    int yOcounter = 0;
    int dLxCounter = 0;
    int dLoCounter = 0;
    int dRxCounter = 0;
    int dRoCounter = 0;
    for(int i = 0; i < 4; i++){
        if(field[i][0] == 'x'){
            xXcounter++;
            if(xXcounter == 3){
                winner = 1;
                cout << "Congratulation! " << playerName1 << " win!" << endl;
            }
        } else if(field[i][0] == 'o'){
            xOcounter++;
            if(xOcounter == 3){
                winner = 2;
                cout << "Congratulation! " << playerName2 << " win!" << endl;
            }
        }
        if(field[i][i + 1] == 'x'){
            dRxCounter++;
            if(dRxCounter == 3){
                winner = 1;
                cout << "Congratulation! " << playerName1 << " win!" << endl;
            }
        } else if(field[i][i + 1] == 'o'){
            dRoCounter++;
            if(dRoCounter == 3){
                winner = 2;
                cout << "Congratulation! " << playerName2 << " win!" << endl;
            }
        }
        if(field[i][3 - i] == 'x'){
            dLxCounter++;
            if(dLxCounter == 3){
                winner = 1;
                cout << "Congratulation! " << playerName1 << " win!" << endl;
            }
        } else if(field[i][3 - i] == 'o'){
            dLoCounter++;
            if(dLoCounter == 3){
                winner = 2;
                cout << "Congratulation! " << playerName2 << " win!" << endl;
            }
        }
        for(int j = 0; j < 4; j++){
            if(field[i][j] == 'x'){
                yXcounter++;
                if(yXcounter == 3){
                    winner = 1;
                    cout << "Congratulation! " << playerName1 << " Win!" << endl;
                }
            } else if(field[i][j] == 'o'){
                yOcounter++;
                if(yOcounter == 3){
                    winner = 2;
                    cout << "Congratulation! " << playerName2 << " win!" << endl;
                }
            } 
        }
        yXcounter = 0;
        yOcounter = 0;
    }
    return winner;
}

int main(){
    char field[4][4] = {{' ','1','2','3'},
                        {'1','_','_','_'},
                        {'2','_','_','_'},
                        {'3','_','_','_'}};
    string playerName1 = input_player_name();
    string playerName2 = input_player_name();
    print_field(field);
    int winner = 0;

    for(int i = 1; i <= 9; i++){
        int playerIndex = 1;
        if(i % 2 == 1){
            player_move(playerName1, playerIndex, field);
        } else{
            playerIndex = 2;
            player_move(playerName2, playerIndex, field);
        }
        print_field(field);
        winner = win_checking(field, playerName1, playerName2);
        if(winner == 1 || winner == 2){
            return 0;
        }
    }
    if(winner == 0){
        cout << "It's a draw! Friendship has won!" << endl;
    }
}