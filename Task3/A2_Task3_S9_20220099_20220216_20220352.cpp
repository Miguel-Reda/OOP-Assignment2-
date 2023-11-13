// FCAI – OOP Programming – 2023 - Assignment-2 Task-3
// Program Name: A2_Task3_S9_20220099_20220216_20220352.cpp
// Last Modification Date: 14/11/2023
// Authors' Information:
// Author1 and ID and Email: Joseph Sameh   S10   20220099   jojo.1922005@gmail.com
// Author2 and ID and Email: Ammar Mohamed  s9    20220216   11410120220216@stud.cu.edu.eg
// Author3 and ID and Email: Miguel Reda    S9    20220352   megooreda2005@gmail.com
// Purpose:Machine language simulator

#include <bits/stdc++.h>
using namespace std;
#include "MLS.cpp"

int main()
{
    Machine machine;
    int command(1);
    while (command)
    {
        cout << "Menu: \n";
        cout << "1. Load \n";
        cout << "2. Run \n";
        cout << "3. Display \n";
        cout << "0. Exit \n";
        cin >> command;
        switch (command)
        {
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
