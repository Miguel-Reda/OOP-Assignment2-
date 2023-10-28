#include <stdio.h>
#include <iostream>
#include "BigReallib.h"

using namespace std;

bool BigReal:: isValid(string num) {
    return (regex_match (num, regex("[+-]?\\d*\\.?\\d*")));
}

