#include <iostream>
#include <cmath>

using namespace std;

bool has_input_error()
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

struct MathVector
{

public:
    double x = 0;
    double y = 0;
    double z = 0;

    MathVector(double newX = 0, double newY = 0, double newZ = 0) : x(newX), y(newY), z(newZ) {}

    void input()
    {
        do
        {
            cout << "input vector coordinates (x, y, z): " << endl;
            cin >> x >> y >> z;
        } while (has_input_error());
    }

    MathVector add(const MathVector &other)
    {
        return MathVector(x + other.x, y + other.y, z + other.z);
    }

    MathVector subtract(const MathVector &other)
    {
        return MathVector(x - other.x, y - other.y, z - other.z);
    }

    MathVector scale(const int &factor)
    {
        return MathVector(x * factor, y * factor, z * factor);
    }

    double length()
    {
        return sqrt(x * x + y * y + z * z);
    }

    void normalize()
    {
        double mathVecLength = length();
        if (mathVecLength < 1e-10)
        {
            x = 0;
            y = 0;
            z = 0;
            return;
        }
        x /= mathVecLength;
        y /= mathVecLength;
        z /= mathVecLength;
    }

    void print()
    {
        cout << "x: " << x << ", "
             << "y: " << y << ", "
             << "z: " << z << endl;
    }
};

int main()
{
    MathVector vec_1;
    MathVector vec_2;
    MathVector vec_3;
    int mathScalar = 0;
    unsigned userCommand = 0;
    while (true)
    {
        cout << "Input command:" << endl
             << "1 - add vector" << endl
             << "2 - scale vector" << endl
             << "3 - subtract vector" << endl
             << "4 - vector length" << endl
             << "5 - normalize vector" << endl
             << "0 - exit" << endl;
        do
        {
            cin >> userCommand;
        } while (has_input_error() || userCommand > 5);

        switch (userCommand)
        {
        case 1: // add vector
        {
            cout << "Vector 1 " << endl;
            vec_1.input();
            cout << "Vector 2 " << endl;
            vec_2.input();
            vec_3 = vec_1.add(vec_2);
            cout << "Result: " << endl
                 << "Vector 3 " << endl;
            vec_3.print();
            break;
        }
        case 2: // scale vector
        {
            cout << "Vector 1 " << endl;
            vec_1.input();
            do
            {
                cout << "Input mathScalar: " << endl;
                cin >> mathScalar;
            } while (has_input_error());
            vec_3 = vec_1.scale(mathScalar);
            cout << "Result: " << endl
                 << "Vector 3 " << endl;
            vec_3.print();
            break;
        }
        case 3: // subtract vector
        {
            cout << "Vector 1 " << endl;
            vec_1.input();
            cout << "Vector 2 " << endl;
            vec_2.input();
            vec_3 = vec_1.subtract(vec_2);
            cout << "Result: " << endl
                 << "Vector 3 " << endl;
            vec_3.print();
            break;
        }
        case 4: // vector length
        {
            cout << "Vector 1 " << endl;
            vec_1.input();
            cout << "Vector 1 length: " << vec_1.length();
            break;
        }
        case 5: // normalize vector
        {
            cout << "Vector 1 " << endl;
            vec_1.input();
            vec_1.normalize();
            cout << "Vector 1 normalized: " << endl;
            vec_1.print();
            double vecLength = vec_1.length();
            cout << "Checking, Vector 1 normalized length: " << vecLength << endl;
            if (fabs(vecLength - 1.0) < 1e-10)
            {
                cout << "Correct!" << endl;
            }
            else
            {
                cout << "Error. Vector length != 1" << endl;
            }
            break;
        }
        case 0: // exit
            return 0;

        default:
            return 0;
        }
    }
}