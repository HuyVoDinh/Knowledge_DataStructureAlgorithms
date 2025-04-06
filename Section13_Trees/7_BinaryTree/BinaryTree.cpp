#include <stdio.h>
#include "Queue.h"
#include "Stack.h"

struct Node *root = NULL;

void TreeCreate()
{
    Node *p,*t;
    int x;
    Queue q;
    create(&q,100);

    printf("Enter root value ");
    scanf("%d", &x);
    root = new Node();
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q,root);

    while(!isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter left child of %d ", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = new Node();
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q,t);
        }

        printf("Enter right child of %d ", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = new Node();
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q,t);
        }
    }
}

void preorder(Node *p)
{
    if(p)
    {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void Inorder(Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

// Iterative Tree Traversals
void Postorder(Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        Inorder(p->rchild);
        printf("%d ", p->data);
    }
}

void IPreorder(Node *p)
{
    Stack stk;
    StackCreate(&stk,100);

    while(p || !isEmptyStack(stk))
    {
        
        if(p)
        {
            printf("%d", p->data);
            push(&stk,p);
            p=p->lchild;
        }
        else
        {
            p=pop(&stk);
            p=p->rchild;
        }
    }
}

void IInorder(Node *p)
{
    Stack stk;
    StackCreate(&stk,100);

    while(p || !isEmptyStack(stk))
    {
        
        if(p)
        {
            push(&stk,p);
            p=p->lchild;
        }
        else
        {
            p=pop(&stk);
            printf("%d ", p->data);
            p=p->rchild;
        }
    }
}

void LevelOrder(Node *p)
{
    Queue q;
    create(&q, 100);
    printf("%d ", p->data);
    enqueue(&q,root);
    while(!isEmpty(q))
    {
        root = dequeue(&q);
        if(root->lchild)
        {
            printf("%d ", root->lchild->data);
            enqueue(&q, root->lchild);
        }
        if(root->rchild)
        {
            printf("%d ", root->rchild->data);
            enqueue(&q, root->rchild);
        }
    }
}

// Generate tree from traversals
/***
 * Example:
 * n = 3. A B C
 * preorder - A B C
 * From preorder, if try to generate a tree, 5 trees are possible for 3 elements. Actually, we want 1 unique tree, so cant generate a tree. We cant find out because there are multiple trees are possible, which are giving same preorder for 3 elements. 
 * So conclusion is if only preorder is given
 * Preorder = 2nCn/n+1
 * Postorder - C B A
 * 
 * So if give preorder and postorder also, more than one trees can have same preorder and postorder. We just need 1 single tree.
 * Solution:
 * Preorder + Inorder
 * Inorder + Preorder
 * Why InOrder? -> Because Inorder will take the root in the middle. So first it gives left then root, then right.
 * Inorder can help if know the root then what should go on left size, what should go on right side.  It can help decide the splitting of nodes in the left subtree or right subtree. That why inorder is mandatory.  
 * 
 * 
 * Preorder - 4, 7, 9, 6, 3, 2, 5, 8, 1
 * Inorder - 7, 6, 9, 3, 4, 5, 8, 2, 1
 * 1. Create a Node
 * 2. Take all the elements of in order, take an order as it is in the node. Dont change the order. Write the elements in the same order. : 7, 6, 9, 3, 4, 5, 8, 2, 1   (1)
 * 3, Repeating procedure, scan through pre-order by taking one element at a time. Then what to do with each element? 
 * 3.1 Take the first element from left to right. First in the element is root -> 4 is root. Search 4 in (1) -> Found, take 4 in one node, this is root. 
 * 3.2 7, 6, 9, 3 on the left-hand size. 5, 8, 2, 1 on the right-hand size.
 * .............
 * 
 * Time: O(n^2)
 * ***/



int main() 
{
    TreeCreate();
    printf("\nLevel order ");
    LevelOrder(root);
    return 0;
}