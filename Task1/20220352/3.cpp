// File: ………cpp
// Purpose:
// Author:
// Section: S9 Wednesday 2nd slot
// ID:
// TA: Samar Sabry Shaker
// Date: …… Oct 2023
// File: 3.cpp
// Purpose: The program take a string and separate all the elements and delete spaces and store it in a vector.
// Author: Miguel Reda
// Section: S9 Wednesday 2nd slot
// ID:20220352
// TA: Samar Sabry Shaker
// Date: 28 Oct 2023
#include <bits/stdc++.h>
using namespace std;
vector<string> split(string target, string delimiter)
{
    vector<string> result;
    int index = 0;
    string take;
    int d = delimiter.size();
    while ((index = target.find(delimiter)) != string::npos)
    {
        take = target.substr(0, index);
        result.push_back(take);
        target.erase(0, index + d);
    }
    result.push_back(target);
    return result;
}
int main()
{
    string target, delimiter;
    vector<string> result;
    cout << "Enter Targeted string ";
    cin >> target;

    cout << "Enter the delimiter";
    cin >> delimiter;
    result = split(target, delimiter);
    
}