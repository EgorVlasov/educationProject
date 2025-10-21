#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

const string path = "/Users/evlasov/Documents/educationProject/build/bin/add_files/";
const string fileName = "pic.txt";

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
bool check_pic_rez(const int &width, const int &height)
{
    if (width > 100 || height > 100)
    {
        cerr << "Error. Max rezolution 100x100px" << endl;
        return false;
    }
    else
    {
        return true;
    }
}
int get_random_int()
{
    return rand() % 2;
}
void fill_pic(ofstream &inputFile, const int &width, const int &height)
{
    srand(time(0));
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            inputFile << get_random_int();
        }
        inputFile << endl;
    }
    cout << "Pic complited" << endl;
}

int main()
{
    ofstream inputFile(path + fileName, ios::binary);
    if (!inputFile.is_open())
    {
        cerr << "Error. Can't open the file " << path + fileName << endl;
        return 0;
    }
    int width = 0;
    int height = 0;

    do
    {
        cout << "Input width and height of the pic, px(max 100x100): " << endl;
        cin >> width >> height;
    } while (input_validation_errors() || !check_pic_rez(width, height));
    fill_pic(inputFile, width, height);
    return 1;
}