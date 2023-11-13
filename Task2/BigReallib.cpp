#include <stdio.h>
#include <iostream>
#include <regex>
#include <string>
#include "BigReallib.h"
#define ll long long
using namespace std;

bool BigReal::isValidReal(string realNumber)
{
  return (regex_match(realNumber, regex("[+-]?\\d*\\.?\\d*")));
}

BigReal::BigReal(string realNumber)
{
  if (isValidReal(realNumber))
  {
    if (realNumber[0] != '-')
    {
      number_sign = 1; // returns 1 as a positive value
    }
    else
    {

      number_sign = -1; // returns -1 as a negative value
    }
    Big_Real = formattedReal(realNumber);
  }
  else
  {
    cout << "invalid number\n";
    Big_Real = "0.0";
    number_sign = 1;
  }
}

BigReal::BigReal(double realNumber)
{
  string number = to_string(realNumber);

  if (number[0] != '-')
  {
    number_sign = 1; // returns 1 as a positive value
  }
  else
  {
    number_sign = -1; // returns -1 as a negative value
  }
  Big_Real = formattedReal(number);
}

BigReal::BigReal(const BigReal &other)
{ // Copy Constructor
  Big_Real = other.Big_Real;
  number_sign = other.number_sign;
}

int BigReal::size() // gets the size of the given number
{
  return Big_Real.size();
}

BigReal &BigReal::operator=(const BigReal &other)
{ // Assignment Operator
  Big_Real = other.Big_Real;
  this->number_sign = other.number_sign;
  return *this;
}

int BigReal::sign()
{
  return number_sign;
}

int BigReal::DecimalSize()
{
  int Decimal_Size;
  Decimal_Size = Big_Real.find('.');
  return Decimal_Size;
}

string BigReal::formattedReal(string realNumber)
{
  string::iterator it = realNumber.begin(), dot;

  if (*it == '-' || *it == '+')
    it++;

  while (it != realNumber.end() && *it == '0')
    it++;

  realNumber.erase(realNumber.begin(), it);

  if (realNumber.empty())
    return "0.0";

  if (realNumber[0] == '.')
    realNumber.insert(0, "0");

  dot = realNumber.begin();
  while (dot != realNumber.end() && *dot != '.')
    dot++;

  if (dot == realNumber.end())
    return realNumber + ".0";

  it = realNumber.end() - 1;
  while (it != dot && *it == '0')
    it--;

  realNumber.erase(it + 1, realNumber.end());

  if (it == dot)
    realNumber.push_back('0');

  return realNumber;
}

BigReal BigReal::operator+(BigReal other)
{
  BigReal result = *this;

  int dotp = result.DecimalSize();
  int dotp2 = other.DecimalSize();
  int frac1 = result.size() - dotp;
  int frac2 = other.size() - dotp2;

  // zero padding
  if (dotp > dotp2)
  {
    other.Big_Real.insert(0, dotp - dotp2, '0');
  }
  else if (dotp2 > dotp)
  {
    result.Big_Real.insert(0, dotp2 - dotp, '0');
  }

  if (frac1 > frac2)
  {
    other.Big_Real.append(frac1 - frac2, '0');
  }
  else if (frac2 > frac1)
  {
    result.Big_Real.append(frac2 - frac1, '0');
  }

  if (result.number_sign * other.number_sign == 1)
  {
    string::reverse_iterator f = result.Big_Real.rbegin();
    string::reverse_iterator o = other.Big_Real.rbegin();
    int carry(0);
    for (; f != result.Big_Real.rend(); f++, o++)
    {
      if (*f == '.')
        continue;
      int sum = ((*f - '0') + (*o - '0')) + carry;
      carry = sum / 10;
      sum %= 10;
      *f = sum + '0';
    }
    if (carry)
      result.Big_Real.insert(0, "1");
    return result;
  }

  else
  {
    bool flag(0);
    if (result.sign() == -1)
    {
      result.number_sign = 1;
      flag = true;
    }
    else
    {
      other.number_sign = 1;
    }
    if (result < other)
    {
      swap(result, other);

      if (!flag)
      {
        result.number_sign = -1;
      }
    }
    else if (!(other < result))
    {

      result.Big_Real = "0.0";
      return result;
    }
    else
    {

      if (flag)
      {
        result.number_sign = -1;
      }
    }
    string::reverse_iterator f = result.Big_Real.rbegin();
    string::reverse_iterator o = other.Big_Real.rbegin();
    int carry(0);
    for (; f != result.Big_Real.rend(); f++, o++)
    {
      if (*f == '.')
        continue;
      int sum = ((*f) - (*o)) - carry;
      if (sum < 0)
      {
        carry = 1;
        sum += 10;
      }
      else
      {
        carry = 0;
      }

      *f = sum + '0';
    }

    result.Big_Real = formattedReal(result.Big_Real);
    return result;
  }
}

