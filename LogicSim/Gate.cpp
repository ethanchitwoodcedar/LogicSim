#include "Gate.h"
#include "Wire.h"

int Gate::AND(int time) const
{
    int a = input1->getHistory().at(time);
    int b = input2->getHistory().at(time);
    int out;
    if (a == 1 && b == 1) {
        out = 1;
    }
    else if (a == 0 || b == 0) {
        out = 0;
    }
    else {
        out = -1;
    }
    return out;
}

int Gate::OR(int time) const
{
    int a = input1->getHistory().at(time);
    int b = input2->getHistory().at(time);
    int out;
    if (a == -1 && b == -1) {
        out = -1;
    }
    else if ((a == 1) || (b == 1)) {
        out = 1;
    }
    else if ((a == 0) && (b == 0)) {
        out = 0;
    }
    else {
        out = -1;
    }
    return out;
}

int Gate::XOR(int time) const
{
    int a = input1->getHistory().at(time);
    int b = input2->getHistory().at(time);
    int out;
    if (a == -1 || b == -1) {
        out = -1;
    }
    else if ((a == 1) && (b == 1)) {
        out = 0;
    }
    else if ((a == 1) || (b == 1)) {
        out = 1;
    }
    else {
        out = 0;
    }
    return out;
}

int Gate::NAND(int time) const
{
    int in = AND(time);
    if (in == -1) {
        return -1;
    }
    return (in == 1) ? 0 : 1;
}

int Gate::NOR(int time) const
{
    int in = OR(time);
    if (in == -1) {
        return -1;
    }
    return (in == 1) ? 0 : 1;
}

int Gate::XNOR(int time) const
{
    int in = XOR(time);
    if (in == -1) {
        return -1;
    }
    return (in == 1) ? 0 : 1;
}

int Gate::NOT(int time) const
{
    int a = input1->getHistory().at(time);

    if (a == -1) {
        return -1;
    }

    return (a == 1) ? 0 : 1;
}

//Public members below.

Gate::Gate(int newType, int newGateDelay, Wire* newInput1, Wire* newInput2, Wire* newOutput)
{
    type = newType;
    gateDelay = newGateDelay;
    input1 = newInput1;
    if (type == 6) {
        input2 = newInput1;
    }
    else {
        input2 = newInput2;
    }
    output = newOutput;
}

int Gate::evaluate(int time) const
{
    switch (type)
    {
    case 0:
        return AND(time);
    case 1:
        return OR(time);
    case 2:
        return XOR(time);
    case 3:
        return NAND(time);
    case 4:
        return NOR(time);
    case 5:
        return XNOR(time);
    case 6:
        return NOT(time);
    default:
        return -99;
    }

}
