#include <stdio.h>

double e(int x, int n)
{
    static double s;
    if (n == 0)
        return s;
    s = 1+x*s/n;
    return e(x,n-1);
}

double e_loop(int x, int n)
{
    double result = 1;
    double num=1;
    double den=1;
    for(int i = 0; i <= n; i++)
    {
        num*=x;
        den*=i;
        result+=num/den;
    }
    return result;
}

int main()
{
    printf("%lf\n", e(2,10));
}