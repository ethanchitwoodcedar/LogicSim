#pragma once

class Wire;

class Gate
{
private:
    int type;
    /*Gate types are as follows:
        AND 0
        OR 1
        XOR 2
        NAND 3
        NOR 4
        XNOR 5  
        NOT 6*/
    int gateDelay;
    Wire* input1;
    Wire* input2;
    Wire* output;
    int AND(int time) const;
    int OR(int time) const;
    int XOR(int time) const;
    int NAND(int time) const;
    int NOR(int time) const;
    int XNOR(int time) const;
    int NOT(int time) const;
public:
    Gate(int, int, Wire*, Wire*, Wire*);
    int getDelay() const { return gateDelay; }
    Wire* getInput(int inputNum) const { return (inputNum == 0) ? input1 : input2; }
    Wire* getOutput() const { return output; }
    int evaluate(int time) const; // 1 is true. 0 is false. -1 is undefined.
};

