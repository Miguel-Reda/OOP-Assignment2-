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
/* int string_to_num(string x)
{
  int n = 0;
  for (int i = 0; i < x.size(); i++)
  {
    if (x.at(i) != '-')
    {
      n = n * 10 + (x.at(i) - '0');
    }
  }

  if (n != 0 && x.at(0) == '-')
  {
    n = -n;
  }
  return n;
}
 */

/*

Different variations of types int and float exist in C++ and other languages. They are limited
by minimum and maximum values depending on the number of bytes used to store the number. We
need versions of these types with unlimited bounds. Java solves this problem by providing
BigInteger and BigDecimal classes. In this problem it is required to develop a a class
BigReal. An object of this class represents a real number of any arbitrary length. The public
interface of your class will be as follows. For functions where default implementation of C++ is
enough and works fine, you do not need to re-implement them. You are free to store the parts of the
real number in any way like string, array or vector. The team should decide and agree on the
data members of the class. You should have suitable data members to store the integer and the
fraction parts, the sign, the place of the decimal point (if needed) and the size (if needed) and any
other info.

Break your code into: header file, implementation file and application file.
*/

/*
It is required to separate your design into a header file and an implementation file. You should also
validate that the passed parameter in case of string is a valid real number. Note that 1. and .1 are
valid real numbers but 1.1.1 is not valid real number.

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
  BigReal n1("+99.00");
  BigReal n2("+99.00010");
  cout << (n1 > n2) << endl;
  // cout << n2;
}