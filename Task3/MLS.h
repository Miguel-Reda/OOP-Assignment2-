#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Register
{
private:
    int8_t registers[16] = {0};

public:
    void setData(int index, int bitPattern); // setter
    int8_t getData(int index);
    void reset();
    void show();
    int8_t add(int index, int index2);
    int add2(int index, int index2);
};

class Memory
{
private:
    uint8_t memory[256] = {0};

public:
    void setData(int index, int bitPattern); // setter
    void loadFile(string fileName);
    uint8_t getData(int index);
    void reset();
    void show();
    int getInstruction(int index);
};

class Machine
{
private:
    Memory memory;
    Register registers;
    int PC = 0;
    int IR = 0;

public:
    string int_to_Binary(string s,int n);
    float floating_point_to_int(int n);
    bool isValidCommand(int IR);
    void exec();
    void reset();
    void show();
    void mloadFile();
};
