#include "Gate.h"
#include "Wire.h"

int Gate::AND() const
{
    int a = input1->getValue();
    int b = input2->getValue();
    int out;
    if (a != -1 && b != -1) {
        out = a * b;
    }
    else {
        out = -1;
    }
    return out;
}

int Gate::OR() const
{
    int a = input1->getValue();
    int b = input2->getValue();
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

int Gate::XOR() const
{
    int a = input1->getValue();
    int b = input2->getValue();
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

int Gate::NAND() const
{
    int in = AND();
    if (in == -1) {
        return -1;
    }
    return (in == 1) ? 0 : 1;
}

int Gate::NOR() const
{
    int in = OR();
    if (in == -1) {
        return -1;
    }
    return (in == 1) ? 0 : 1;
}

int Gate::XNOR() const
{
    int in = XOR();
    if (in == -1) {
        return -1;
    }
    return (in == 1) ? 0 : 1;
}

//Public members below.

Gate::Gate(int newType, int newGateDelay, Wire* newInput1, Wire* newInput2, Wire* newOutput)
{
    type = newType;
    gateDelay = newGateDelay;
    input1 = newInput1;
    input2 = newInput2;
    output = newOutput;
}

int Gate::evaluate() const
{
    switch (type)
    {
    case 0:
        return AND();
    case 1:
        return OR();
    case 2:
        return XOR();
    case 3:
        return NAND();
    case 4:
        return NOR();
    case 5:
        return XNOR();
    default:
        return -99;
    }

}