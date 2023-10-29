#include <iostream>
#include <string>
#define ll long long

using namespace std;
class BigReal
{
private:
  string Big_Real;

public:
  int Decimal_Size;
  bool isValidReal(string realNumber);    // True if correct real
  BigReal(double realNumber /* = 0.0 */); // Default constructor
  BigReal(string realNumber = "0.0");     // Initialize from string
  BigReal(const BigReal &other);          // Copy constructor
  BigReal &operator=(BigReal &other);     // Assignment operator
  // Depending on how you store data, default can be enough
  void setNum(string realNumber);
  int size();
  int sign();

  BigReal operator+(BigReal &other);
  BigReal operator-(BigReal &other);

  int DecimalSize();
  bool operator<(BigReal Big_Real_2);
  bool operator>(BigReal Big_Real_2);
  bool operator==(BigReal Big_Real_2);
  bool operator!=(BigReal Big_Real_2);

  friend ostream &operator<<(ostream &out, BigReal num);
};
