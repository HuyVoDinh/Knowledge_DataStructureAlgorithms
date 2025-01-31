/***
 * [Static and Global Variables In Recursion]
 * 
 * int func(int n)
 * {
 *      if(n > 0)
 *      {
 *          return func(n-1) + n;
 *      }
 * }
 * 
 * void main()
 * {
 *      int a = 5;
 *      cout << func(a);
 * }
 * 
 * <6_StaticAndGlobalVariablesInRecursion1.png>
 * <6_StaticAndGlobalVariablesInRecursion2.png>
 * 
 * int func(int n)
 * {
 *      static int x = 0;
 *      if(n > 0)
 *      {
 *          x++;
 *          return func(n-1) + n;
 *      }
 * }
 * static will not be created every time. When the function is called, it is created only one time that is at the loading time of a program. 
 * SO this x, will not have multiple copies, just like n, it will have a single copy.  
 * <6_StaticAndGlobalVariablesInRecursion3.png>
 * <6_StaticAndGlobalVariablesInRecursion4.png>
 * 
 * int x = 0;
 * int func(int n)
 * {
 *      if(n > 0)
 *      {
 *          x++;
 *          return func(n-1) + n;
 *      }
 * }
 * Result will be same. Static variable will have a sngle copy and even global variable . It will have a single copy used by all the function calls
 * *** */
#include <stdio.h>

int func(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x++;
        return func(n-1)+n;
    }
    return 0;
}

int main(){
    int r;
    r = func (5);
    printf("%d\n" ,r);
    return 0;
}