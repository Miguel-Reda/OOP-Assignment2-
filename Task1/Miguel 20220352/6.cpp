// File: 6.cpp
// Purpose: Port 8 takes a number and transform it into equivalent and Binary B.takes a string and a number and makes all the combinational possible.
// Author: Miguel Reda
// Section: S9 Wednesday 2nd slot
// ID:20220352
// TA: Samar Sabry Shaker
// Date: 28 Oct 2023
#include <bits/stdc++.h>
using namespace std;
// part a
// The binaryPrint function recursively converts a decimal number 'n' to its binary representation.
// It takes an integer 'n' and a string 's' as input.
// The function divides 'n' by 2 and recursively calls itself with the quotient.
// The remainder of the division is checked to determine the binary digit ('0' or '1') and added to the string 's'.
// Finally, the binary representation is printed.
void binaryPrint(int n, string s)
{
    if (n > 0)
    {
        binaryPrint(n / 2, s); // Recursive call with the quotient of n divided by 2.
        if (n % 2 == 0)
        {
            s.push_back('0'); // If n is even, add '0' to the binary representation string.
        }
        else
        {
            s.push_back('1'); // If n is odd, add '1' to the binary representation string.
        }
        n = floor(n); // Note: The line 'n = floor(n)' does not have any effect and can be removed.
    }
    cout << s; // Print the binary representation.
}
// part b
// The numbers function generates all possible binary numbers with a given prefix and k additional digits.
// It takes a string 'Prefix' and an integer 'k' as input.
// The function recursively generates binary numbers by appending '0' and '1' to the prefix,
// and decreasing 'k' by 1 in each recursive call.
// The generated binary numbers are printed with a newline character between them.
void numbers(string Prefix, int k)
{
    if (k == 0)
    {
        cout << Prefix << '\n'; // Print the binary number with the given prefix when k is zero.
    }
    else
    {
        numbers(Prefix + "0", k - 1); // Recursive call with '0' appended to the prefix and k decreased by 1.
        numbers(Prefix + "1", k - 1); // Recursive call with '1' appended to the prefix and k decreased by 1.
    }
}

int main()
{
    string s;
    int n;
    cin >> s;
    cin >> n;
    numbers(s,n);
    /* binaryPrint(n, s); */
}