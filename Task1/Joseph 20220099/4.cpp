// File: 4.cpp
// Purpose: find all the prime numbers up to some upper limit n
// Author: Joseph Sameh Fouad
// Section: S9 Wednesday 2nd slot
// ID: 20220099
// TA: Samar Sabry Shaker
// Date: 27 Oct 2023

#include "bits/stdc++.h"

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

int visited[N];
vector<int> primes;
void prime(int &to_num)
{
  for (ll i = 2; i <= to_num; i++)
  {
    if (!visited[i])
    {
      primes.push_back(i);
    }
    for (ll j = i * i; j <= to_num; j += i)
    {
      visited[j] = 1;
    }
  }
}
void solve()
{
  cout<<"Enter the Upper limit to find all the prime numbers up to this limit.\n";
  int to_num;
  cin >> to_num;
  prime(to_num);
  for (auto prime : primes)
  {
    cout << prime << ' ';
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
