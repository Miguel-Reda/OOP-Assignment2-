// File: 12.cpp
// Purpose: find the fishing horse in emails to prevent scams.
// Author: Miguel Reda
// Section: S9 Wednesday 2nd slot
// ID:20220352
// TA: Samar Sabry Shaker
// Date: 29 Oct 2023
#include <bits/stdc++.h>
using namespace std;
map<string, int> Phishing_keywords = {
    {"password", 3},
    {"account", 3},
    {"verify", 3},
    {"urgent", 3},
    {"login", 3},
    {"update", 2},
    {"bank", 3},
    {"creditcard", 3},
    {"social security number", 3},
    {"security alert", 2},
    {"paypal", 3},
    {"financial", 1},
    {"suspicious activity", 2},
    {"unauthorized access", 2},
    {"limited time offer", 1},
    {"click here", 2},
    {"phishing", 3},
    {"lottery", 1},
    {"congratulations", 1},
    {"IRS", 2},
    {"free", 1},
    {"win", 1},
    {"claim", 1},
    {"offer", 1},
    {"urgent action required", 2},
    {"prize", 1},
    {"exclusive deal", 1},
    {"reward", 1},
    {"guaranteed", 1},
    {"secret", 1}};
int main()
{
    string file_name, track;
    cin >> file_name;
    freopen("words.txt", "r", stdin);
    int Total_count = 0;
    // ifstream input_file(file_name);
    map<string, int> found_words;
    while (cin >> track)
    {
        transform(track.begin(), track.end(), track.begin(), ::tolower);
        if (Phishing_keywords.find(track) != Phishing_keywords.end())
        {
            found_words[track]++;
            Total_count += Phishing_keywords[track];
        }
    }
    /* for (auto it = found_words.begin(); it != found_words.end(); it++)
    {
        cout << it->first << "  " << it->second << '\n';
    } */
      for (auto [x, y] : found_words)
      {
          cout << x << "  " << y << '\n';
      }
    cout << "Total count is: " << Total_count;
}