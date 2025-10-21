#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string path = "/Users/evlasov/Documents/educationProject/module_20/block_5/add_files/";
const string inFileName = "river.txt";
const string outFileName = "basket.txt";

bool input_validation_errors()
{
    if (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Input error. Try again" << endl;
        return true;
    }
    else
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
}
void find_str_in_file(ifstream &inFile, ofstream &outFile, const string &str)
{
    string bufLine;
    unsigned matchesCnt = 0;
    cout << "Trying to catch " << str << endl;
    inFile.clear();
    inFile.seekg(0);
    while (getline(inFile, bufLine))
    {
        // cout << bufLine << endl;
        if (bufLine == str)
        {
            // cout << "put " << str << " in basket" << endl;
            outFile << str << endl;
            if (outFile.fail())
            {
                cerr << "Error writing to file!" << outFileName << endl;
                return;
            }
            matchesCnt++;
        }
    }
    if (matchesCnt == 0)
    {
        cout << "No " << str << " in the river" << endl;
    }
    else
    {
        cout << matchesCnt << " new fishes in your basket" << endl;
    }
}

int main()
{
    ifstream inFile(path + inFileName);
    if (!inFile.is_open())
    {
        cerr << "Error. Can't open the file " << path + inFileName << endl;
        return 1;
    }
    ofstream outFile(path + outFileName, ios::app);
    if (!outFile.is_open())
    {
        cerr << "Error. Can't open the file " << path + outFileName << endl;
        return 1;
    }
    string fishName;
    bool isRunning = 1;
    while (isRunning)
    {
        do
        {
            cout << "Input fish name: " << endl;
            cin >> fishName;
        } while (input_validation_errors());
        find_str_in_file(inFile, outFile, fishName);
        do
        {
            cout << "Continue? 1 - yes, 0 - no" << endl;
            cin >> isRunning;
        } while (input_validation_errors());
    }
    inFile.close();
    outFile.close();
    return 0;
}