#include "MLS.h"
#include <iomanip>
using namespace std;

void Memory::loadFile(std::string fileName) {
    ifstream fetch(fileName);

    if (fetch.fail()){
        cout << "Error" << '\n';
        return;
    }
    int x1,x2,x3,i(0);
    while(fetch >> hex >> x1 >> x2 >> x3){

        if (i > 254) break;
        memory[i] = (x1 << 4) + x2;
        memory[i+1] = x3;

        i +=2 ;

    }

}
void Memory::show() {
    for (int i = 0; i < 256; i += 4) {
        for (int j = i; j < i + 4; ++j) {

            cout << setw(2) << setfill('0') << hex << uppercase << (int) memory[j] << '\t';
        }
        cout << '\n';
    }
}

void Memory::setData(int index, int bitPattern) {
    memory[index] = bitPattern;

}
void Memory::reset(){
    fill(memory,memory + 256,0);
};

uint8_t Memory::getData(int index) {
    return memory[index];
}

int8_t Register::getData(int index) {
    return registers[index];
}

void Register::setData(int index, int bitPattern) {
    registers[index] = bitPattern;
}

void Register::reset() {
    fill(registers,registers + 16 , 0);
}

void Register::show() {
    for (int i = 0; i < 16; i += 2) {
        for (int j = i; j < i + 2; ++j) {

            cout << setw(2) << setfill('0') << hex << uppercase << (int) registers[j] << '\t';
        }
        cout << '\n';
    }
}
int8_t Register::add(int index, int index2) {
    return registers[index] + registers[index2];
}

void Machine::reset() {
    PC = 0; IR = 0;
    registers.reset();
    memory.reset();
}

void Machine::show() {
    cout << "PC: " << PC << " \n";
    cout << "IR: " << IR << '\n';
    registers.show();
    memory.show();
}

void Machine::exec() {
    int op;
    cin >> op;
    if (op == 1){
        int index,index2;
        registers[index] = memory[index2];
    }
    if (op == 2){
        int index,bitpattern;
        registers[index] = bitpattern;
    }
    if (op == 3){
        int rindex,mindex;
        if (mindex == 0){
            cout << registers[rindex];
        }
        else{
            memory[mindex] = registers[rindex];
        }


    }
    if (op == 4){
        int index1,index2;
        registers[index2] = registers[index1];
        registers[index1]= 0;
    }
    if (op == 5){
        int res_index,index1,index2;
        registers[res_index] = registers.add(index1,index2);
    }
    if (op == 6){}
    if (op == 11){}
    /*if (op == 12){}*/

}






