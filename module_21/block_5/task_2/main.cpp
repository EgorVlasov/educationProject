#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

const string path = "/Users/evlasov/Documents/educationProject/module_21/block_5/add_files/";

enum class buildingsTypes : uint8_t
{
    house,
    garage,
    barn,
    bathhouse
};

enum class roomsTypes : uint8_t
{
    bedroom,
    kitchen,
    bathroom,
    childrens_room,
    living_room,
    steam_room,
    relaxation_room,
    washroom,
    non_residential_premise
};

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

string get_string_from_file_by_id(const int &objId, const string &fileName)
{
    ifstream dataFile(path + fileName);
    if (!dataFile.is_open())
    {
        return "FILE_NOT_FOUND";
    }
    string bufLine;
    while (getline(dataFile, bufLine))
    {
        if (to_string(objId) == bufLine.substr(0, bufLine.find(',')))
        {
            dataFile.close();
            return bufLine;
        }
    }
    dataFile.close();
    return "NOT_FOUND";
}

string get_string_from_file_by_parentId(const int &parentId, streampos &searchPos, const string &fileName)
{
    ifstream dataFile(path + fileName);
    if (!dataFile.is_open())
    {
        return "FILE_NOT_FOUND";
    }
    dataFile.seekg(searchPos);
    string bufLine;
    while (getline(dataFile, bufLine))
    {
        stringstream ss(bufLine);
        string field;
        getline(ss, field, ',');
        if (getline(ss, field, ','))
        {
            if (to_string(parentId) == field)
            {
                searchPos = dataFile.tellg();
                dataFile.close();
                return bufLine;
            }
        }
    }
    dataFile.close();
    return "NOT_FOUND";
}

int get_new_id(const string fileName)
{
    ifstream dataFile(path + fileName, ios::ate);
    int newId = 0;
    if (!dataFile.is_open())
    {
        cerr << "Can't open file " << fileName << endl;
        cerr << "Try to create new data file... " << endl;
        ofstream newDataFile(path + fileName);
        if (!newDataFile.is_open())
        {
            cerr << "Fatal error. Can't create new data file " << fileName << endl;
            return -1;
        }
        newDataFile.close();

        dataFile.open(path + fileName, ios::ate);
        if (!dataFile.is_open())
        {
            cerr << "Fatal error. Can't reopen created file " << fileName << endl;
            return -1;
        }
    }
    streampos fileSize = dataFile.tellg();
    if (fileSize == 0)
    {
        return 1;
    }
    streampos currentPos = fileSize;
    int lineCnt = 0;
    while (currentPos > 0)
    {
        dataFile.seekg(-1, ios::cur);
        currentPos = dataFile.tellg();
        if (dataFile.get() == '\n' && lineCnt > 1)
        {
            dataFile.seekg(1, ios::cur);
            string lastLine;
            getline(dataFile, lastLine);
            stringstream ss(lastLine);
            string field;
            getline(ss, field, ',');
            dataFile.close();
            return stoi(field) + 1;
        }
        lineCnt++;
    }
    cerr << "Incorrect file " << fileName << endl;
    cerr << "Can't find last id in not empty file" << endl;
    dataFile.close();
    return 0;
}

bool is_valid_command(int command)
{
    if (command < 0 || command > 4)
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
        cout << "1 - add new Plot" << endl;
        cout << "2 - add new Building" << endl;
        cout << "3 - add new Floor" << endl;
        cout << "4 - add new Room" << endl;
        cout << "0 - exit" << endl;
        cin >> command;
    } while (has_input_error() || !is_valid_command(command));
    return command;
}

struct Plots
{
public:
    const string fileName = "plots.csv";
    int id;
    unsigned int number;
    string owner;
    double area;

private:
    bool write_to_file()
    {
        ofstream dataFile(path + fileName, ios::app);
        if (!dataFile.is_open())
        {
            cerr << "Error. Can't write to" << "'plots.csv'" << endl;
            return false;
        }
        dataFile << id << "," << number << "," << owner << "," << area;
        dataFile.close();
        return true;
    }

