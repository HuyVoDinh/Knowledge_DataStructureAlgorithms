/***
 * ((a+b) * (c-b))
 * We need find out whether the parenthesis are balanced or not. Means for every opening parenthesis, there must be a closing parenthesis. 
 * This is what we want to check. For every opening bracket, there must be a closing bracket. 
 * For checking this, a stack can be used. Find out whether the parenthesis are balanced or not.
 * First: Opening bracket. Push it into the stack. If it is opening bracket, push it into the stack. 
 * Second: Also opening bracket. Push it into the stack. 
 * Next symbol is A. It's neither opening bracket nor closing bracket, some other letter, just ignore it and move ahead. So it means if you're getting opening or closing bracket, then only you have to respond. Otherwise just move ahead. 
 * ....
 * Next: Got a closing bracket. Whenever we get a closing bracket, pop out a bracket from the stack. Dont push that closing bracket in the stack. It means we found a match. 
 * ......
 * have reached the end of an expression. And check the stack. Stack is empty. So it means the parentheses are matching. 
 * ***/

/***
 * Need a fixed size array. 
 * Then need a top pointer to point on the top most element because it is pointing on the index whichever is the recently inserted element there it'll be pointing. 
 * Then this array depends what type of values you are storing in this one. 
 * So we need total 2 things:
 * + array of some size
 * + Top pointer
 * 
 * inside the stack we insert and delete the element from same end insertion is also done from top and deletion is also done from top. 
 * **/

#include <stdio.h>

struct Node
{
    char data;
    Node *next;
}*top = NULL;

void push(char x)
{
    Node *t = new Node();
    if(t == NULL)
        printf("Stack overflow\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char pop()
{
    char x =-1;
    Node *t;
    if(top == NULL)
        printf("Stack overflow\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

int isBalanced(const char *exp)
{
    for(int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(')
            push(exp[i]);
        else if(exp[i] == ')')
        {
            if(top == NULL)
                return 0;
            pop();
        }
    }
    if(top == NULL)
        return 1;
    else 
        return 0;
}

int main()
{
    const char *exp = "((a+b)*(c-d))";
    printf("%d\n", isBalanced(exp));
    return 0;
}