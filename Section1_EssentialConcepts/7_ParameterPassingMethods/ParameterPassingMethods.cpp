/***
 * [Parameter Passing methods]
 * [Pass by Value]
 * 
 * void swap(int x, int y)
 * {
 *      int temp;
 *      temp = x;
 *      x = y;
 *      y = temp;
 * }
 * 
 * int main()
 * {
 *      int a, b;
 *      a = 10;
 *      b = 20;
 *      swap(a,b);
 * }
 * 
 * <ParameterPassingMethods.png>
 * 
 * -> Pass by value: formal parameters are modified but actual parameters remain same. So the swapping is done inside the variables of swap function only, they are not reflected inside actual parameter. 
 * So when the function ends after this line, when it comes back here, there is nothing return, it is void type, then print, a = 10, b = 20. So these values are not swapped. 10 and 20 were passed and with the help of temp, this became 20 and this became 10. But actual parameters, they are same only. 
 * In pass by value, any changes are done to formal parameters will not reflect in actual parameters. So when you should use Pass by Value? When you don't have to modify actual parameters, you can use Pass by Value. 
 * And you can use Pass by Value if a function is returning some results. So swap function should not be written using Pass by Value. 
 * But here Pass by Value is not suitable for swapping two numbers. In Pass by Value, actual parameters will not be modified if any changes are done to formal parameters. 
 * 
 * 
 * [Pass by Address]
 * 
 * void swap(int *x, int *y)
 * {
 *      int temp;
 *      temp = *x;
 *      *x = *y;
 *      *y = temp;
 * }
 * 
 * int main()
 * {
 *      int a, b;
 *      a = 10;
 *      b = 20;
 *      swap(&a,&b);
 * }
 * 
 * <ParameterPassingMethods2.png>
 * 
 * The addresses of actual parameters are passed to formal parameters and formal parameters must be pointer. Any changes is done inside a function will modify actual parameters. 
 * Need * for accessing the data of actual parameters. Addresses must be passed. So this function can access the variables of another function. It's not directly, it is indirectly using pointers. 
 * One function cannot access the variables of another function directly but it can access using pointers so it can access indirectly. Now variables are modified.
 * So when the functions ends, control comes back, and when it prints the value a = 20, b = 10. 
 * Call by address is suitable mechanism for modifying the actual parameters. Sp will be using this type of code more frequently in our programs. 
 * 
 * 
 * [Call by reference]
 * 
 * 
 * void swap(int &x, int &y)
 * {
 *      int temp;
 *      temp = x;
 *      x = y;
 *      y = temp;
 * }
 * 
 * int main()
 * {
 *      int a, b;
 *      a = 10;
 *      b = 20;
 *      swap(a,b);
 * }
 * 
 * <ParameterPassingMethods3.png>
 * Call by reference: Only in the parameters, just before parameter name, or variable name, is &. 
 * Swap function is called by passing A and B, A and B are passed to X and Y. So X becomes a reference to A and Y becomes a reference to B, and reference is nothing but alias or another name or a nickname to a variable. 
 * So this itself is X and that itself is Y, does it take any memory? References doesn't take any memory. Existing variable, another name is given. Yes so that doesn't take any extra memory. 
 * The actual parameters are modified. 
 * one function cannot access the variables of another function directly, it can access indirectly. In memory, swap is not a separate function. 
 * Swap is not a separate function it has became a part of main function and there is only one activation stack.
 * So this swap is not a separate body of a function, it has became a part of the main function. So it means that a machine code of the swap function will be pasted here. 
 * The entire code inside a single main function only, so the machine code is monolithic. Though the source code is procedural or modular. 
 * Can use call by Reference for small functions. Don't use it for heavy functions which are having loops and all having complex logic. 
 * 
 * ****/

#include <iostream>
using namespace std;
//pass be value
int add(int a, int b)
{
    int c;
    c = a + b;
    a++;        // is not change
    cout << a;
    return c;
}

void swap1(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swap2(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{

    int num1 = 10, num2 = 15, sum;
    sum = add(num1,num2);
    cout << "Sum is " << sum;
    
    swap1(&num1, &num2);
    cout << num1 << " - " << num2 << endl;

    swap2(num1, num2);
    cout << num1 << " - " << num2 << endl;
    return 0;
}