    bool is_input_owner_correct()
    {
        if (owner.length() > 30 || owner.length() < 1)
        {
            cerr << "Error. Invalid name" << endl;
            return false;
        }
        for (char s : owner)
        {
            if (((s < 65 || s > 90) && (s < 97 || s > 122)) && s != 45)
            {
                cerr << "Error. Invalid name. String shoud contain only latters (A-Z, a-z) or symbol '-'" << endl;
                return false;
            }
        }
        return true;
    }

public:
    int get_id_by_number(const int &number)
    {
        int id = 0;
        ifstream dataFile(path + fileName);
        if (!dataFile.is_open())
        {
            cerr << "Can't open the data file" << endl;
            return -1;
        }
        string bufLine;
        while (getline(dataFile, bufLine))
        {
            stringstream ss(bufLine);
            string field;
            if (getline(ss, field, ','))
            {
                id = stoi(field);
            }
            if (getline(ss, field, ','))
            {
                if (field == to_string(number))
                {
                    dataFile.close();
                    cout << "Number exist" << endl;
                    return id;
                }
            }
        }
        dataFile.close();
        cout << "Number is not exist" << endl;
        return 0;
    }

    void get_object_by_id(const int &objId)
    {
        string data = get_string_from_file_by_id(objId, fileName);
        if (data == "NOT_FOUND" || data == "FILE_NOT_FOUND")
        {
            cerr << "Plot with id " << objId << " not found" << endl;
            return;
        }
        string field;
        stringstream ss(data);
        try
        {
            if (!getline(ss, field, ','))
                return;
            id = stoi(field);
            if (!getline(ss, field, ','))
                return;
            number = stoi(field);
            if (!getline(ss, owner, ','))
                return;
            if (!getline(ss, field, ','))
                return;
            area = stod(field);
        }
        catch (const exception &e)
        {
            cerr << "Error parsing data for id " << objId << ": " << e.what() << endl;
        }
    }

    int add_new_object()
    {
        char choice;

        id = get_new_id(fileName);
        if (id == -1 || id == 0)
        {
            cerr << "Can't add new Plot" << endl;
            return id;
        }

        do
        {
            cout << "Input Plot number: " << endl;
            cin >> number;
        } while (has_input_error() || get_id_by_number(number) > 0);
        do
        {
            cout << "Input Plot owner name: " << endl;
            cin >> owner;
        } while (has_input_error() || !is_input_owner_correct());
        do
        {
            cout << "Input Plot area, m2: " << endl;
            cin >> area;
            if (area <= 0)
            {
                cerr << "Area cannot have a negative value or be equal 0" << endl;
            }
        } while (has_input_error() || area <= 0);

        if (write_to_file())
        {
            cout << "Plot added" << endl;
            return id;
        }
        cerr << "Can't write object data to the file" << endl;
        return -2;
    }
};

struct Buildings
{
public:
    const string fileName = "buildings.csv";
    int id;
    int plotId;
    buildingsTypes type;
    double area;
    bool hasStove;

private:
    string building_type_to_string()
    {
        switch (type)
        {
        case buildingsTypes::house:
            return "house";
        case buildingsTypes::garage:
            return "garage";
        case buildingsTypes::barn:
            return "barn";
        case buildingsTypes::bathhouse:
            return "bathhouse";
        default:
            return "unknown";
        }
    }

    buildingsTypes string_to_building_type(const string &str)
    {
        if (str == "house")
            return buildingsTypes::house;
        if (str == "garage")
            return buildingsTypes::garage;
        if (str == "barn")
            return buildingsTypes::barn;
        if (str == "bathhouse")
            return buildingsTypes::bathhouse;
        return buildingsTypes::house;
    }

    bool write_to_file()
    {
        ofstream dataFile(path + fileName, ios::app);
        if (!dataFile.is_open())
        {
            cerr << "Error. Can't write to" << "'buildings.csv'" << endl;
            return false;
        }
        string typeStr = building_type_to_string();
        dataFile << id << "," << plotId << "," << typeStr << "," << area << "," << hasStove;
        dataFile.close();
        return true;
    }

public:
    double calc_total_buldings_area_by_plotId(const int &plotId)
    {
        string str;
        double totalBuldingsArea = 0.00;
        streampos currentPos = 0;
        while (true)
        {
            str = get_string_from_file_by_parentId(plotId, currentPos, fileName);

            if (str == "NOT_FOUND")
            {
                break;
            }
            if (str == "FILE_NOT_FOUND")
            {
                cerr << "File not found: " << fileName << endl;
                break;
            }

            stringstream ss(str);
            string field;
            for (int i = 0; getline(ss, field, ','); i++)
            {
                if (i == 3)
                {
                    try
                    {
                        totalBuldingsArea += stod(field);
                        break;
                    }
                    catch (const exception &e)
                    {
                        cerr << "Error parsing area: '" << field << "': " << e.what() << endl;
                    }
                }
            }
        }
        return totalBuldingsArea;
    }

