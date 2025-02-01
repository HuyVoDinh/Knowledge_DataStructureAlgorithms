/***
 * [Tree Recursion]
 * Linear Recursion
 * func(n)
 * {
 *      if(n > 0)
 *      {
 *          .......... 
 *          func(n-1)
 *          ..........
 *      }
 * }
 * 
 * A function that is recursive function if it is calling itself only one time. 
 * 
 * func(n)
 * {
 *      if(n > 0)
 *      {
 *          .......... 
 *          func(n-1)
 *          ..........
 *          func(n-1)
 *          .......... 
 *      }
 * }
 * Tree recursion: If a function that is recursive function is calling itself more than one time. 
 * 
 * void func(int n)
 * {
 *      if(n > 0)
 *      {
 *          printf("%d", n);
 *          func(n-1)
 *          func(n-1)
 *      }
 * }
 * <TreeRecursion1.png>
 * Space complexity depends on that is the maximum height of the stack, because total activation records depends on number of calls, but how much space it was occupying inside the stack. 
 * So you have observed that same space was reused inside the stack. One activation record was gone and in the same place, another activation record was created.  
 * *** */
#include <stdio.h>

void func(int n)
{
    if (n > 0)
    {
        printf ("%d ",n);
        func(n-1);
        func(n-1);
    }
}

int main()
{
    func(3);
    return 0;
}