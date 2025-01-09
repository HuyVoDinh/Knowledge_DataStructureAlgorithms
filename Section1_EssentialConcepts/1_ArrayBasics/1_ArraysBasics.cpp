/****
 * [Array]
 * 
 * Arrays are defined as a collection of similar data elements.
 * If you have some set of integers or set of floats, you can group them under one name as an array.
 * <ArrayBasic1.png>
 * 
 * int main()
 * {
 *      int A[5];
 *      int B[5] = {2,4,6,8,10};
 * }
 * 
 * The main run Inside the main memory.
 * Array will be created here inside the stack.  This is where the array will be created and that array will be directly accessible to the main function. 
 * Directly can store the value.
 * 
 * Array B will be created and it will be already
 * ***/

#include <iostream>

using namespace std;

int main()
{
    int A[5];       // The memory this array will take depends on the size of integer. Compilers take 4 bytes for integer.
    A[0] = 12;
    A[1] = 15;
    A[2] = 25;

    cout << sizeof(A) << endl;
    cout << A[1] << endl;
    cout << A[3] << endl;

    for(int i = 0; i < 5; i++)
    {
        cout << A[i] << endl;
    }

    for(int x : A){
        cout << x << endl;
    }
    return 0;
}