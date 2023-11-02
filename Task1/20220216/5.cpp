// File: ………cpp
// Purpose: player list management
// Author: Ammar Mohamed Mahmoud Hamed
// Section: S9 Wednesday 2nd slot
// ID: 20220216
// TA: Samar Sabry Shaker
// Date: …… Oct 2023
#include <bits/stdc++.h>
using namespace std;
pair<string ,int> arr[10];

void AddPlayer(){
    pair<string ,int> InputPlayer;
    cin >> InputPlayer.first >> InputPlayer.second;
    for (int i = 0; i < 10; ++i) {
        if (InputPlayer.second > arr[i].second) {
            swap(InputPlayer,arr[i]);
        }
    }
}

void printTopTen(){
    for (int i = 0; i < 10; ++i) {
        if (arr[i].second == 0) break;
        cout << arr[i].first << ": " << arr[i].second << '\n';
    }
}

void EnterPlayerName(){
    string name;
    cin >> name;
    for (int i = 0; i < 10; ++i) {
        if (arr[i].first == name){
            cout << arr[i].second << '\n';
            return;
        }
    }
    cout << "Player is not in top 10\n";

}


int main() {
    char Menu[] =
            "Please select an option to apply or 0 to exit:\n"
            "1- Add a New Player\n"
            "2- Print Top Ten Players\n"
            "3- Enter a Player Name\n"
            "0- Exit";
    int option;
    void (*menu[])() = {AddPlayer,printTopTen,EnterPlayerName};

    while (true) {
        puts(Menu);
        cin >> option;
        if (option == 0) break;
        menu[option - 1]();

    }



}
