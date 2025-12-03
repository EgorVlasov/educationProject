#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

using namespace std;
using namespace std::chrono;

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

int main()
{
    unsigned int m, s = 0;

    cout << "Timer set up" << endl;
    do
    {
        cout << "input minutes: (59 max)" << endl;
        cin >> m;
        if (m > 59)
        {
            cerr << "Error. 59 min max in timer" << endl;
        }
    } while (has_input_error() || m > 59);
    do
    {
        cout << "input seconds: (59 max)" << endl;
        cin >> s;
        if (s > 59)
        {
            cerr << "Error. 59 sec max in timer. Use minutes." << endl;
        }
    } while (has_input_error() || s > 59);

    seconds totalSeconds = m * 60s + s * 1s;
    auto endTime = steady_clock::now() + totalSeconds;

    while (steady_clock::now() < endTime)
    {
        auto remainingTime = endTime - steady_clock::now();
        auto mins = duration_cast<minutes>(remainingTime);
        remainingTime -= mins;
        auto secs = duration_cast<seconds>(remainingTime);

        cout << "\rTimer: "
             << setw(2) << setfill('0') << mins.count() << ":"
             << setw(2) << setfill('0') << secs.count()
             << flush;

        this_thread::sleep_for(1s);
    }
    cout << "DING! DING! DING!" << endl;
    return 0;
}
