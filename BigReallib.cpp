#include <stdio.h>
#include <iostream>
#include <regex>
#include "BigReallib.h"

using namespace std;

bool BigReal::isValidReal(string realNumber)
{
  return (regex_match(realNumber, regex("[+-]?\\d*\\.?\\d*")));
}

BigReal::BigReal()
{
  Big_Real = "0.0";
}

BigReal::BigReal(string realNumber)
{
  if (isValidReal(realNumber))
  {
    Big_Real = realNumber;
  }
  else
  {
    cout << "invalid number";
  }
}

BigReal::BigReal(const BigReal &other)
{ // Copy Constructor
  Big_Real = other.Big_Real;
}

BigReal &BigReal::operator=(BigReal &other)
{ // Assignment Operator
  Big_Real = other.Big_Real;
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
    int size1=0, size2=0;
    for (auto digit : Big_Real)
    {
      if (digit != '.')
      {
        ++size1;
      }
      else
      {
        break;
      }
    }
    for (auto digit : Big_Real_2.Big_Real)
    {
      if (digit != '.')
      {
        ++size2;
      }
      else
      {
        break;
      }
    }
    if (size1 > size2)
    {
      return 1;
    }
    else if (size1 < size2)
    {
      return 0;
    }
    else
    {
      for (int i = 0; i < size1; i++)
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

      for (int i = size1 + 1; i < Big_Real.size(); i++)
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

      if (Big_Real.size() <= Big_Real_2.Big_Real.size())
      {
        return 0;
      }
      return 1;
    }
  }
  else
  {
    int size1=0, size2=0;
    for (auto digit : Big_Real)
    {
      if (digit != '.')
      {
        ++size1;
      }
      else
      {
        break;
      }
    }
    for (auto digit : Big_Real_2.Big_Real)
    {
      if (digit != '.')
      {
        ++size2;
      }
      else
      {
        break;
      }
    }
    if (size1 > size2)
    {
      return 0;
    }
    else if (size1 < size2)
    {
      return 1;
    }
    else
    {
      for (int i = 0; i < size1; i++)
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

      for (int i = size1 + 1; i < Big_Real.size(); i++)
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
        return 1;
      }
      return 0;
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
    int size1=0, size2=0;
    for (auto digit : Big_Real)
    {
      if (digit != '.')
      {
        ++size1;
      }
      else
      {
        break;
      }
    }
    for (auto digit : Big_Real_2.Big_Real)
    {
      if (digit != '.')
      {
        ++size2;
      }
      else
      {
        break;
      }
    }
    if (size1 > size2)
    {
      return 0;
    }
    else if (size1 < size2)
    {
      return 1;
    }
    else
    {
      for (int i = 0; i < size1; i++)
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

      for (int i = size1 + 1; i < Big_Real.size(); i++)
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
        return 1;
      }
      return 0;
    }
  }
  else
  {
    int size1=0, size2=0;
    for (auto digit : Big_Real)
    {
      if (digit != '.')
      {
        ++size1;
      }
      else
      {
        break;
      }
    }
    for (auto digit : Big_Real_2.Big_Real)
    {
      if (digit != '.')
      {
        ++size2;
      }
      else
      {
        break;
      }
    }
    if (size1 > size2)
    {
      return 1;
    }
    else if (size1 < size2)
    {
      return 0;
    }
    else
    {
      for (int i = 0; i < size1; i++)
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

      for (int i = size1 + 1; i < Big_Real.size(); i++)
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

      if (Big_Real.size() <= Big_Real_2.Big_Real.size())
      {
        return 0;
      }
      return 1;
    }
  }
  return 1;
}