BigReal BigReal::operator-(BigReal other)
{
  other.number_sign *= -1;
  return (*this + other);
}

bool BigReal::operator<(BigReal Big_Real_2)
{
  // Check if the signs of the two BigReal numbers are different
  if (sign() != Big_Real_2.sign())
  {
    return (sign() < Big_Real_2.sign());
  }
  // Both numbers have the same sign, so we need to compare them further
  else if (sign() == -1 && Big_Real_2.sign() == -1)
  {
    // Decimal_Size stores the number of decimal digits
    int Decimal_Size = DecimalSize();
    if (Decimal_Size > Big_Real_2.DecimalSize())
    {
      return 1; // Return true if current number has more decimal digits
    }
    else if (Decimal_Size < Big_Real_2.DecimalSize())
    {
      return 0; // Return false if current number has fewer decimal digits
    }
    else
    {
      // Both numbers have the same number of decimal digits, so we need to compare them digit by digit
      for (ll i = 0; i < Decimal_Size; i++)
      {
        if (Big_Real[i] > Big_Real_2.Big_Real[i])
        {
          return 1; // Return true if current digit is greater in current number
        }
        else if (Big_Real[i] < Big_Real_2.Big_Real[i])
        {
          return 0; // Return false if current digit is greater in Big_Real_2
        }
      }
      // If all decimal digits are equal, compare the remaining digits
      ll limit = min(Big_Real.size(), Big_Real_2.Big_Real.size());
      ll i = Decimal_Size + 1;
      for (; i < limit; i++)
      {
        if (Big_Real[i] > Big_Real_2.Big_Real[i])
        {
          return 1; // Return true if current digit is greater in current number
        }
        else if (Big_Real[i] < Big_Real_2.Big_Real[i])
        {
          return 0; // Return false if current digit is greater in Big_Real_2
        }
      }
      // If all digits are equal, compare the total number of digits
      if (Big_Real.size() > Big_Real_2.Big_Real.size())
      {
        return 1; // Return true if current number has more total digits
      }
      else if (Big_Real.size() < Big_Real_2.Big_Real.size())
      {
        return 0; // Return false if current number has fewer total digits
      }
      else
      {
        return 0; // Return false if both numbers have the same total digits
      }
    }
  }
  else
  {
    // Both numbers have the same positive sign, so we need to compare them further
    int Decimal_Size = DecimalSize();
    if (Decimal_Size > Big_Real_2.DecimalSize())
    {
      return 0; // Return false if current number has more decimal digits
    }
    else if (Decimal_Size < Big_Real_2.DecimalSize())
    {
      return 1; // Return true if current number has fewer decimal digits
    }
    else
    {
      // Both numbers have the same number of decimal digits, so we need to compare them digit by digit
      for (ll i = 0; i < Decimal_Size; i++)
      {
        if (Big_Real[i] > Big_Real_2.Big_Real[i])
        {
          return 0; // Return false if current digit is greater in current number
        }
        else if (Big_Real[i] < Big_Real_2.Big_Real[i])
        {
          return 1; // Return true if current digit is greater in Big_Real_2
        }
      }

      // If all decimal digits are equal, compare the remaining digits
      ll limit = min(Big_Real.size(), Big_Real_2.Big_Real.size());
      ll i = Decimal_Size + 1;
      for (; i < limit; i++)
      {
        if (Big_Real[i] > Big_Real_2.Big_Real[i])
        {
          return 0; // Return false if current digit is greater in current number
        }
        else if (Big_Real[i] < Big_Real_2.Big_Real[i])
        {
          return 1; // Return true if current digit is greater in Big_Real_2
        }
      }

      // If all digits are equal, compare the total number of digits
      if (Big_Real.size() > Big_Real_2.Big_Real.size())
      {
        return 0; // Return false if current number has more total digits
      }
      else if (Big_Real.size() < Big_Real_2.Big_Real.size())
      {
        return 1; // Return true if current number has fewer total digits
      }
      else
      {
        return 0; // Return false if both numbers have the same total digits
      }
    }
  }
  return 0; // Default case, should not reach here
}

