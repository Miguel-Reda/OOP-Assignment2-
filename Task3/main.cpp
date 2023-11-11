#include<bits/stdc++.h>
using namespace std;
#include "MLS.cpp"

int main() {
    Machine machine;
    int command(1);
    while (command) {
        cout << "Menu: \n";
        cout << "1. Load \n";
        cout << "2. Run \n";
        cout << "3. Display \n";
        cout << "0. Exit \n";
        cin >> command;
        switch (command) {
            case 1:
                machine.mloadFile();
                break;
            case 2:
                machine.exec();
                break;
            case 3:
                machine.show();
                break;
        }
    }
}