    void get_object_by_id(const int &objId)
    {
        string data = get_string_from_file_by_id(objId, fileName);
        if (data == "NOT_FOUND" || data == "FILE_NOT_FOUND")
        {
            cerr << "Building with id " << objId << " not found" << endl;
            return;
        }
        string field;
        stringstream ss(data);
        try
        {
            if (!getline(ss, field, ','))
                return;
            id = stoi(field);
            if (!getline(ss, field, ','))
                return;
            plotId = stoi(field);
            if (!getline(ss, field, ','))
                return;
            type = string_to_building_type(field);
            if (!getline(ss, field, ','))
                return;
            area = stod(field);
            if (!getline(ss, field, ','))
                return;
            hasStove = stoi(field);
        }
        catch (const exception &e)
        {
            cerr << "Error parsing data for id " << objId << ": " << e.what() << endl;
        }
    }

    int add_new_object(const int &parentId)
    {
        id = get_new_id(fileName);
        if (id == -1 || id == 0)
        {
            cerr << "Can't add new Building" << endl;
            return id;
        }
        int floorLimit = 0;
        int floorsAdded = 0;
        char choice;
        Plots plot;
        plot.get_object_by_id(parentId);
        double areaLimitforBuilding = plot.area * 0.6 - calc_total_buldings_area_by_plotId(plotId);

        do
        {
            cout << "Choose your building type:'" << endl;
            cout << "1 - house" << endl;
            cout << "2 - garage" << endl;
            cout << "3 - barn" << endl;
            cout << "4 - bathhouse" << endl;
            cin >> choice;
        } while (has_input_error() || (choice < 49 || choice > 52));

        switch (choice)
        {
        case '1':
            type = buildingsTypes::house;
            floorLimit = 3;
            do
            {
                cout << "Do this building has a stove?" << endl;
                cout << "1 - yes" << endl;
                cout << "0 - no" << endl;
                cin >> hasStove;
            } while (has_input_error());
            break;
        case '2':
            type = buildingsTypes::garage;
            floorLimit = 1;
            hasStove = false;
            break;
        case '3':
            type = buildingsTypes::barn;
            floorLimit = 1;
            hasStove = false;
            break;
        case '4':
            type = buildingsTypes::bathhouse;
            floorLimit = 2;
            hasStove = true;
            break;
        }

        do
        {
            cout << "Input bulding area, m2" << endl;
            cin >> area;
            if (area > areaLimitforBuilding)
            {
                cerr << "bulding is too large, max: " << areaLimitforBuilding << "m2" << endl;
            }
        } while (has_input_error() || area > areaLimitforBuilding);

        if (write_to_file())
        {
            cout << "Building added" << endl;
            return id;
        }
        cerr << "Can't write object data to the file" << endl;
        return -2;
    }
};

struct Floors
{
public:
    const string fileName = "floors.csv";
    int id;
    int buildingId;
    unsigned int level;
    float height;

private:
    bool write_to_file()
    {
        ofstream dataFile(path + fileName, ios::app);
        if (!dataFile.is_open())
        {
            cerr << "Error. Can't write to" << "'floors.csv'" << endl;
            return false;
        }
        dataFile << id << "," << buildingId << "," << level << "," << height;
        dataFile.close();
        return true;
    }

    bool is_floor_level_exist()
    {
        ifstream dataFile(path + fileName);
        if (!dataFile.is_open())
            return false;

        string bufLine;
        while (getline(dataFile, bufLine))
        {
            stringstream ss(bufLine);
            string field;
            getline(ss, field, ',');
            getline(ss, field, ',');
            if (field == to_string(buildingId))
            {
                getline(ss, field, ',');
                if (field == to_string(level))
                {
                    dataFile.close();
                    return true;
                }
            }
        }
        dataFile.close();
        return false;
    }

public:
    void get_object_by_id(const int &objId)
    {
        string line = get_string_from_file_by_id(objId, fileName);
        if (line == "NOT_FOUND" || line == "FILE_NOT_FOUND")
        {
            cerr << "Floor with id " << objId << " not found" << endl;
            return;
        }
        string field;
        stringstream ss(line);
        try
        {
            if (!getline(ss, field, ','))
                return;
            id = stoi(field);
            if (!getline(ss, field, ','))
                return;
            buildingId = stoi(field);
            if (!getline(ss, field, ','))
                return;
            level = stoi(field);
            if (!getline(ss, field, ','))
                return;
            height = stof(field);
        }
        catch (const exception &e)
        {
            cerr << "Error parsing data for id " << objId << ": " << e.what() << endl;
        }
    }

