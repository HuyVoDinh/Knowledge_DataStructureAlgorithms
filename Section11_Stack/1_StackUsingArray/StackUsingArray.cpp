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

struct Stack
{
    int size;
    int top;
    int *S;
};

void create(Stack *st)
{
    printf("Enter size: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = new int();
}

void Display(Stack st)
{
    for(int i = st.top; i >= 0; i--)
    {
        printf("%d ", st.S[i]);
    }
    printf("\n");
}

void push(Stack *st, int x)
{
    if(st->top == st->size-1)
        printf("Stack overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(Stack *st)
{
    int x =-1;
    if(st->top == -1)
        printf("Stack overflow\n");
    else
    {
        x=st->S[st->top--];
    }
    return x;
}

int peak(Stack st, int index)
{
    int x =-1;
    if(st.top-index < 0)
        printf("Invalid index\n");
    x = st.S[st.top-index+1];

    return x;
}

int isEmpty(Stack st)
{
    if(st.top == -1)
        return 1;
    return 0;
}

int isFull(Stack st)
{
    return st.top == st.size-1;
}

int stackTop(Stack st)
{
    if(!isEmpty(st))
        return st.S[st.top];
    return -1;
}

int main()
{
    Stack st;
    create(&st);

    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);

    Display(st);

    printf("Pop: %d\n", pop(&st));
    printf("Peak: %d\n", peak(st,2));
    return 0;
}