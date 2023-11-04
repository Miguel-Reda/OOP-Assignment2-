#include <iostream>
#include <string>
#define ll long long

using namespace std;
class BigReal
{
private:
  string Big_Real;
  int number_sign;
  string formattedReal(string realNumber);
  bool isValidReal(string realNumber); // True if correct real

public:
  int Decimal_Size;
  BigReal(double realNumber);                // Initialize double
  BigReal(string realNumber = "0.0");        // Default constructor
  BigReal(const BigReal &other);             // Copy constructor
  BigReal &operator=(const BigReal &other);  // Assignment operator
  void setNum(string realNumber);
  void setNum(double realNumber);
  int size();
  int sign();

  BigReal operator+(BigReal other);
  BigReal operator-(BigReal other);

  int DecimalSize();
  bool operator<(BigReal Big_Real_2);
  bool operator>(BigReal Big_Real_2);
  bool operator==(BigReal Big_Real_2);
  bool operator!=(BigReal Big_Real_2);
  friend ostream &operator<<(ostream &out, BigReal Real);
  friend istream &operator>>(istream &in, BigReal &Real);
};
