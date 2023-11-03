#include <stdio.h>
#include <iostream>
#include <regex>
#include <string>
#include "BigReallib.h"
#define ll long long
using namespace std;

bool BigReal::isValidReal(string realNumber)
{
  return (regex_match(realNumber, regex("[+-]?\\d*\\.?\\d*")) /* && realNumber.size() > 1 */);
}

BigReal::BigReal(string realNumber)
{
  if (isValidReal(realNumber))
  {
    Big_Real = realNumber;
    DecimalSize();
  }
  else
  {
    cout << "invalid number\n";
    Big_Real = "0.0";
  }
}

BigReal::BigReal(const BigReal &other)
{ // Copy Constructor
  Big_Real = other.Big_Real;
  DecimalSize();
}

BigReal &BigReal::operator=(BigReal &other)
{ // Assignment Operator
  Big_Real = other.Big_Real;
  DecimalSize();
  return other;
}

int BigReal::sign()
{
  if (isdigit(Big_Real[0]) || Big_Real[0] == '+' || Big_Real[0] == '.')
  {
    return 1; // returns 1 as a positive value
  }
  else
  {
    return -1; // returns -1 as a negative value
  }
}

int BigReal::DecimalSize()
{
  Decimal_Size = 0;
  for (auto digit : Big_Real)
  {
    if (digit != '.')
    {
      ++Decimal_Size;
    }
    else
    {
      break;
    }
  }
  --Decimal_Size;
  return Decimal_Size;
}

bool BigReal::operator<(BigReal Big_Real_2)
{
  if (Big_Real[0] == '-' && Big_Real_2.Big_Real[0] != '-')
  {
    return 1;
  }
  else if (Big_Real[0] != '-' && Big_Real_2.Big_Real[0] == '-')
  {
    return 0;
  }
  else if (Big_Real[0] == '-' && Big_Real_2.Big_Real[0] == '-')
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
      ll i = Decimal_Size + 2;
      for (i = Decimal_Size + 2; i < limit; i++)
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
      if (Big_Real.size() < Big_Real_2.Big_Real.size())
      {
        for (i; i < Big_Real_2.Big_Real.size(); i++)
        {
          if (Big_Real_2.Big_Real[i] > '0')
          {
            return 0;
          }
        }
      }
      else if (Big_Real.size() > Big_Real_2.Big_Real.size())
      {
        for (i; i < Big_Real.size(); i++)
        {
          if (Big_Real[i] > '0')
          {
            return 1;
          }
        }
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
      ll i = Decimal_Size + 2;
      for (i = Decimal_Size + 2; i < limit; i++)
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
      if (Big_Real.size() < Big_Real_2.Big_Real.size())
      {
        for (i; i < Big_Real_2.Big_Real.size(); i++)
        {
          if (Big_Real_2.Big_Real[i] > '0')
          {
            return 1;
          }
        }
      }
      else if (Big_Real.size() > Big_Real_2.Big_Real.size())
      {
        for (i; i < Big_Real.size(); i++)
        {
          if (Big_Real[i] > '0')
          {
            return 0;
          }
        }
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
  if (Big_Real[0] == '-' && Big_Real_2.Big_Real[0] != '-')
  {
    return 0;
  }
  else if (Big_Real[0] != '-' && Big_Real_2.Big_Real[0] == '-')
  {
    return 1;
  }
  else if (Big_Real[0] == '-' && Big_Real_2.Big_Real[0] == '-')
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
      ll i = Decimal_Size + 2;
      for (i = Decimal_Size + 2; i < limit; i++)
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
      if (Big_Real.size() < Big_Real_2.Big_Real.size())
      {
        for (i; i < Big_Real_2.Big_Real.size(); i++)
        {
          if (Big_Real_2.Big_Real[i] > '0')
          {
            return 1;
          }
        }
      }
      else if (Big_Real.size() > Big_Real_2.Big_Real.size())
      {
        for (i; i < Big_Real.size(); i++)
        {
          if (Big_Real[i] > '0')
          {
            return 0;
          }
        }
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
      ll i = Decimal_Size + 2;
      for (i = Decimal_Size + 2; i < limit; i++)
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
      if (Big_Real.size() < Big_Real_2.Big_Real.size())
      {
        for (i; i < Big_Real_2.Big_Real.size(); i++)
        {
          if (Big_Real_2.Big_Real[i] > '0')
          {
            return 0;
          }
        }
      }
      else if (Big_Real.size() > Big_Real_2.Big_Real.size())
      {
        for (i; i < Big_Real.size(); i++)
        {
          if (Big_Real[i] > '0')
          {
            return 1;
          }
        }
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

ostream &operator<<(ostream &out, BigReal &Real)
{
  if (Real.Big_Real.size() == Real.Decimal_Size + 3 && (Real.Big_Real.back() == '0'))
  {
    string integer = Real.Big_Real;
    integer.pop_back();
    integer.pop_back();
    out << integer;
  }
  else
  {
    out << Real.Big_Real;
  }
  return out;
}

istream &operator>>(istream &in, BigReal &Real)
{
  string test_Real;
  in >> test_Real;
  if (test_Real[0] != '-' && test_Real[0] != '+')
  {
    test_Real = '+' + test_Real;
  }

  if (Real.isValidReal(test_Real))
  {
    Real.Big_Real = test_Real;
    Real.DecimalSize();
  }
  else
  {
    cout << "invalid number\n";
  }
  return in;
}
