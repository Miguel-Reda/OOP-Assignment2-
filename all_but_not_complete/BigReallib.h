

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
    BigReal(const BigReal &other);          // Copy constructor
    BigReal &operator=(const BigReal &other);     // Assignment operator
    // Depending on how you store data, default can be enough
    void setNum(string realNumber);

    int size();

    int sign();


    friend BigReal operator+(BigReal first, BigReal other);

    BigReal operator-(BigReal other);

    int DecimalSize();

    bool operator<(BigReal Big_Real_2);

    bool operator>(BigReal Big_Real_2);

    bool operator==(BigReal Big_Real_2);

    bool operator!=(BigReal Big_Real_2);

    friend ostream &operator<<(ostream &out, BigReal num);
};