    int add_new_object(const int &parentId)
    {
        id = get_new_id(fileName);
        if (id == -1 || id == 0)
        {
            cerr << "Can't add new Floor" << endl;
            return id;
        }

        buildingId = parentId;
        Buildings building;
        int maxHeight = 0;
        char choice;
        int roomsAdded = 0;

        if (buildingId != building.id)
        {
            building.get_object_by_id(buildingId);
        }

        switch (building.type)
        {
        case buildingsTypes::garage:
        case buildingsTypes::barn:
        {
            level = 1;
            maxHeight = 5;
            break;
        }
        case buildingsTypes::house:
        case buildingsTypes::bathhouse:
        {
            do
            {
                cout << "Input floor level:" << endl;
                cin >> level;
            } while (has_input_error() || is_floor_level_exist());

            maxHeight = 3;
            break;
        }
        }

        do
        {
            cout << "Input floor height, m " << "(max height " << maxHeight << ")" << endl;
            cin >> height;

            if (height > maxHeight)
            {
                cerr << "max height " << maxHeight << "m" << endl;
            }
            if (height <= 0)
            {
                cerr << "Height cannot have a negative value or be equal 0" << endl;
            }
        } while (has_input_error() || height > maxHeight || height <= 0);

        if (write_to_file())
        {
            cout << "Floor added" << endl;
            return id;
        }
        cerr << "Can't write object data to the file" << endl;
        return -2;
    }
};

struct Rooms
{
public:
    const string fileName = "rooms.csv";
    int id;
    int floorId;
    roomsTypes type;
    double area;

private:
    string room_type_to_string()
    {
        switch (type)
        {
        case roomsTypes::bedroom:
            return "bedroom";
        case roomsTypes::kitchen:
            return "kitchen";
        case roomsTypes::bathroom:
            return "bathroom";
        case roomsTypes::childrens_room:
            return "childrens_room";
        case roomsTypes::living_room:
            return "living_room";
        case roomsTypes::steam_room:
            return "steam_room";
        case roomsTypes::relaxation_room:
            return "relaxation_room";
        case roomsTypes::washroom:
            return "washroom";
        case roomsTypes::non_residential_premise:
            return "non_residential_premise";
        default:
            return "unknown";
        }
    }

    roomsTypes string_to_room_type(const string &str)
    {
        if (str == "bedroom")
            return roomsTypes::bedroom;
        if (str == "kitchen")
            return roomsTypes::kitchen;
        if (str == "bathroom")
            return roomsTypes::bathroom;
        if (str == "childrens_room")
            return roomsTypes::childrens_room;
        if (str == "living_room")
            return roomsTypes::living_room;
        if (str == "steam_room")
            return roomsTypes::steam_room;
        if (str == "relaxation_room")
            return roomsTypes::relaxation_room;
        if (str == "washroom")
            return roomsTypes::washroom;
        if (str == "non_residential_premise")
            return roomsTypes::non_residential_premise;

        return roomsTypes::living_room;
    }

    bool write_to_file()
    {
        ofstream dataFile(path + fileName, ios::app);
        if (!dataFile.is_open())
        {
            cerr << "Error. Can't write to" << "'rooms.csv'" << endl;
            return false;
        }
        string typeStr = room_type_to_string();
        dataFile << id << "," << floorId << "," << typeStr << "," << area;
        dataFile.close();
        return true;
    }

public:
    double calc_total_rooms_area_by_floorId(const int &floorId)
    {
        string str;
        double totalRoomsArea = 0.00;
        streampos currentPos = 0;
        while (true)
        {
            str = get_string_from_file_by_parentId(floorId, currentPos, fileName);

            if (str == "NOT_FOUND")
            {
                break;
            }
            if (str == "FILE_NOT_FOUND")
            {
                cerr << "File not found: " << fileName << endl;
                break;
            }

            stringstream ss(str);
            string field;
            for (int i = 0; getline(ss, field, ','); i++)
            {
                if (i == 3)
                {
                    try
                    {
                        totalRoomsArea += stod(field);
                        break;
                    }
                    catch (const exception &e)
                    {
                        cerr << "Error parsing area: '" << field << "': " << e.what() << endl;
                    }
                }
            }
        }
        return totalRoomsArea;
    }