bool BigReal::operator>(BigReal Big_Real_2)
{
  // Check if the signs of the two BigReal numbers are different
  if (sign() != Big_Real_2.sign())
  {
    return (sign() > Big_Real_2.sign()); // Return true if current sign is greater than Big_Real_2 sign
  }
  // Both numbers have the same sign, so we need to compare them further
  else if (sign() == -1 && Big_Real_2.sign() == -1)
  {
    // Decimal_Size stores the number of decimal digits
    int Decimal_Size = DecimalSize();
    // Compare the number of decimal digits
    if (Decimal_Size > Big_Real_2.DecimalSize())
    {
      return 0; // Return false if current number has more decimal digits
    }
    else if (Decimal_Size < Big_Real_2.DecimalSize())
    {
      return 1; // Return true if current number has fewer decimal digits
    }
    else
    {
      // Both numbers have the same number of decimal digits, so we need to compare them digit by digit
      for (ll i = 0; i < Decimal_Size; i++)
      {
        if (Big_Real[i] > Big_Real_2.Big_Real[i])
        {
          return 0; // Return false if current digit is greater in current number
        }
        else if (Big_Real[i] < Big_Real_2.Big_Real[i])
        {
          return 1; // Return true if current digit is greater in Big_Real_2
        }
      }
      // If all decimal digits are equal, compare the remaining digits
      ll limit = min(Big_Real.size(), Big_Real_2.Big_Real.size());
      ll i = Decimal_Size + 1;
      for (; i < limit; i++)
      {
        if (Big_Real[i] > Big_Real_2.Big_Real[i])
        {
          return 0; // Return false if current digit is greater in current number
        }
        else if (Big_Real[i] < Big_Real_2.Big_Real[i])
        {
          return 1; // Return true if current digit is greater in Big_Real_2
        }
      }
      // If all digits are equal, compare the total number of digits
      if (Big_Real.size() > Big_Real_2.Big_Real.size())
      {
        return 0; // Return false if current number has more total digits
      }
      else if (Big_Real.size() < Big_Real_2.Big_Real.size())
      {
        return 1; // Return true if current number has fewer total digits
      }
      else
      {
        return 0; // Return false if both numbers have the same total digits
      }
    }
  }
  else
  {
    // Both numbers have the same positive sign, so we need to compare them further
    int Decimal_Size = DecimalSize();
    if (Decimal_Size > Big_Real_2.DecimalSize())
    {
      return 1; // Return true if current number has more decimal digits
    }
    else if (Decimal_Size < Big_Real_2.DecimalSize())
    {
      return 0; // Return false if current number has fewer decimal digits
    }
    else
    {
      // Both numbers have the same number of decimal digits, so we need to compare them digit by digit
      for (ll i = 0; i < Decimal_Size; i++)
      {
        if (Big_Real[i] > Big_Real_2.Big_Real[i])
        {
          return 1; // Return true if current digit is greater in current number
        }
        else if (Big_Real[i] < Big_Real_2.Big_Real[i])
        {
          return 0; // Return false if current digit is greater in Big_Real_2
        }
      }

      // If all decimal digits are equal, compare the remaining digits
      ll limit = min(Big_Real.size(), Big_Real_2.Big_Real.size());
      ll i = Decimal_Size + 1;
      for (; i < limit; i++)
      {
        if (Big_Real[i] > Big_Real_2.Big_Real[i])
        {
          return 1; // Return true if current digit is greater in current number
        }
        else if (Big_Real[i] < Big_Real_2.Big_Real[i])
        {
          return 0; // Return false if current digit is greater in Big_Real_2
        }
      }
      // If all digits are equal, compare the total number of digits
      if (Big_Real.size() > Big_Real_2.Big_Real.size())
      {
        return 1; // Return true if current number has more total digits
      }
      else if (Big_Real.size() < Big_Real_2.Big_Real.size())
      {
        return 0; // Return false if current number has fewer total digits
      }
      else
      {
        return 0; // Return false if both numbers have the same total digits
      }
    }
  }
  return 0; // Default case, should not reach here
}

