/***
 * [Nested Recursion]
 * A recursive function will pass parameter as a recursive call.
 * A recursive function and it is calling itself but parameter itself is a recursive call. 
 * Means unless the result of this recursive call is abtained, this call cannot be made. 
 * A recursive call is taking a recursive call as a parameter. 
 * So this is recursion inside recursion
 * 
 * int func(int n)
 * {
 *      if(n > 100)
 *          return n-10;
 *      else 
 *          return func(func(n+11));
 * }
 * 
 * func(95); 
 * <NestedRecursion.png>
 * ** */

#include <stdio.h>

int func(int n)
{
    if (n > 100)
        return n-10;
    return func(func(n+11));
}

int main()
{
    int r;
    r = func(30);
    printf("%d\n",r);
    return 0;
}