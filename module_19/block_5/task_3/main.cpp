#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void file_parsing(ifstream &file, vector<string> &fieldsNames, vector<double> &fieldsSalaries, vector<string> &fieldsPaymentDates)
{
    string line;
    while (getline(file, line))
    {
        stringstream ssBuffer(line);
        int fieldNum = 0;
        string field;
        while (getline(ssBuffer, field, ','))
        {
            int error = 0;
            if (fieldNum < 3)
            {
                switch (fieldNum)
                {
                case 0:
                    fieldsNames.push_back(field);
                    break;
                case 1:
                    double doubleBuff;
                    try
                    {
                        doubleBuff = stod(field);
                    }
                    catch (...)
                    {
                        cerr << "ERROR DURING CONVERSION TO DOUBLE" << endl;
                        error = 1;
                    }
                    if (!error)
                    {
                        fieldsSalaries.push_back(doubleBuff);
                    }
                    else
                    {
                        fieldsSalaries.push_back(0);
                    }
                    break;
                case 2:
                    fieldsPaymentDates.push_back(field);
                    break;
                }
            }
            else
            {
                cerr << "field out of scope" << endl;
                break;
            }
            fieldNum++;
        }
    }
}
double calc_max_salary(const vector<double> &fieldsSalaries)
{
    double maxSalary = 0;
    for (int i = 0; i < fieldsSalaries.size(); i++)
    {
        if (maxSalary < fieldsSalaries[i])
        {
            maxSalary = fieldsSalaries[i];
        }
    }
    return maxSalary;
}
void find_lines_with_max_salary(vector<int> &buffIndexes, const vector<double> &fieldsSalaries)
{
    double maxSalary = calc_max_salary(fieldsSalaries);
    for (int i = 0; i < fieldsSalaries.size(); i++)
    {
        if (fieldsSalaries[i] == maxSalary)
        {
            buffIndexes.push_back(i);
        }
    }
}
void show_lines_with_max_salary(vector<int> &buffIndexes, const vector<string> &fieldsNames, const vector<double> &fieldsSalaries, const vector<string> &fieldsPaymentDates)
{
    find_lines_with_max_salary(buffIndexes, fieldsSalaries);
    for (int i = 0; i < buffIndexes.size(); i++)
    {
        cout << fieldsNames[buffIndexes[i]] << " | " << fieldsSalaries[buffIndexes[i]] << " | " << fieldsPaymentDates[buffIndexes[i]] << endl;
    }
    buffIndexes.clear();
}
double calc_total_salary(const vector<double> &fieldsSalaries)
{
    double totalSalary = 0;
    for (int i = 0; i < fieldsSalaries.size(); i++)
    {
        totalSalary += fieldsSalaries[i];
    }
    return totalSalary;
}

int main()
{
    string path = "/Users/evlasov/Documents/educationProject/module_19/block_5/add_files/";
    string fileName = "file";
    string fileExt = ".txt";
    ifstream inputFile;
    inputFile.open(path + fileName + fileExt);
    if (inputFile)
    {
        vector<string> fieldsNames;
        vector<double> fieldsSalaries;
        vector<string> fieldsPaymentDates;
        vector<int> buffIndexes;
        file_parsing(inputFile, fieldsNames, fieldsSalaries, fieldsPaymentDates);
        for (int i = 0; i < fieldsSalaries.size(); i++)
        {
            cout << fieldsNames[i] << " | " << fieldsSalaries[i] << " | " << fieldsPaymentDates[i] << endl;
        }
        cout << "____________________" << endl;
        cout << "Total paid:: " << calc_total_salary(fieldsSalaries) << endl;
        cout << "____________________" << endl;
        cout << "Employees with the highest salary: " << endl;
        show_lines_with_max_salary(buffIndexes, fieldsNames, fieldsSalaries, fieldsPaymentDates);
    }
    else
    {
        cerr << "Error. Can't open the file" << endl;
        return 0;
    }
}