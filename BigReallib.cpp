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
    DecimalSize();
  }
  else
  {
    cout << "invalid number\n";
    Big_Real = "0.0";
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
  DecimalSize();
}

BigReal::BigReal(const BigReal &other)
{ // Copy Constructor
  Big_Real = other.Big_Real;
  number_sign = other.number_sign;
  Decimal_Size = other.Decimal_Size;
}

int BigReal::size() // gets the size of the given number
{
  return Big_Real.size();
}

BigReal &BigReal::operator=(const BigReal &other)
{ // Assignment Operator
  Big_Real = other.Big_Real;
  this->number_sign = other.number_sign;
  Decimal_Size = other.Decimal_Size;
  return *this;
}

int BigReal::sign()
{
  return number_sign;
}

int BigReal::DecimalSize()
{
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

  int dotp = result.Decimal_Size;
  int dotp2 = other.Decimal_Size;
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
  if (sign() != Big_Real_2.sign())
  {
    return (sign() < Big_Real_2.sign());
  }
  else if (sign() == -1 && Big_Real_2.sign() == -1)
  {
    if (Decimal_Size > Big_Real_2.Decimal_Size)
    {
      return 1;
    }
    else if (Decimal_Size < Big_Real_2.Decimal_Size)
    {
      return 0;
    }
    else
    {
      for (ll i = 0; i < Decimal_Size; i++)
      {
        if (Big_Real[i] > Big_Real_2.Big_Real[i])
        {
          return 1;
        }
        else if (Big_Real[i] < Big_Real_2.Big_Real[i])
        {
          return 0;
        }
      }
      ll limit = min(Big_Real.size(), Big_Real_2.Big_Real.size());
      ll i = Decimal_Size + 1;
      for (; i < limit; i++)
      {
        if (Big_Real[i] > Big_Real_2.Big_Real[i])
        {
          return 1;
        }
        else if (Big_Real[i] < Big_Real_2.Big_Real[i])
        {
          return 0;
        }
      }
      if (Big_Real.size() > Big_Real_2.Big_Real.size())
      {
        return 1;
      }
      else if (Big_Real.size() < Big_Real_2.Big_Real.size())
      {
        return 0;
      }
      else
      {
        return 0;
      }
    }
  }
  else
  {
    if (Decimal_Size > Big_Real_2.Decimal_Size)
    {
      return 0;
    }
    else if (Decimal_Size < Big_Real_2.Decimal_Size)
    {
      return 1;
    }
    else
    {
      for (ll i = 0; i < Decimal_Size; i++)
      {
        if (Big_Real[i] > Big_Real_2.Big_Real[i])
        {
          return 0;
        }
        else if (Big_Real[i] < Big_Real_2.Big_Real[i])
        {
          return 1;
        }
      }

      ll limit = min(Big_Real.size(), Big_Real_2.Big_Real.size());
      ll i = Decimal_Size + 1;
      for (; i < limit; i++)
      {
        if (Big_Real[i] > Big_Real_2.Big_Real[i])
        {
          return 0;
        }
        else if (Big_Real[i] < Big_Real_2.Big_Real[i])
        {
          return 1;
        }
      }
      if (Big_Real.size() > Big_Real_2.Big_Real.size())
      {
        return 0;
      }
      else if (Big_Real.size() < Big_Real_2.Big_Real.size())
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }
  }
  return 0;
}

