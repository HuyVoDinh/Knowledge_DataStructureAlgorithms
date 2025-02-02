/***
 * fib(n) = 0                     n = 0
 *        = 1                     n = 1
 *        = fib(n-2) + fib (n-1)  n > 1  
 * 
 * f(5) = 15 times called
 * f(4) = 9 times called
 * f(3) = 5 times called
 * fib(n-2) + fib (n-1) <=> 2fib(n-1) = O(2^n)
 * 
 * How to make it faster?
 * They are also called multiple times. So a recursive function is calling itself multiple times for the same values.
 * So such a recursive function is called as excessive recursion. 
 * To void them and just make a call only once, and itilize it in further calls?
 * Take of static variable or global variables.  
 * Create a global array or static array, and initialize it with minus one. 
 * Minus one means we don't know the value 
 * <FibonacciSeriesUsingRecursion-Memoization.png>
 * F(5) = -1 -> call F(3) = -1 -> Call F(1) = -1 -> F(1) = 1
 *                             -> Call F(2) = -1 -> F(0) = 0, F(1) = 1 (skip call), F(2) = F(0) + F(1) = 1 
 *                             -> F(3) = F(1) + F(2) = 2
 *           -> Call F(4) = -1 -> Call F(2) (skip) 
 *                             -> Call F(3) (skip)
 *                        = F(2) + F(3) = 3  
 * O(n)
 * ** */
#include <stdio.h>


int fib(int n)
{
    int t0 = 0, t1=1,s,i;
    if(n <= 1) return n;
    for(int i = 0; i <= n; i++)
    {
        s = t0+t1;
        t0=t1;
        t1=s;
    }
    return s;
}

int rfib(int n)
{
    if (n <= 1) return n;
    return rfib(n-2)+rfib(n-1);
}

int F[10];

int mfib(int n)
{
    if(n<=1)
    {
        F[n] = n;
        return n;
    }
    else 
    {
        if(F[n-2] == -1)
            F[n-2] = mfib(n-2);
        if (F[n-1] == -1)
            F[n-1] = mfib(n-1);
        F[n] = F[n-2] + F[n-1]
        return F[n];
    }
}

int main()
{
    for(int i = 0; i < 10; i++)
    {
        F[i] =-1;
    }
    rfib(10);
    return 0;
}