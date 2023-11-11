#include "MLS.h"
#include <iomanip>
#include <cmath>
using namespace std;

void Memory::loadFile(std::string fileName)
{
    ifstream fetch(fileName);

    if (fetch.fail())
    {
        cout << "Error" << '\n';
        return;
    }
    int x1, x2, x3, i(0);
    while (fetch >> hex >> x1 >> x2 >> x3)
    {

        if (i > 254)
            break;
        memory[i] = (x1 << 4) + x2;
        memory[i + 1] = x3;

        i += 2;
    }
}
void Memory::show()
{
    for (int i = 0; i < 256; i += 4)
    {
        for (int j = i; j < i + 4; ++j)
        {

            cout << setw(2) << setfill('0') << hex << uppercase << (int)memory[j] << '\t';
        }
        cout << '\n';
    }
}

void Memory::setData(int index, int bitPattern)
{
    memory[index] = bitPattern;
}
void Memory::reset()
{
    fill(memory, memory + 256, 0);
};

uint8_t Memory::getData(int index)
{
    return memory[index];
}

int8_t Register::getData(int index)
{
    return registers[index];
}

void Register::setData(int index, int bitPattern)
{
    registers[index] = bitPattern;
}

void Register::reset()
{
    fill(registers, registers + 16, 0);
}

void Register::show()
{
    for (int i = 0; i < 16; i += 2)
    {
        for (int j = i; j < i + 2; ++j)
        {

            cout << setw(2) << setfill('0') << hex << uppercase << (int)registers[j] << '\t';
        }
        cout << '\n';
    }
}
int8_t Register::add(int index, int index2)
{
    return registers[index] + registers[index2];
}

void Machine::reset()
{
    PC = 0;
    IR = 0;
    registers.reset();
    memory.reset();
}

void Machine::show()
{
    cout << "PC: " << PC << " \n";
    cout << "IR: " << IR << '\n';
    registers.show();
    memory.show();
}

int Memory::getInstruction(int index)
{

    return ((memory[index] << 8) + memory[index + 1]);
}

void Machine::mloadFile()
{
    cout << "Enter file name: ";
    string fileName;
    cin >> fileName;
    memory.loadFile(fileName);
}

string Machine::int_to_Binary(string s, int n)
{
    if (n > 0)
    {
        int_to_Binary(s, n / 2); // Recursive call with the quotient of n divided by 2.
        if (n % 2 == 0)
        {
            s.push_back('0'); // If n is even, add '0' to the binary representation string.
        }
        else
        {
            s.push_back('1'); // If n is odd, add '1' to the binary representation string.
        }
    }
    cout << s; // Print the binary representation.
    return string();
}

float Machine::floating_point_to_int(string s)
{
    int exp = ((s[1] - '0') * 4 + (s[2] - '0') * 2 + (s[3] - '0') * 1) - 4;
    float r;
    if (exp == -4)
    {
        r = (s[4] - '0') / 32.0 + (s[5] - '0') / 64.0 + (s[6] - '0') / 128.0 + (s[7] - '0') / 256.0;
    }
    else if (exp == -3)
    {
        r = (s[4] - '0') / 16.0 + (s[5] - '0') / 32.0 + (s[6] - '0') / 64.0 + (s[7] - '0') / 128.0;
    }
    else if (exp == -2)
    {
        r = (s[4] - '0') / 8.0 + (s[5] - '0') / 16.0 + (s[6] - '0') / 32.0 + (s[7] - '0') / 64.0;
    }
    else if (exp == -1)
    {
        r = (s[4] - '0') / 4.0 + (s[5] - '0') / 8.0 + (s[6] - '0') / 16.0 + (s[7] - '0') / 32.0;
    }
    else if (exp == 0)
    {
        r = (s[4] - '0') / 2.0 + (s[5] - '0') / 4.0 + (s[6] - '0') / 8.0 + (s[7] - '0') / 16.0;
    }
    else if (exp == 1)
    {
        r = (s[4] - '0') + (s[5] - '0') / 2.0 + (s[6] - '0') / 4.0 + (s[7] - '0') / 8.0;
    }
    else if (exp == 2)
    {
        r = (s[4] - '0') * 2 + (s[5] - '0') + (s[6] - '0') / 2.0 + (s[7] - '0') / 4.0;
    }
    else if (exp == 3)
    {
        r = (s[4] - '0') * 4 + (s[5] - '0') * 2 + (s[6] - '0') + (s[7] - '0') / 2.0;
    }

    return r;
}

bool Machine::isValidCommand(int IR)
{
    if (((0x1000 <= IR) & (IR < 0x7000)) || ((0xB000 <= IR) & (IR <= 0xC000)))
    {
        return true;
    }
    return false;
}

void Machine::exec()
{

    IR = memory.getInstruction(PC);
    if (!isValidCommand(IR))
    {
        cout << "some instructions arent valid \n";
        return;
    }
    PC += 2;
    int op = (IR >> 12);
    int R = (IR >> 8) & (0xF);
    int XY = (IR) & (0xFF);
    int r = (XY >> 4);
    int s = (XY) & (0xF);
    if (op == 1)
    {
        /*registers[R] = memory[XY];*/
        registers.setData(R, memory.getData(XY));
    }
    else if (op == 2)
    {

        /*registers[index] = bitpattern;*/
        registers.setData(R, XY);
    }
    if (op == 3)
    {
        if (XY == 0)
        {
            cout << registers.getData(R);
        }
        memory.setData(XY, registers.getData(R));
    }
    if (op == 4)
    {
        if (R)
        {
            cout << "not valid command \n";
            return;
        }
        registers.setData(s, registers.getData(r));
    }
    if (op == 5)
    {
        registers.setData(R, registers.add(r, s));
    }
    // if (op == 6){}
    if (op == 11)
    {
        if (registers.getData(R) == registers.getData(0))
            PC = XY;
    }
    if (op == 12)
    {
        return;
    }
    exec();
}
