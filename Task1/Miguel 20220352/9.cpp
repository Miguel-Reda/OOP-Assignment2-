// File: 9.cpp
// Purpose: it is a game
// Author: Miguel Reda
// Section: S9 Wednesday 2nd slot
// ID:20220352
// TA: Samar Sabry Shaker
// Date: 29 Oct 2023
#include <bits/stdc++.h>
using namespace std;

// The bear function determines if a given integer n satisfies specific conditions.
// It recursively applies rules to n, returning true if n becomes 42, and false otherwise.
bool bear(int n)
{
    // If n is 42, the condition is satisfied, return true.
    if (n == 42)
    {
        return true;
    }
    // If n is a multiple of 5, subtract 42 from n and recursively check the new value.
    else if (n % 5 == 0)
    {
        n -= 42;
        return bear(n);
    }
    // If n is even and greater than 83, divide n by 2 and recursively check the new value.
    else if (n % 2 == 0 && n > 83)
    {
        n /= 2;
        return bear(n);
    }
    // If n is divisible by 3 or 4, subtract the product of its last digit and tens digit from n,
    // and recursively check the new value.
    else if (n % 3 == 0 || n % 4 == 0)
    {
        n -= ((n % 10) * ((n % 100) / 10));
        return bear(n);
    }
    // If none of the conditions are met, return false.
    else
    {
        return false;
    }
}

int main()
{
    int a;
    cin >> a; // Read an integer from the user.

    // Check if the input integer satisfies the conditions defined in the bear function.
    // Output "true" if the conditions are met, and "false" otherwise.
    if (bear(a))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}
