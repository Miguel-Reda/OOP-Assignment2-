// File: 9.cpp
// Purpose:
// Author: Miguel Reda
// Section: S9 Wednesday 2nd slot
// ID:20220352
// TA: Samar Sabry Shaker
// Date: 29 Oct 2023
#include <bits/stdc++.h>
using namespace std;
bool bear(int n)
{
    if (n == 42)
    {
        return true;
    }
    else if (n % 5 == 0)
    {
        n -= 42;
        return bear(n);
    }
    else if (n % 2 == 0 && n > 83)
    {
        n /= 2;
        return bear(n);
    }
    else if (n % 3 == 0 || n % 4 == 0)
    {
        n -= ((n % 10) * ((n % 100) / 10));
        return bear(n);
    }
    else
    {
        return false;
    }
}

int main()
{
    int a;
    cin >> a;
    if (bear(a))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}