    void get_object_by_id(const int &objId)
    {
        string data = get_string_from_file_by_id(objId, fileName);
        if (data == "NOT_FOUND" || data == "FILE_NOT_FOUND")
        {
            cerr << "Object with id " << objId << " not found" << endl;
            return;
        }
        string field;
        stringstream ss(data);
        try
        {
            if (!getline(ss, field, ','))
                return;
            id = stoi(field);
            if (!getline(ss, field, ','))
                return;
            type = string_to_room_type(field);
            if (!getline(ss, field, ','))
                return;
            area = stod(field);
        }
        catch (const exception &e)
        {
            cerr << "Error parsing data for id " << objId << ": " << e.what() << endl;
        }
    }

    int add_new_object(const int &parentId)
    {
        id = get_new_id(fileName);
        if (id == -1 || id == 0)
        {
            cerr << "Can't add new Room" << endl;
            return id;
        }

        floorId = parentId;
        int choice;
        Floors floor;
        floor.get_object_by_id(floorId);
        Buildings building;
        cout << floor.id << endl;
        cout << floor.buildingId << endl;
        building.get_object_by_id(floor.buildingId);

        double areaLimitForRoom = building.area - calc_total_rooms_area_by_floorId(floorId);

        switch (building.type)
        {
        case buildingsTypes::garage:
        case buildingsTypes::barn:
        {
            choice = 9;
            break;
        }
        case buildingsTypes::house:
        {
            do
            {
                cout << "Choose room type:'" << endl;
                cout << "1 - bedroom" << endl;
                cout << "2 - kitchen" << endl;
                cout << "3 - bathroom" << endl;
                cout << "4 - childrens room" << endl;
                cout << "5 - living room" << endl;
                cin >> choice;
            } while (has_input_error() || choice < 1 || choice > 5);
            break;
        }
        case buildingsTypes::bathhouse:
        {
            do
            {
                cout << "Choose room type:'" << endl;
                cout << "1 - steam room" << endl;
                cout << "2 - relaxation room" << endl;
                cout << "3 - washroom" << endl;
                cin >> choice;
            } while (has_input_error() || choice < 1 || choice > 3);
            choice += 5;
            break;
        }
        }
        switch (choice)
        {
        case 1:
            type = roomsTypes::bedroom;
            break;
        case 2:
            type = roomsTypes::kitchen;
            break;
        case 3:
            type = roomsTypes::bathroom;
            break;
        case 4:
            type = roomsTypes::childrens_room;
            break;
        case 5:
            type = roomsTypes::living_room;
            break;
        case 6:
            type = roomsTypes::steam_room;
            break;
        case 7:
            type = roomsTypes::relaxation_room;
            break;
        case 8:
            type = roomsTypes::washroom;
            break;
        case 9:
            type = roomsTypes::non_residential_premise;
            break;
        }
        do
        {
            cout << "Input room area:'" << endl;
            cin >> area;
            if (area > areaLimitForRoom)
            {
                cerr << "Room is too large, max: " << areaLimitForRoom << "m2" << endl;
            }
            if (area <= 0)
            {
                cerr << "Area cannot have a negative value or be equal 0" << endl;
            }
        } while (has_input_error() || area > areaLimitForRoom || area <= 0);

        if (write_to_file())
        {
            cout << "Room added" << endl;
            return id;
        }
        cerr << "Can't write object data to the file" << endl;
        return -2;
    }
};

int main()
{
    Plots plot;
    Buildings building;
    Floors floor;
    Rooms room;
    unsigned int parentId = 0;
    int newId = 0;

    while (true)
    {
        switch (get_user_command())
        {
        case 1:
            newId = plot.add_new_object();
            cout << "Plot Id: " << newId << endl;
            break;
        case 2:
            do
            {
                cout << "Input Plot ID" << endl;
                cin >> parentId;
            } while (has_input_error());
            newId = building.add_new_object(parentId);
            cout << "Building Id: " << newId << endl;
            break;
        case 3:
            do
            {
                cout << "Input Building ID" << endl;
                cin >> parentId;
            } while (has_input_error());
            newId = floor.add_new_object(parentId);
            cout << "Floor Id: " << newId << endl;
            break;
        case 4:
            do
            {
                cout << "Input Floor ID" << endl;
                cin >> parentId;
            } while (has_input_error());
            newId = room.add_new_object(parentId);
            cout << "Room Id: " << newId << endl;
            break;
        case 0:
            cout << "Goodbye!" << endl;
            return 0;
        }
    }
    return 0;
}