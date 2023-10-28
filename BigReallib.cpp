#include <stdio.h>
#include <iostream>
#include <regex>
#include "BigReallib.h"

using namespace std;

bool BigReal:: isValidReal(string realNumber) {
    return (regex_match (realNumber, regex("[+-]?\\d*\\.?\\d*")));
}

BigReal(){
    BigNum = "0.0";
}

BigReal(string realNumber){
    if(isValidReal(realNumber)){
        BigNum = realNumber;
    }
    else{
        cout << "invalid number";
    }
}

BigReal(const BigReal& other){ //Copy Constructor
    BigNum = other.BigNum;
}

BigReal &operator=(BigReal &other){ //Assignment Operator
    BigNum = other.BigNum;
    return other;
}

int sign()
{
    if(isdigit(BigNum[0]) ||  BigNum[0] == '+' || BigNum[0] == '.')
    {
        return 1;  //returns 1 as a positive value
    }
    else
    {
        return -1; //returns -1 as a negative value
    }
}



