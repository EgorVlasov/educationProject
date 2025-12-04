#include <iostream>
#include "operationtools.h"
#include "userinterface.h"

using namespace std;

void scalpel(OperationStatus &newAction)
{
    if (newAction.isCuted == false)
    {
        cout << "Enter x coordinate: " << endl;
        newAction.cutPointX = get_coordinate();

        cout << "Enter y coordinate: " << endl;
        newAction.cutPointY = get_coordinate();

        if (newAction.cutPointX >= newAction.cutPointY)
        {
            cerr << "Error: x coordinate must be less than y coordinate" << endl;
            return;
        }

        float cutLength = newAction.cutPointY - newAction.cutPointX;
        newAction.isCuted = true;

        cout << "Cut was made from point " << newAction.cutPointX
             << " to point " << newAction.cutPointY << endl;
        cout << "Length of the cut: " << cutLength << endl;
    }
    else
    {
        cerr << "Error. Cut has been already made" << endl;
    }
}

void hemostat(OperationStatus &newAction)
{
    if (!newAction.isCuted)
    {
        cerr << "Error. Cut wasn't made. You can't use hemostat" << endl;
        return;
    }

    cout << "Enter x coordinate for hemostat: " << endl;
    float x = get_coordinate();

    if (x >= newAction.cutPointX && x <= newAction.cutPointY)
    {
        cout << "Hemostat was applied at the point: " << x << endl;
    }
    else
    {
        cerr << "Error. Interaction point is out of cut" << endl;
    }
}

void tweezers(OperationStatus &newAction)
{
    if (!newAction.isCuted)
    {
        cerr << "Error. Cut wasn't made. You can't use tweezers" << endl;
        return;
    }

    cout << "Enter x coordinate for tweezers: " << endl;
    float x = get_coordinate();

    if (x >= newAction.cutPointX && x <= newAction.cutPointY)
    {
        cout << "Tweezers were applied at the point: " << x << endl;
    }
    else
    {
        cerr << "Error. Interaction point is out of cut" << endl;
    }
}

void suture(OperationStatus &newAction)
{
    if (!newAction.isCuted)
    {
        cerr << "Error. Cut wasn't made. You can't use suture" << endl;
        return;
    }

    cout << "Enter start x coordinate for suture: " << endl;
    float x = get_coordinate();

    cout << "Enter end y coordinate for suture: " << endl;
    float y = get_coordinate();

    if (x == newAction.cutPointX && y == newAction.cutPointY)
    {
        newAction.isCuted = false;
        newAction.isSutured = true;
        cout << "Suture successfully applied from point " << x << " to point " << y << endl;
        cout << "Operation completed!" << endl;
    }
    else
    {
        cerr << "Error. Suture points do not match the cut points." << endl;
        cerr << "Expected: " << newAction.cutPointX << " to " << newAction.cutPointY << endl;
        cerr << "Got: " << x << " to " << y << endl;
    }
}