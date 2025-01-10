/***
 * [Reference]
 * 
 * A reference is a nickname given to a variable or alias given to a variable. 
 * 
 * int main()
 * {
 *      int a = 10;         -> This is main function, inside the code section, and inside its stack frame there is a variable having value name A and with value 10.
 *      int &r = a;             -> Inside this I want to have a reference to that variable A. So the method of declaring reference is int r; r is a reference. write ampersand(&) to reference
 *                              -> assign with a -> referring to A. This means, this A itself is called as r.  Now you have 2 names for the same value inside the memory. it means if that variable A is occupying 4 bytes of memory, let's say 200 is the address and 203 and value = 10. And r variable same too. 
 * 
 *      cout << a; // 10
 *      r++;        // if r++ this means this value is increased to 11 because the same value is r now. So address of r is also 200. 
 *      cout << r;  // 11
 *      cout << a;  // 11   -> a reference is nothing but another name to a variable. 
 * }
 *  <Reference1.png>
 * Why need another name to the same variable? -> This is useful in parameter passing, and this is a very useful feature of C++ -> we use references instead of using pointers. 
 * 
 * 
 * ***/

#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int &r = a;
    a = 25;

    int b = 30;
    r = b;
    cout << a << endl << r << endl;
}