bool BigReal::operator>(BigReal Big_Real_2)
{
  if (sign() != Big_Real_2.sign())
  {
    return (sign() > Big_Real_2.sign());
  }
  else if (sign() == -1 && Big_Real_2.sign() == -1)
  {
    if (Decimal_Size > Big_Real_2.Decimal_Size)
    {
      return 0;
    }
    else if (Decimal_Size < Big_Real_2.Decimal_Size)
    {
      return 1;
    }
    else
    {
      for (ll i = 0; i < Decimal_Size; i++)
      {
        if (Big_Real[i] > Big_Real_2.Big_Real[i])
        {
          return 0;
        }
        else if (Big_Real[i] < Big_Real_2.Big_Real[i])
        {
          return 1;
        }
      }
      ll limit = min(Big_Real.size(), Big_Real_2.Big_Real.size());
      ll i = Decimal_Size + 1;
      for (; i < limit; i++)
      {
        if (Big_Real[i] > Big_Real_2.Big_Real[i])
        {
          return 0;
        }
        else if (Big_Real[i] < Big_Real_2.Big_Real[i])
        {
          return 1;
        }
      }
      if (Big_Real.size() > Big_Real_2.Big_Real.size())
      {
        return 0;
      }
      else if (Big_Real.size() < Big_Real_2.Big_Real.size())
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }
  }
  else
  {
    if (Decimal_Size > Big_Real_2.Decimal_Size)
    {
      return 1;
    }
    else if (Decimal_Size < Big_Real_2.Decimal_Size)
    {
      return 0;
    }
    else
    {
      for (ll i = 0; i < Decimal_Size; i++)
      {
        if (Big_Real[i] > Big_Real_2.Big_Real[i])
        {
          return 1;
        }
        else if (Big_Real[i] < Big_Real_2.Big_Real[i])
        {
          return 0;
        }
      }

      ll limit = min(Big_Real.size(), Big_Real_2.Big_Real.size());
      ll i = Decimal_Size + 1;
      for (; i < limit; i++)
      {
        if (Big_Real[i] > Big_Real_2.Big_Real[i])
        {
          return 1;
        }
        else if (Big_Real[i] < Big_Real_2.Big_Real[i])
        {
          return 0;
        }
      }
      if (Big_Real.size() > Big_Real_2.Big_Real.size())
      {
        return 1;
      }
      else if (Big_Real.size() < Big_Real_2.Big_Real.size())
      {
        return 0;
      }
      else
      {
        return 0;
      }
    }
  }
  return 0;
}

bool BigReal::operator==(BigReal Big_Real_2)
{
  if (Big_Real.size() != Big_Real_2.Big_Real.size())
  {
    return 0;
  }
  else
  {
    for (ll i = 0; i < Big_Real.size(); i++)
    {
      if (Big_Real[i] != Big_Real_2.Big_Real[i])
      {
        return 0;
      }
    }
    return 1;
  }
}

bool BigReal::operator!=(BigReal Big_Real_2)
{
  if (Big_Real.size() != Big_Real_2.Big_Real.size())
  {
    return 1;
  }
  else
  {
    for (ll i = 0; i < Big_Real.size(); i++)
    {
      if (Big_Real[i] != Big_Real_2.Big_Real[i])
      {
        return 1;
      }
    }
    return 0;
  }
}

ostream &operator<<(ostream &out, BigReal Real)
{
  if (Real.Big_Real.size() == Real.Decimal_Size + 2 && (Real.Big_Real.back() == '0'))
  {
    string integer = Real.Big_Real;
    integer.pop_back();
    integer.pop_back();
    if (Real.number_sign == -1)
    {
      out << '-';
    }
    out << integer;
  }
  else
  {
    if (Real.number_sign == -1)
    {
      out << '-';
    }
    out << Real.Big_Real;
  }
  return out;
}

istream &operator>>(istream &in, BigReal &Real)
{
  string test_Real;
  in >> test_Real;
  if (Real.isValidReal(test_Real))
  {

    if (test_Real[0] != '-')
    {
      Real.number_sign = 1; // returns 1 as a positive value
    }
    else
    {
      Real.number_sign = -1; // returns -1 as a negative value
    }
    Real.Big_Real = Real.formattedReal(test_Real);
    Real.DecimalSize();
  }
  else
  {
    cout << "invalid number";
    Real.Big_Real = "0.0";
  }
  return in;
}

void BigReal::setNum(string realNumber)
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
    DecimalSize();
  }
  else
  {
    cout << "invalid number";
  }
}

void BigReal::setNum(double realNumber)
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
  DecimalSize();
}


