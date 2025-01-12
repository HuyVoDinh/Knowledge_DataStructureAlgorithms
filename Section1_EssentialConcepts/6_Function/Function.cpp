/***
 * [Function]
 * 
 * Parameter Passing:
 *  Pass by Value
 *  Pass by Address
 *  Pass by Reference
 * 
 * Structure is a group of related data members. Now function is a group of related instructions which perform a specific task. 
 * So, grouping data is a structure, grouping instructions is a function. 
 * Functions are called as modules or procedures. See, instead of writing a single main program, writing everything inside the main function, we can break the main function into small manageable size pieces and we can separate the repeating tasks or smaller tasks. 
 * 
 * Monolithic programming: everything inside a single body. 
 * Modular programming/procedural programming: Breaking a program into smaller pieces of functions and using those functions inside the main function that is integrating them all together.
 * 
 * In modular programming, can break the program into smaller tasks and can focus on smaller tasks and finish them and make them perfect. It's easy for one single individual to develop the application. Even can break this software project into a team of programmers. Then only person has to develop this one. 
 * A group of programmers can develop a single application like some people are developing. Some functions like one person developing this one, second person, third person, and one of the person who's a team leader can integrate all of them inside the main function. 
 * This style of programming has increased productivity and also re-usability. 
 * 
 * int add (int a, int b)           -> 1. prototype or signature of a function,     => a, b is copied from where it was called. 
 * {
 *      int c;
 *      c = a + b;
 *      return c;                   -> when the function returns it will come back to the line from where it was called. The result of the function is 15.
 * }
 * 
 * int main()                       
 * {
 *      int x, y, z;
 *      x = 10;
 *      y = 5;
 *      z = add(x,y);               -> 2. two values x and y to this function, which is taking 2 parameters. SO these parameters, the one which we are passing, these are called as actual parameters. These parameters which are taken by this function, called formal parameters. 
 *      cout << "Sum: " << z << endl;
 * }
 * 
 * <>
 * 
 * The function will have its own activation record, its separate set of variables will be there inside the memory, and when it is called they are created, and when their function terminates they are destroyed. 
 * This function cannot access the variables of main and main cannot access the variables of this add function. One function cannot access the variables of another function. 
 * It means that I cannot use x y z here inside add function because they belong to main function and I cannot use a, b, c inside main function because they belong to add function. So that
 * 
 * ***/

#include <iostream>
using namespace std;

int add(int a, int b)
{
    int c;
    int c = a + b;
    return c;
}

int main()
{
    int num1 = 10, num2 = 15, sum;
    sum = add(num1, num2);

    cout << sum << endl;

    return 0;
}