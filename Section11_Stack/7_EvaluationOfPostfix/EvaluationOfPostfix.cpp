/***
 * [Evaluation to postfix]
 * 3*5+6/2-4    = 15 + 3 - 4    =   18 - 4 = 14
 * Postfix: 35*62/+4-
 * 
 * Need a stack, scan through postfix expression by taking one symbol at a time and while scanning. 
 * 
 * stack: 3
 * 
 * stack: 3, 5
 * 
 * If get any operator, pop outs (*)
 * -> 3 * 5 = 15 -> then push into the stack
 * stack: 15, 6, 2
 * 
 * pop outs(/) 6/2 -> push into the stack
 * stack 15, 3
 * 
 * pop outs(+) 15 + 3 -> push into the stack
 * stack: 18
 * 
 * 
 * stack 18, 4
 * 
 * pop ous (-) 18 - 4 -> push into the stack
 * 
 * stack 14
 * 
 * end
 * 
 * Symbol   |   stack   | Operation
 * 3        |   3       |
 * 5        |   5,3     |
 * *        |   15      | 3*5=15
 * 6        |   6,15    |
 * 2        |   2,6,15  |
 * /        |   3,15    | 6/2=3
 * +        |   18      | 15+3=18
 * 4        |   4,18    |
 * -        |   14      | 18-4=14
 * 
 * 
 * --------------------------------
 * 6 + 5 + 3 *4
 * postfix: 65+34*+
 * -> Issue: 6+5 (executed first) -> That precedences and associativity are meant for parenthesization. They dont decide who will execute first. 
 * They wont decide which operator should execute first. 
 * It shows who should be parenthesized. 
 * ((6+5)+(3*5))
 * -> 6+5 will evaluate first
 * Plus one was executed but when it is not parenthesized, highest precedents that will execute first. Not necessary. Unless know complete parenthesis expression. -> Which bracket has to execute first. Tahat bracket will be executed or that operation will be executed. 
 * This is one interesting fact that precedents and associativity are meant for parenthesization, not for execution. 
 * ****/

#include <stdio.h>
#include <string.h>
#include <iostream>
struct Node
{
    int data;
    Node *next;
}*top = NULL;

void push(int x)
{
    Node *t;
    t = new Node();
    if(t == NULL)
        printf("Stack is full\n");
    else
    {
        t->data = x;
        t->next  = top;
        top = t;
    }
}

int pop()
{
    Node *t;
    int x = -1;
    if(top == NULL)
        printf("Stack is empty\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void Display()
{
    Node *p;
    p = top;
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int isOperand(char x)
{
    if(x == '+' ||x == '-' || x == '*'  ||x == '/' )
        return 0;
    return 1;
}

int pre(int x)
{
    if(x=='+' || x == '-')
        return 1;
    else if(x== '*' || x == '\\')
        return 2;
    return 0;
}

int *InToPost(char*infix)
{
    int *postfix;
    int len = strlen(infix);
    postfix= new int(len+2);
    int i = 0, j = 0;

    while(infix[i]!= '\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(pre(infix[i])>pre(top->data))
                push(infix[i++]);
            else
            {
                postfix[j++] = pop();
            }
        }
    }

    while(top != NULL)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int Eval(char *postfix)
{
    
    int x1,x2,r;
    for(int i = 0; postfix[i] != '\0'; i++)
    {
        if(isOperand(postfix[i]))
        {
            push(postfix[i]-'0');
        }
        else
        {
             x2 = pop();
             x1 = pop();
             switch (postfix[i])
             {
             case '+': r=x1+x2; break;
             case '-': r=x1-x2; break;
             case '*': r=x1*x2; break;
             case '/': r=x1/x2; break;
             
             default:
                break;
             }
             push(r);
        }
    }
    return top->data;
}

int main()
{
    char *postfix = "234*+82/-";
    
    printf("Result: %d ", Eval(postfix));
    return 0;
}