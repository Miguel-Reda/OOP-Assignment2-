// File: 1.cpp
// Purpose: the program reads a sentence of up to 100 characters and outputs the sentence with spacing
//          corrected and with letters corrected for capitalization
// Author: Joseph Sameh Fouad
// Section: S9 Wednesday 2nd slot
// ID: 20220099
// TA: Samar Sabry Shaker
// Date: 26 Oct 2023

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

void additional_definations()
{
  /*
  #define NULL nullptr
  #define pi 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
  #define mod 1000000007ll;
  */
}

void test_cases_definations()
{
#define tsn ts1 ts2 ts3
#define ts ts1 ts3
#define ts1 int t = 1;
#define ts2 cin >> t;
#define ts3 while (t--)
}

void remember_section()
{ /*
   *define array in class : array<int, "array size"> "array name" = {"elements"} **include <array>
   *define c-string : char name[] = "joseph" or {j, o, s, e, p, h, \0}  **lower memory
   *define a iterator: container<type>::iterator "iteratorName" =.. or auto "iteratorName" =..
   *define a pointer: int* ptr = &num;
   *dereference void ptr: in c-stile -> *(int *)ptr | modern -> *static_cast<int *>(ptr)
   *add c-strings : strcat(Fname,Lname) **include <cstring> or <string.h>
   *int mod: 11%2 VS float mod: fmod(11.5, 2)
   *use .at(i) not [i] in vector
   *ceil() = round up | flour() = round down | round() = mathmatical round
   *isspace() func. if found a space or \n or \t
   *second element after itr: iterator[1] or iterator + 1
   *advance(itr, 3) == itr += 3
   *min({ , , , , }), max({ , , , , })
   * you can use Emojis as a variable
   * convert vector element to -ve: transform(values.begin(), values.end(), values.begin(), std::negate<int>());;
   * multiply vector elements: accumulate(nums.begin(), nums.end(), 1, multiplies<int>())  **include <numeric>
   * cbegin() & nums.cend(): is a read only constant iterator
   * maximum element in vector: *max_element(v.begin(), v.end()) **include <algorithm>
   * string(str1.begin(), str1.end()) = str1.substr(0, str1.size())
   * I
   */
}

//_________________________________________________________________________________//
/*
input
the      Answer to life,       the Universe,


and everything IS 42.
*/

/*
output

*/

void solve()
{
  cout<<"Enter a sentence to correct spacing, letters, and capitalization.\n";
  char sentence[101];
  cin.getline(sentence, 101, '.');
  bool first = 1;
  for (int i = 0; i < 150; i++)
  {
    if (sentence[i] == '\0')
    {
      break;
    }
    else if (first && isalpha(sentence[i]))
    {
      cout << char(toupper(sentence[i]));
      first = 0;
    }
    else if (sentence[i] == ' ' && (sentence[i - 1] == ' ' || sentence[i - 1] == '\n'))
    {
      continue;
    }
    else if (sentence[i] == '\n' && (sentence[i - 1] == ' ' || sentence[i - 1] == '\n'))
    {
      continue;
    }
    else if (sentence[i] == '\n' || sentence[i] == ' ')
    {
      cout << ' ';
    }
    else
    {
      cout << char(tolower(sentence[i]));
    }
  }
  cout << ".\n";
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

  // fio;
  // ifs;
  // ofs;
  ts { solve(); }
  return 0;
}
