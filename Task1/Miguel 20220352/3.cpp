// File: 3.cpp
// Purpose: The program take a string and separate all the elements and delete spaces and store it in a vector.
// Author: Miguel Reda
// Section: S9 Wednesday 2nd slot
// ID:20220352
// TA: Samar Sabry Shaker
// Date: 28 Oct 2023

#include <bits/stdc++.h>
using namespace std;
// The split function takes two strings as input: 'target' (the string to be split) and 'delimiter' (the separator used to split the string).
// It splits the 'target' string into multiple substrings based on the 'delimiter'.
// The function iteratively finds the 'delimiter' in the 'target' string, extracts the substring before the 'delimiter', and adds it to the result vector.
// It then removes the extracted substring along with the 'delimiter' from the 'target' string and continues the process until no more instances of 'delimiter' are found.
// Finally, the remaining 'target' string (which does not contain any more delimiters) is added to the result vector.
// The function returns a vector of strings containing the split substrings.

vector<string> split(string target, string delimiter)
{
    vector<string> result; // Vector to store the split substrings.
    int index = 0; // Variable to keep track of the position of the found delimiter in the 'target' string.
    string take; // Temporary variable to store the extracted substring before the delimiter.
    int d = delimiter.size(); // Size of the delimiter string.

    // Loop until the delimiter is found in the 'target' string.
    while ((index = target.find(delimiter)) != string::npos)
    {
        take = target.substr(0, index); // Extract substring before the delimiter.
        result.push_back(take); // Add the extracted substring to the result vector.
        target.erase(0, index + d); // Remove the extracted substring along with the delimiter from the 'target' string.
    }

    // Add the remaining 'target' string (without any more delimiters) to the result vector.
    result.push_back(target);

    return result; // Return the vector containing the split substrings.
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
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}
