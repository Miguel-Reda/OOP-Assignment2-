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

//                                                    just nots

/*
Test your class with a small application and 12 test cases that test all these functions.
Each team member will take one of the parts of the class after designing it carefully together.
Work must be integrated in one working program.

1. Please note the following
- Using data encapsulation. Decide on a suitable container for storing the content of the
  number. Study the different options and find the efficient and elegant one to use in terms of
  (1) memory used and (2) suitable attributes and (3) speed of developing the program.
  Possible options include string, dynamic array, vector, or other containers in STL. These are
  details that are not important to the user of your class. This is called encapsulation or data
  hiding. You will need to build + and – operations that work on the representation you chose.
  The user does not care about which algorithm you use as long as it works. This is called
algorithm hiding.
- Signs might be added to the number at initialization, but only –ve sign is printed. You may
  like keep this information about the sign in a separate attribute.

 +111111111111111111.0000000000000000000000011111111111       // valid
 -.0000000000000099999999999999911111111111111111999999       // valid
 + 00099.999                                                  // invalid
 +-999000000                                                  // invalid
 99900.011111                                                 // valid
 Both addition and subtraction should consider +v end –ve cases.

*/

int main()
{
  // BigReal n1("11.9000000000000000000000000000000001");
  // BigReal n2("2333333333339.1134322222222292");
  // BigReal n3 = n1 + n2;
  // cout << n3;
  // n3 = n3 + BigReal(0.9);
  BigReal n1("99");
  BigReal n2("99");
  BigReal n3 = n1 + n2;
  cout << n3 << endl;
  cout << n3.DecimalSize() << endl;
  // cout << n1 << endl;
  // n1.setNum("99.001");
  // cout << n1 << endl;
  // BigReal n2;
  // cin>>n2;
  // BigReal n2("+99.0");
}
