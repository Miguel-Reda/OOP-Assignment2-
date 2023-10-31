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


        if (Big_Real[0] != '-')
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
        cout << "invalid number";
    }
    DecimalSize();
}

int BigReal::size()  //gets the size of the given number
{
    return Big_Real.size();
}

BigReal::BigReal(const BigReal &other)
{ // Copy Constructor
    Big_Real = other.Big_Real;
    DecimalSize();
}

BigReal &BigReal::operator=(const BigReal &other)
{ // Assignment Operator
    Big_Real = other.Big_Real;
    this->number_sign = other.number_sign;
    /*DecimalSize();*/
    return *this;
}

int BigReal::sign()
{
    return number_sign;
}

int BigReal::DecimalSize()
{
    int Decimal_Size = Big_Real.find('.');
    return Decimal_Size;
}

string BigReal::formattedReal(string realNumber) {
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
    while (it != dot &&  *it == '0')
        it--;

    realNumber.erase(it + 1, realNumber.end());

    if (it == dot)
        realNumber.push_back('0');

    return realNumber;
}


BigReal operator+(BigReal first ,BigReal other){

    int dotp = first.DecimalSize();
    int dotp2 = other.DecimalSize();
    int frac1 = first.size() - dotp;
    int frac2 = other.size() - dotp2;

    //zero padding
    if (dotp > dotp2){
        other.Big_Real.insert(0,dotp - dotp2,'0');
    }
    else if (dotp2 > dotp){
        first.Big_Real.insert(0,dotp2 - dotp , '0');
    }
    if (frac1 > frac2){
        other.Big_Real.append(frac1-frac2,'0');

    } else if (frac2 > frac1){
        first.Big_Real.append(frac2-frac1,'0');
    }

    if (first.sign() * other.sign() == 1) {
        string::reverse_iterator f = first.Big_Real.rbegin();
        string::reverse_iterator o = other.Big_Real.rbegin();
        int carry(0);
        for (; f != first.Big_Real.rend(); f++, o++) {
            if (*f == '.') continue;
            int sum = ((*f - '0') + (*o - '0')) + carry;
            carry = sum / 10;
            sum %= 10;
            *f = sum + '0';

        }
        if (carry) first.Big_Real.insert(0, "1");

        return first;
    }

    else{
        bool flag(0);
        if (first.sign() == -1){
            first.number_sign = 1;
            flag = true;
        }
        else{
            other.number_sign = 1;

        }
        if (first < other){
            swap(first,other);
            if (!flag){
                first.number_sign = -1;
            }

        }
        else if (!(other<first)){
            first.Big_Real = "0.0";
            return first;
        }
        else{
            if (flag){
                first.number_sign = -1;

            }

        }
        string::reverse_iterator f = first.Big_Real.rbegin();
        string::reverse_iterator o = other.Big_Real.rbegin();
        int carry(0);
        for (; f != first.Big_Real.rend(); f++, o++) {
            if (*f == '.') continue;
            int sum = ((*f) - (*o)) - carry;
            if (sum < 0){
                carry = 1;
                sum += 10;
            }
            else{
                carry = 0;
            }

            *f = sum + '0';

        }


        return first;
    }



}

BigReal BigReal:: operator-(BigReal other){
    other.number_sign *= -1;
    return (*this + other);
}

bool BigReal::operator<(BigReal Big_Real_2)
{
    if (sign() != Big_Real_2.sign())
    {
        return (sign() < Big_Real_2.sign());
    }

    if (sign() == -1 && Big_Real_2.sign() == -1)
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
            if (Big_Real.size() < Big_Real_2.Big_Real.size())
            {
                return false;
            }
            else if (Big_Real.size() > Big_Real_2.Big_Real.size())
            {
                return true;
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

ostream &operator<<(ostream &out, BigReal Real)
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