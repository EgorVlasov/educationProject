#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
//#include <filesystem>


using namespace std;

const int sectorsCnt = 13;
const int totalScoreToWin = 6;
const string path= "./add_files/";

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
int get_random_int(int max){
     srand(time(NULL));
     return rand() % (max);
}
void parse_file_to_vec(vector <string> &vec, const string &name){
    ifstream file;
    //std::filesystem::path currentDir = std::filesystem::current_path();
    //cout << currentDir;
    file.open(path + name);
    if(file){
        string line;
        while(getline(file, line)){
            vec.push_back(line);
        }
        file.close();
    }else{
        cerr << "Error. Can't open the file" << endl;
    }
}
bool check_answer(const string &answer,  vector <string> &answers, const int &sectorNum){
    if(answer == answers[sectorNum]){
        return true;
    } else{
        return false;
    }
}

int main(){
    const string answersListFileName = "answers.txt";
    const string questionsListFileName = "questions.txt";
    vector <string> questions;
    parse_file_to_vec(questions, questionsListFileName);
    int freeSectors = questions.size();
    if(freeSectors < sectorsCnt){
        cerr << "Error. Insufficient number of questions in the file" << endl;
        return 0;
    }
    vector <string> answers;
    parse_file_to_vec(answers, answersListFileName);
    if(answers.size() != freeSectors){
        cerr << "Error. Insufficient number of answers in the file" << endl;
        return 0;       
    }

    cout << "Let's start!" << endl;
    int score[2] = {0,0};
    while(score[0] < totalScoreToWin && score[1] < totalScoreToWin){
        string answer;
        int sectorNum =  get_random_int(questions.size());
        cout << "On the wheel, sector " << sectorNum << ", a question from the viewer:" << endl;
        cout << questions[sectorNum] << endl;
        do{
            cout << "Your answer: " << endl;
            getline(cin, answer);
        }while(input_validation_errors());
        if(check_answer(answer, answers, sectorNum)){
            score[0]++;
            cout << "Correct! +1 point to your team" << endl;
        }else{
            score[1]++;
            cout << "Wrong answer! +1 point goes to viewers team" << endl;
            cout << "Correct answer: " << answers[sectorNum] << endl; 
        }
        cout << "Experts: " << score[0] << " | Viewers: " << score[1] << endl;
        answers.erase(answers.begin() + sectorNum);
        questions.erase(questions.begin() + sectorNum);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if(score[0] > score[1]){
        cout << "Congratulations! Experts win!" << endl;
    }else{
        cout << "You loose! Viewers win!" << endl;
        return 1;
    }
}