/***
 * [Indirect Recursion]
 * There may be more than one function and thay are calling one another in a circular function so if the first function calls second one, and the third one again call back first function then it becomes a cycle.
 * 
 * void funcA(int n)
 * {
 *      if(n > 0)
 *      {
 *          printf("%d",n);
 *          funcB(n-1);
 *      }
 * }
 * 
 * void funcB(int n)
 * {
 *      if(n > 1)
 *      {
 *          printf("%d",n);
 *          funcA(n/2);
 *      }
 * }
 * <IndirectRecursion.png>
 * ** */

#include <stdio.h>
void funcA(int n)
{
    if (n > 0)
    {
        printf("%d ",n);
        funcB(n-1);
    }
}

void funcB(int n)
{
    if (n > 1)
    {
        printf("%d ", n);
        funcA(n/2);
    }
}

int main()
{
    funcA(20);
    return 0;
}