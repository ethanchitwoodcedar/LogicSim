#include "Wire.h"
#include "Gate.h"
#include <iostream>

Wire::Wire(int v = -1, std::string n = "new", int i = 0) {
    name = n;
    index = i;
    value = v;
}

int Wire::getValue() const {
    return value;
}

std::string Wire::getName() const {
    return name;
}

int Wire::getIndex() const {
    return index;
}

std::vector<int> Wire::getHistory() const {
    return history;
}

std::vector<Gate*> Wire::getDrives() const {
    return drives;
}

void Wire::printHistory() const {
    /* Currently implemented for a console application. */
    for (int i = 0; i < history.size(); i++) {
        std::cout << history.at(i);
    }
}

void Wire::setValue(int v) {
    /* Automatically enters value in the history vector. */
    history.push_back(value);
    value = v;
}

void Wire::setName(std::string n) {
    name = n;
}

void Wire::setIndex(int i) {
    index = i;
}

void Wire::addDrive(Gate* gate) {
    drives.push_back(gate);
}