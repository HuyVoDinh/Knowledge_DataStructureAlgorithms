/***
 * a + b * c - d / e
 * Syb      |   Pre     | Asso
 * +,-      |   1       | L-R
 * *,/      |   2       | L-R
 * -> postfix: a
 * stack: +
 * 
 * -> postfix: ab
 * stack: +*
 * 
 * -> postfix: abc*             //(pre: * > 0)
 * stack: +
 * 
 * -> postfix: abc*+
 * stack: 
 * 
 * Topmost value is plus and its precedence is equal. Then also pop out and send it to postfix. It means if it is an operator, should push it into the stack,and before pushing, check what are the operators present in the stack. 
 * If the operators in the stack have lower precedence, then push that one, otherwise pop out.
 * -> postfix: abc*+
 * stack: 
 * 
 * -> postfix: abc*+
 * stack: -
 * 
 * -> postfix: abc*+d
 * stack: -/
 * 
 * -> postfix: abc*+de
 * stack: -/
 * 
 * End of expression, have reached the end onf the expression. Whatever is there in the stack, empty it and go on adding the contents to the end of postfix. 
 * -> postfix: abc*+de/-
 * stack: 
 * 
 * 
 * ////////////////////////////////////////////
 * Method 2
 * a + b * c - d / e
 * Syb      |   Pre     | Asso
 * +,-      |   1       | L-R
 * *,/      |   2       | L-R
 * a,b,c    |   3       | L-R
 * 
 * -> postfix: 
 * stack: a
 * 
 * -> postfix: a
 * stack: 
 * 
 * -> postfix: a
 * stack: +b
 * 
 * -> postfix: ab 
 * stack: +*
 * 
 * -> postfix: ab 
 * stack: +*c
 * 
 * -> postfix: abc*+
 * stack: -
 * 
 * -> postfix: abc*+
 * stack: -d
 * 
 * -> postfix: abc*+d
 * stack: -/
 * 
 * -> postfix: abc*+d
 * stack: -/e
 * 
 * -> postfix: abc*+de/-
 * stack: 
 * ****/

#include <stdio.h>
#include <string.h>

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
    if(x == '+' ||x == '-' || x == '*'  ||x == '\\' )
        return 0;
    return 1;
}

int pre(char x)
{
    if(x=='+' || x == '-')
        return 1;
    else if(x== '*' || x == '\\')
        return 2;
    return 0;
}

char *InToPost(char*infix)
{
    char *postfix;
    int len = strlen(infix);
    postfix= new char(len+2);
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

int main()
{
    char *infix = "a+b*c";
    push('#');
    char *postfix = InToPost(infix);
    printf("%s ", postfix);
    return 0;
}