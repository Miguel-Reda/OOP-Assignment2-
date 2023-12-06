// FCAI – OOP Programming – 2023 - Assignment-2 Task-2
// Program Name: A2_Task2_S9_20220099_20220216_20220352.cpp
// Last Modification Date: ……/10/2023
// Authors' Information:
// Author1 and ID and Email: Joseph Sameh   S10   20220099   jojo.1922005@gmail.com
// Author2 and ID and Email: Ammar Mohamed  s9    20220216   11410120220216@stud.cu.edu.eg
// Author3 and ID and Email: Miguel Reda    S9    20220352   megooreda2005@gmail.com
// Purpose:

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "BigReallib.cpp"

using namespace std;

int main()
{
     BigReal n1("11.9000000000000000000000000000000001");
     BigReal n2("2333333333339.1134322222222292");
     BigReal n3 = n1 + n2;
     cout << n3 << endl;
     n3 = n3 + BigReal(0.9);
     cout << n3 << endl;

     BigReal a1("99");
     cout << a1 << endl;
     BigReal a2("99.033");
     cout << a2 << endl;
     BigReal a3("+99.07156");
     cout << a3 << endl;
     BigReal a4("-99");
     cout << a4 << endl;
     BigReal a5("-99.645");
     cout << a5 << endl;

     cout << endl
          << endl;
     BigReal b1(99);
     cout << b1 << endl;
     BigReal b2(99.033);
     cout << b2 << endl;
     BigReal b3(+99.07156);
     cout << b3 << endl;
     BigReal b4(-99);
     cout << b4 << endl;
     BigReal b5(-99.645);
     cout << b5 << endl;

     cout << endl
          << endl;
     BigReal c1 = b1;
     cout << c1 << endl;
     BigReal c2 = b2;
     cout << c2 << endl;

     cout << endl
          << endl;
     c1.setNum("1234.567");
     cout << c1 << endl;
     c2.setNum("-1234.567");
     cout << c2 << endl;

     cout << endl
          << endl;
     c1.setNum(1234.567);
     cout << c1 << endl;
     c2.setNum(-1234.567);
     cout << c2 << endl;

     cout << endl
          << endl;
     cout << c1.size() << endl;
     cout << c2.size() << endl;

     cout << endl
          << endl;
     cout << c1.sign() << endl;
     cout << c2.sign() << endl;

     cout << endl
          << endl;
     BigReal d1("5678.67890");
     BigReal d2("1234.2345");
     cout << d1 + d2 << endl;
     cout << d1 - d2 << endl;
     BigReal d3 = d1 + d2;
     cout << d3 << endl;
     BigReal d4 = d1 - d2;
     cout << d4 << endl;

     cout << endl
          << endl;
     BigReal e1("-5678.67890");
     BigReal e2("-1234.2345");
     cout << e1 + e2 << endl;
     cout << e1 - e2 << endl;
     BigReal e3 = e1 + e2;
     cout << e3 << endl;
     BigReal e4 = e1 - e2;
     cout << e4 << endl;

     cout << endl
          << endl;
     BigReal f1("5678.67890");
     BigReal f2("-1234.2345");
     cout << f1 + f2 << endl;
     cout << f1 - f2 << endl;
     BigReal f3 = f1 + f2;
     cout << f3 << endl;
     BigReal f4 = f1 - f2;
     cout << f4 << endl;

     cout << endl
          << endl;
     BigReal g1("5678.67890");
     BigReal g2("1234.2345");
     BigReal g3("-5678.67890");
     BigReal g4("-1234.2345");
     cout << (g1 > g2) << endl;
     cout << (g1 < g2) << endl;
     cout << (g3 > g4) << endl;
     cout << (g3 < g4) << endl;
     cout << (g1 > g3) << endl;
     cout << (g1 < g3) << endl;
     cout << (g2 > g4) << endl;
     cout << (g2 < g4) << endl;

     cout << endl
          << endl;
     BigReal h1("5678.67890");
     BigReal h2("5678.67890");
     BigReal h3("1234.2345");
     cout << (h1 == h2) << endl;
     cout << (h1 == h3) << endl;
     cout << (h1 != h2) << endl;
     cout << (h1 != h3) << endl;

     cout << endl
          << endl;
     BigReal j;
     // cin >> j;
     cout << j << endl;
     cout << j.sign() << endl;
}
