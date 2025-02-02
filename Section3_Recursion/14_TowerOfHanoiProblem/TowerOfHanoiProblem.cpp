/***
 * TOH(1,A,B,C)
 *  Move disk from A to C using B
 * 
 * TOH(2,A,B,C)
 *  TOH(1,A,C,B)
 *  Move disk from A to C using B
 *  TOH(1,B,A,C)
 * 
 * TOH(3,A,B,C)
 *  TOH(A,C,B)
 *  Move disk from A to C using B
 *  TOH(2,B,A,C)    
 * 
 * TOH(n,A,B,C)
 *  TOH(n-1,A,C,B)
 *  Move disk from A to C using B
 *  TOH(n-1,B,A,C)
 * 
 * <TowerOfHanoiProblem.png>
 * n=3 15 call  = 1+2+2^2+2^3= 2^4-1
 * n=2 7 call
 * 
 * 1+2+2^2+...2^n= 2^(n+1) -1 => O(2^n)
 * 
 * *** */

#include <stdio.h>
void TOH(int n, int A, int B, int C)
{
    if(n>0)
    {
        TOH(n-1, A,C,B);
        printf("(%d,%d)\n",A,C);
        TOH(n-1,B,A,C);
    }
}

int main()
{
    TOH(3,1,2,3);
    return 0;
}