// File: ………cpp
// Purpose: recursive fractal pattern builder
// Author: Ammar Mohamed Mahmoud Hamed
// Section: S9 Wednesday 2nd slot
// ID: 20220216
// TA: Samar Sabry Shaker
// Date: …… Oct 2023

#include <iostream>

using namespace std;
void pattern(int n,int i)
{
    if(n==0)
    {
        return;
    }
    pattern(n/2,i);
        for(int j=0;j<i;++j)
        {
            cout<<"  ";
        }
        for(int j=0;j<n;++j)
        {
            cout<<"* ";
        }
        cout<<"\n";
        pattern(n/2,i + n/2);
}
int main() {
    pattern(8,0);
    return 0;
}
