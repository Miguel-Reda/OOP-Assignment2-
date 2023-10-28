#include <iostream>
#include <string>
using namespace std;
class BigReal
{
private:
  string Big_Real;

public:
  bool isValidReal(string realNumber); // True if correct real
  BigReal();
  BigReal(double realNumber = 0.0);   // Default constructor
  BigReal(string realNumber);         // Initialize from string
  BigReal(const BigReal &other);      // Copy constructor
  BigReal &operator=(BigReal &other); // Assignment operator
  // Depending on how you store data, default can be enough
  void setNum(string realNumber);
  int size();
  int sign();

  BigReal operator+(BigReal &other);
  BigReal operator-(BigReal &other);

  bool operator<(BigReal anotherReal);
  bool operator>(BigReal anotherReal);
  bool operator==(BigReal anotherReal);
  bool operator!=(BigReal anotherReal);
  friend ostream &operator<<(ostream &out, BigReal num);
};
