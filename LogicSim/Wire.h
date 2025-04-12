#pragma once

#include <vector>
#include <string>

class Gate;

class Wire
{
private:
    int value;
    /*
        wire states are as follows:
        0 - 0 or off
        1 - 1 or on
       -1 - X or unknown/undefined
    */

    std::string name;
    std::vector<Gate*> drives;
    int index;
    std::vector<int> history;
    /*history includes past values, not including the current value.*/

public:
    //Constructor
    Wire(int v, std::string n, int i);
    //Getters
    int getValue() const;
    std::string getName() const;
    int getIndex() const;
    std::vector<int> getHistory() const;
    std::vector<Gate*> getDrives() const;
    void printHistory() const;
    //Setters
    void setValue(int v);
    void setName(std::string n);
    void setIndex(int i);
    void addDrive(Gate*);
};
