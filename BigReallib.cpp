#include <stdio.h>
#include <iostream>
#include <regex>
#include "BigReallib.h"

using namespace std;

bool BigReal:: isValidReal(string realNumber) {
    return (regex_match (realNumber, regex("[+-]?\\d*\\.?\\d*")));
}

