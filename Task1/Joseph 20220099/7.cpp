// File: 7.cpp
// Purpose: The game of dominos
// Author: Joseph Sameh Fouad
// Section: S9 Wednesday 2nd slot
// ID: 20220099
// TA: Samar Sabry Shaker
// Date: 27 Oct 2023

//                                libraries
#include "bits/stdc++.h"
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <numeric>

using namespace std;

void definations()
{
#define endl '\n'
#define ll long long
// #define str string
#define len length()
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(c) (c).begin(), (c).end()
#define allr(c) (c).rbegin(), (c).rend()
#define fr(c) for (ll i = 0; i < c; i++)
#define fr1(c) for (ll i = 1; i <= c; i++)
#define frj(c) for (ll j = 0; j < c; j++)
#define fr1j(c) for (ll j = 1; j <= c; j++)

#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ifs freopen("D:/VS Code/College/2nd year/input.txt", "r", stdin);
#define ofs freopen("D:/VS Code/College/2nd year/output.txt", "w", stdout);
#define files                                                   \
  freopen("D:/VS Code/College/2nd year/input.txt", "r", stdin); \
  freopen("D:/VS Code/College/2nd year/output.txt", "w", stdout);
}
const ll mod = 1e9 + 7, inf = 1e9, N = 1e5 + 5, M = 5e1 + 5;
char di[] = {'D', 'L', 'U', 'R'};
int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};

void test_cases_definations()
{
#define tsn ts1 ts2 ts3
#define ts ts1 ts3
#define ts1 int t = 1;
#define ts2 cin >> t;
#define ts3 while (t--)
}

//_________________________________________________________________________________//
/*
input
Test case :1
 5 ==>size
 2 6
 6 1
 1 4
 4 4
 4 3
 success

Test case :2

10

1 2
2 3
8 9
3 4
5 6
6 7
10 1
7 8
4 5
9 10
success

 Test case 3:
 4==>size
 2 6
 6 1
 4 4
 4 3
*/

/*
output

*/

vector<string> result; // It will be a store in which result of chain domino

bool FormsDominoChain(vector<pair<string, string>> &dominos)
{
  sort(dominos.begin(), dominos.end());
  do
  {
    bool success = true;
    for (int j = 1; j < dominos.size(); j++)
    {
      if (dominos[j].first != dominos[j - 1].second)
      {
        success = false;
        break;
      }
    }

    if (success == true)
    {
      for (int i = 0; i < dominos.size(); i++)
      {
        result.push_back(dominos[i].first);
        result.push_back(dominos[i].second);
      }
      return 1;
    }
  } while (next_permutation(dominos.begin(), dominos.end()));

  return 0;
}

void solve()
{
  int size;
  cout << "Enter the number of Domino ==>";
  cin >> size;
  // vector<dominoT> vector(size);
  vector<pair<string, string>> vector(size);
  cout << "Enter two number of domino left first, then right" << endl;
  for (auto &x : vector)
  {
    cin >> x.first;
    cin >> x.second;
  }
  if (FormsDominoChain(vector))
  {
    cout << "True, it's possible to build a chain consisting of every domino in the vector" << endl;
    // to print answer
    for (int i = 0; i < result.size(); i++)
    {
      if (i == result.size() - 1)
      {
        cout << result[i]; // not to print — in the end
        continue;
      }
      if (i & 1)
      {
        cout << result[i] << " — ";
      }
      else
      {
        cout << result[i] << "|";
      }
    }
  }
  else
  {
    cout << "False, it's impossible to build a chain consisting of every domino in the vector" << endl;
  }
}
/*
_________________________________________________________________________________
                            ⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⡀⠠⠤⠀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀
                            ⠀⠀⠀⠀⣀⢤⡒⠉⠁⠀⠒⢂⡀⠀⠀⠀⠈⠉⣒⠤⣀⠀⠀⠀⠀
                            ⠀⠀⣠⠾⠅⠈⠀⠙⠀⠀⠀⠈⠀⠀⢀⣀⣓⡀⠉⠀⠬⠕⢄⠀⠀
                            ⠀⣰⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡤⠶⢦⡀⠑⠀⠀⠀⠀⠈⢧⠀
                            ⠀⡇⠀⠀⠀⠀⠀⢤⣀⣀⣀⣀⡀⢀⣀⣀⠙⠀⠀⠀⠀⠀⠀⢸⡄
                            ⠀⢹⡀⠀⠀⠀⠀⡜⠁⠀⠀⠙⡴⠁⠀⠀⠱⡄⠀⠀⠀⠀⠀⣸⠀
                            ⠀⠀⠱⢄⡀⠀⢰⣁⣒⣒⣂⣰⣃⣀⣒⣒⣂⢣⠀⠀⢀⡴⠁⠀
                            ⠀⠀⠀⠀⠙⠲⢼⡀⠀⠙⠀⢠⡇⠀⠛⠀⠀⣌⣀⡤⠖⠉⠀⠀⠀
                            ⠀⠀⠀⠀⠀⠀⢸⡗⢄⣀⡠⠊⠈⢦⣀⣀⠔⡏⠀⠀⠀⠀⠀⠀⠀
                            ⠀⠀⠀⠀⠀⠀⠈⡇⠀⢰⠁⠀⠀⠀⢣⠀⠀⣷⠀⠀⠀⠀⠀⠀⠀
                            ⠀⠀⠀⠀⣠⠔⠊⠉⠁⡏⠀⠀⠀⠀⠘⡆⠤⠿⣄⣀⠀⠀⠀⠀⠀
                            ⠀⠀⠀⠀⣧⠸⠒⣚⡩⡇⠀⠀⠀⠀⠀⣏⣙⠒⢴⠈⡇⠀⠀⠀⠀
                            ⠀⠀⠀⠀⠈⠋⠉⠀⠀⢳⡀⠀⠀⠀⣸⠁⠈⠉⠓⠚⠁⠀⠀⠀⠀
                            ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠓⠛⠛
*/
int main()
{
  definations(), test_cases_definations();
  // #ifndef ONLINE_JUDGE
  //   files
  // #endif

  // fio;
  // ifs;
  // ofs;
  ts { solve(); }
  return 0;
}
