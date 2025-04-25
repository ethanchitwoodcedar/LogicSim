#include "Gate.h"
#include "Wire.h"
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <vector>
#include "Event.h"

using namespace std;

/* LoadGate creates a new gate from a definition in cricuitIn.
   Additionaly if a wire in that definition does not exist the function will
   create a new wire and add it to the wires map.*/
Gate* loadGate(ifstream& circuitIn, map<int, Wire*>& wires, int type) {
    string dump;
    int delay;
    int input1;
    int input2;
    int output;
    Gate* newGate;

    circuitIn >> delay >> dump >> input1 >> input2 >> output;

    if (wires.find(input1) == wires.end()) {
        wires.emplace(input1, new Wire(-1, "internalWire", input1));
    }
    if (wires.find(input2) == wires.end()) {
        wires.emplace(input2, new Wire(-1, "internalWire", input2));
    }
    if (wires.find(output) == wires.end()) {
        wires.emplace(output, new Wire(-1, "internalWire", output));
    }

    newGate = new Gate(type, delay, wires.at(input1), wires.at(input2), wires.at(output));
    wires.at(input1)->addDrive(newGate);
    wires.at(input2)->addDrive(newGate);
    return newGate;
}

void parseFiles(vector<Gate*>& gates, map<int, Wire*>& wires, queue<Event*>& events, string& circuitName, vector<Wire*>& outputs) {
    ifstream circuitIn;
    ifstream vectorIn;
    string filename;
    string input;
    int key;
    int A;
    int B;

    do {
        cout << "Please enter the name of the file (base name only) : ";
        cin >> filename;
        circuitIn.open((filename + ".txt").c_str());
        vectorIn.open((filename + "_v.txt").c_str());
        if (!(circuitIn && vectorIn)) {
            cout << "Error: could not open file\n";
        }
    } while (!(circuitIn && vectorIn));

    circuitIn >> input >> circuitName;

    while (!circuitIn.eof()) {
        //TODO: parse cricuit file.
        circuitIn >> input;
        if ("INPUT" == input) {
            circuitIn >> input;
            circuitIn >> A;
            wires.emplace(A, new Wire(-1, input, A));
        }
        else if ("OUTPUT" == input) {
            circuitIn >> input;
            circuitIn >> A;
            wires.emplace(A, new Wire(-1, input, A));
            outputs.push_back(new Wire(-1, input, A));
        }
        else if ("AND" == input) {
            gates.push_back(loadGate(circuitIn, wires, 0));
        }
        else if ("OR" == input) {
            gates.push_back(loadGate(circuitIn, wires, 1));
        }
        else if ("XOR" == input) {
            gates.push_back(loadGate(circuitIn, wires, 2));
        }
        else if ("NAND" == input) {
            gates.push_back(loadGate(circuitIn, wires, 3));
        }
        else if ("NOR" == input) {
            gates.push_back(loadGate(circuitIn, wires, 4));
        }
        else if ("XNOR" == input) {
            gates.push_back(loadGate(circuitIn, wires, 5));
        }
        else if ("NOT" == input) {
            gates.push_back(loadGate(circuitIn, wires, 6));
        }
    }

    vectorIn >> input;
    vectorIn >> input;


    while (!vectorIn.eof()) {
        vectorIn >> input;
        vectorIn >> input;
        vectorIn >> A;
        vectorIn >> B;
        // Find key corrisponding to wire name
        for (map<int, Wire*>::iterator itr = wires.begin(); itr != wires.end(); itr++) {
            if (itr->second->getName() == input) {
                key = itr->first;
            }
        }
        events.push(new Event(key, A, B));
    }

    circuitIn.close();
    vectorIn.close();
}

Gate* getGate(Wire* wire, vector<Gate*> list) {
    for (int i = 0; i < list.size(); i++) {
        if (list.at(i)->getOutput() == wire) {
            return list.at(i);
        }
    }
    return nullptr;
}

void evaluteAll(Wire* wire, queue<Event*> events, map<int, Wire*> wires) {
    for (int t = 0; t < 60; t++) {
        while (events.front()->getTime() == t) {
            wires.at(events.front()->getKey())->setValue(events.front()->getValue());
            events.pop();
        }
    }
}

void simulate(Wire* wire, vector<Gate*> list, queue<Event*> events) {
    
    for (int time = 0; time < 60; time++) {
        // TODO: empliment simulation.
        // Update input wires
         
    }
}

void print(map<int, Wire*>& wires, string circuitName) {
    cout << endl << circuitName << endl << endl;
    cout << "------------------------------";
    cout << "------------------------------\n";
    for (auto itr : wires) {
        cout << itr.second->getName() << " ";
        itr.second->printHistory();
        cout << endl;
    }
    cout << "------------------------------";
    cout << "------------------------------\n";
}

int main(int argc, char* argv[]) 
{
    string circuitName;
    map<int, Wire*> wires;
    vector<Gate*> gates;
    vector<Wire*> outputs;
    queue<Event*> events;
   
    parseFiles(gates, wires, events, circuitName, outputs);

    simulate(gates, wires, events);

    print(wires, circuitName);

    return 0;
}