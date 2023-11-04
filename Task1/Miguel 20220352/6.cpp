// File: 7.cpp
// Purpose: The program take a string and separate all the elements and delete spaces and store it in a vector.
// Author: Miguel Reda
// Section: S9 Wednesday 2nd slot
// ID:20220352
// TA: Samar Sabry Shaker
// Date: 28 Oct 2023
#include <bits/stdc++.h>
using namespace std;
// part a
void binaryPrint(int n, string s)
{
    if (n > 0)
    {
        binaryPrint(n / 2, s);
        if (n % 2 == 0)
        {
            s.push_back('0');
        }
        else
        {
            s.push_back('1');
        }
        n = floor(n);
    }
    cout << s;
}
// part b
void numbers(string Prefix, int k)
{
    if (k == 0)
    {
        cout << Prefix<<'\n';
    }
    else
    {
        numbers(Prefix + "0", k - 1);
        numbers(Prefix + "1", k - 1);
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