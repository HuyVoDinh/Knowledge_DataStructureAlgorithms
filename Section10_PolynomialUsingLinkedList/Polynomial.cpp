#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Node
{
    int coeff;
    int exp;
    Node *next;
}*poly = NULL;

void create()
{
    Node *t, *last = NULL;
    int num;
    printf("Enter number of terms");
    scanf("%d",&num);
    printf("Enter each term with coeff and exp\n");

    for(int i = 0; i < num; i++)
    {
        t = new Node();
        scanf("%d%d", &t->coeff, &t->exp);
        t->next = NULL;
        if(poly ==NULL)
        {
            poly = last = t;
        }
        else
        {
            last->next=t;
            last = t;
        }
    }
}

void Display (Node *p)
{
    while(p)
    {
        printf("%dx%d +", p->coeff, p->exp);
        p=p->next;
    }
    printf("\n");
}

long Eval(Node *p, int x)
{
    long val = 0;
    while (p)
    {
        val += p->coeff * pow(x,p->exp);
        p = p->next;
    }
    return val;
}

int main()
{
    create();
    Display(poly);
    printf("\nPoly: %ld\n", Eval(poly,1));
}