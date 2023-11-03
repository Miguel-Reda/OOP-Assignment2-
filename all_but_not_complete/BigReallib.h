

#include <iostream>
#include <string>

#define ll long long

using namespace std;

class BigReal {
private:
    string Big_Real;

    string formattedReal(string realNumber);

    bool isValidReal(string realNumber);    // True if correct real
    int number_sign;

public:

    int Decimal_Size;

    BigReal(double realNumber /* = 0.0 */); // Default constructor
    BigReal(string realNumber = "0.0");     // Initialize from string

    BigReal &operator=(const BigReal &other);     // Assignment operator



    int size();

    int sign();

    BigReal operator+ (BigReal other);

    BigReal operator-(BigReal other);

    int DecimalSize();

    bool operator<(BigReal Big_Real_2);

    bool operator>(BigReal Big_Real_2);

    bool operator==(BigReal Big_Real_2);

    bool operator!=(BigReal Big_Real_2);

    friend ostream &operator<<(ostream &out, BigReal num);
};

