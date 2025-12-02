#include <iostream>
#include <string>
#include <optional>
#include <chrono>
#include <map>

using namespace std;
using namespace std::chrono;

struct Tasks
{
    string name;
    optional<steady_clock::time_point> startTime;
    optional<steady_clock::time_point> endTime;
};

map<int, Tasks> allTasks;

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

void addToCache(Tasks &task)
{
    int newKey = 1;
    if (!allTasks.empty())
    {
        newKey = allTasks.rbegin()->first + 1;
    }
    allTasks.emplace(newKey, task);
}

void end(Tasks &currentTask)
{
    if (currentTask.startTime.has_value())
    {
        currentTask.endTime = steady_clock::now();
        addToCache(currentTask);
        cout << "task " << currentTask.name << " finished" << endl;
    }
    else
    {
        cerr << "Error. No open tasks" << endl;
    }
}

void begin(Tasks &newTask, Tasks &currentTask)
{
    int nameSize = 0;
    do
    {
        cout << "Input task name: " << endl;
        getline(cin, newTask.name);
        nameSize = newTask.name.size();
        if (nameSize > 30)
        {
            cerr << "Error. Too many symbols." << endl;
        }
    } while (has_input_error() || nameSize > 30);

    if (!currentTask.endTime.has_value() && currentTask.startTime.has_value())
    {
        end(currentTask);
    }
    newTask.startTime = steady_clock::now();
    currentTask = newTask;
}

void showDurationInHMS(steady_clock::duration duration)
{
    auto h = duration_cast<hours>(duration);
    auto m = duration_cast<minutes>(duration % hours(1));
    auto s = duration_cast<seconds>(duration % minutes(1));

    cout << "duration: " << h.count() << "h:" << m.count() << "m:" << s.count() << "s" << endl;
}

void showCurrentTask(Tasks &currentTask)
{
    if (currentTask.startTime.has_value())
    {
        cout << "task name: " << currentTask.name << endl;
        cout << "status: In progrss" << endl;
        auto duration = steady_clock::now() - currentTask.startTime.value();
        showDurationInHMS(duration);
    }
    else
    {
        cout << "No active tasks" << endl;
    }
    cout << endl;
}

void status(Tasks &currentTask)
{
    showCurrentTask(currentTask);

    if (!allTasks.empty())
    {
        for (const auto &pair : allTasks)
        {
            cout << "task id: " << pair.first << endl;
            cout << "task name: " << pair.second.name << endl;
            cout << "status: Done" << endl;
            auto duration = pair.second.endTime.value() - pair.second.startTime.value();
            showDurationInHMS(duration);
            cout << endl;
        }
    }
    else
    {
        cout << "No ended tasks" << endl;
    }
}

bool is_valid_command(int command)
{
    if (command < 0 || command > 3)
    {
        cerr << "Invalide operation code." << endl;
        return false;
    }
    else
    {
        return true;
    }
}

int get_user_command()
{
    unsigned int command = 0;
    do
    {
        cout << "=== MENU ===" << endl;
        cout << "1 - add new task" << endl;
        cout << "2 - finish active task" << endl;
        cout << "3 - Status" << endl;
        cout << "0 - Exit" << endl;
        cin >> command;
    } while (has_input_error() || !is_valid_command(command));
    return command;
}

int main()
{
    unsigned int userCommand = 0;
    Tasks currentTask;

    while (true)
    {
        userCommand = get_user_command();

        switch (userCommand)
        {
        case 1: // add new task
        {
            Tasks newTask;
            begin(newTask, currentTask);
        }
        break;
        case 2: // finish active task
        {
            end(currentTask);
        }
        break;
        case 3: // Status
        {
            status(currentTask);
        }
        break;
        case 0: // Exit
            cout << "Goodbye!" << endl;
            return 0;
        default:
            return 0;
        }
    }
}