bool BigReal::operator==(BigReal Big_Real_2)
{
  // Check if the sizes of the Big_Real vectors are not equal
  if (Big_Real.size() != Big_Real_2.Big_Real.size())
  {
    return 0; // Return false if sizes are different
  }
  else
  {
    // Sizes are equal, so we need to compare the elements of the vectors
    for (ll i = 0; i < Big_Real.size(); i++)
    {
      if (Big_Real[i] != Big_Real_2.Big_Real[i])
      {
        return 0; // Return false if any corresponding elements are different
      }
    }
    return 1; // All corresponding elements are equal, so return true
  }
}

bool BigReal::operator!=(BigReal Big_Real_2)
{
  // Check if the sizes of the Big_Real vectors are not equal
  if (Big_Real.size() != Big_Real_2.Big_Real.size())
  {
    return 1; // Return true if sizes are different (indicating not equal)
  }
  else
  {
    // Sizes are equal, so we need to compare the elements of the vectors
    for (ll i = 0; i < Big_Real.size(); i++)
    {
      if (Big_Real[i] != Big_Real_2.Big_Real[i])
      {
        return 1; // Return true if any corresponding elements are different (indicating not equal)
      }
    }
    return 0; // All corresponding elements are equal, so return false (indicating equal)
  }
}

ostream &operator<<(ostream &out, BigReal Real)
{
  // Check if the Big_Real has only ".0" in the end
  if (Real.Big_Real.size() == Real.DecimalSize() + 2 && (Real.Big_Real.back() == '0'))
  {
    // Create a string 'integer' and copy all elements of Big_Real except the ".0"
    string integer = Real.Big_Real;
    integer.pop_back();
    integer.pop_back();

    // Check if the number has a negative sign, and if so, output '-'
    if (Real.number_sign == -1)
    {
      out << '-';
    }
    // Output the modified string 'integer'
    out << integer;
  }
  else
  {
    // Check if the number has a negative sign, and if so, output '-'
    if (Real.number_sign == -1)
    {
      out << '-';
    }
    // Output the original Big_Real string
    out << Real.Big_Real;
  }
  // Return the output stream
  return out;
}

istream &operator>>(istream &in, BigReal &Real)
{
  // Define a string 'test_Real' to hold the input
  string test_Real;

  // Read input from the stream into 'test_Real'
  in >> test_Real;

  // Check if 'test_Real' is a valid BigReal
  if (Real.isValidReal(test_Real))
  {
    // If the first character of 'test_Real' is not '-', set 'number_sign' to 1 (positive)
    if (test_Real[0] != '-')
    {
      Real.number_sign = 1;
    }
    // If the first character is '-', set 'number_sign' to -1 (negative)
    else
    {
      Real.number_sign = -1;
    }

    // Format 'test_Real' and assign it to 'Big_Real'
    Real.Big_Real = Real.formattedReal(test_Real);
  }
  else
  {
    // If 'test_Real' is not a valid BigReal, print an error message
    cout << "invalid number";

    // Set 'Big_Real' to "0.0" and 'number_sign' to 1 (default)
    Real.Big_Real = "0.0";
    Real.number_sign = 1;
  }
  return in;
}

void BigReal::setNum(string realNumber)
{
  // Check if 'realNumber' is a valid BigReal
  if (isValidReal(realNumber))
  {
    // If the first character of 'realNumber' is not '-', set 'number_sign' to 1 (positive)
    if (realNumber[0] != '-')
    {
      number_sign = 1;
    }
    // If the first character is '-', set 'number_sign' to -1 (negative)
    else
    {
      number_sign = -1;
    }
    // Format 'realNumber' and assign it to 'Big_Real'
    Big_Real = formattedReal(realNumber);
  }
  else
  {
    // If 'realNumber' is not a valid BigReal, print an error message
    cout << "invalid number";
  }
}

void BigReal::setNum(double realNumber)
{
  // Convert the double 'realNumber' to a string for processing
  string number = to_string(realNumber);

  // If the first character of the string is not '-', set 'number_sign' to 1 (positive)
  if (number[0] != '-')
  {
    number_sign = 1;
  }
  // If the first character is '-', set 'number_sign' to -1 (negative)
  else
  {
    number_sign = -1;
  }
  // Format the string 'number' and assign it to 'Big_Real'
  Big_Real = formattedReal(number);
}
