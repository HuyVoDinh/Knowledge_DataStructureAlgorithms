#include <stdio.h>

struct Node
{
    Node *lchild;
    int data = 0;
    Node *rchild;
}*root = NULL;


// Searching
/****
 * T(n) = log(n) <= h <= n
 * ***/


// Inserting
void Insert(int key)
{
    Node *t = root;
    Node *r = NULL,*p;

    if(root == NULL)
        {
            p = new Node();
            p->data = key;
            p->lchild = p->rchild = NULL;
            root = p;
            return;
        }
    while (t != NULL)
    {
        r = t;
        if(key < t->data)
            t = t->lchild;
        else if(key > t->data)
            t = t->rchild;
        else
            return;
    }
    p = new Node();
    p->data = key;
    p->lchild = r->rchild = NULL;

    if(key < r->data) r->lchild = p;
    else r->rchild=p;
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

Node *Search(int key)
{
    Node *t = root;
    while(t != NULL)
    {
        if(key == t->data)
            return t;
        else if (key < t->data)
            t = t->lchild;
        else 
            t = t->rchild;
    }
    return NULL;
}

Node *RInsert(Node *p, int key)
{
    if(p == NULL)
    {
        Node *t = new Node();
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data)
        p->lchild = RInsert(p->lchild,key);
    else if(key > p->data)
        p->rchild = RInsert(p->rchild, key);

    return p;
}

/******
 * When deleting any node, then who should take its place? Inorder Predecessor or Inorder Successor should take its place
 * How to find Inorder predecessor or successor?
 * For Inorder Prececessor, for deleting a node go to its left sub-tree. -> left -> right unitl get last node
 * Inorder successor is leftmost child of right sub-tree. -> right -> left until get last node
 * This method to avoid multiple modifications in the trees. 
 * If Inorder Precessor or Successor is not a leaf node then may have to make multiple modifications. 
 * T(n) = O(logn)
 * If Predecessor successor is a leaf node then just one modification. Otherwise there may be more than one modifications. -> That depends on the height again. 
*/ 

int Height (Node *p)
{
    int x,y;
    if(p == NULL) return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x+1 : y+1;
}

Node *InPre(Node *p)
{
    while (p && p->lchild != NULL)
        p = p->lchild;
    return p;
}

Node *InSucc(Node *p)
{
    while (p && p->rchild != NULL)
        p = p->rchild;
    return p;
}

Node *Delete(Node *p, int key)
{
    Node *q;
    if(p == NULL)
        return NULL;
        // When reach the leaf node, delete that node
    if(p->lchild == NULL && p->rchild == NULL)
    {
        if(p == root)
            root = NULL;
        delete p;
        return NULL;
    }
    // Search process
    if(key < p->data)
        p->lchild = Delete(p->lchild, key);
    else if(key > p->data)
        p->rchild = Delete(p->rchild,key);
    else    // mean key is found and this time have to delete a key. 
    {       // Can delete an element by replacing it with the preorder. Can delete an element by replacing it with the Inorder predecessor or successor.
        
        if(Height(p->lchild) > Height(p->rchild))   // This decide based on the height of left sub-tree and the height of right sub-tree. If height of left sub is more, then we'll delete an element from the left hand side. Otherwise we'll delete an element from right hand side. If they're equal can delete from any side. 
        {
            q = InPre(p->lchild);    // should delete an element from left hand side. -> Need Inorder Predecessor.
            p->data = q->data;      // replace
            p->lchild = Delete(p->lchild,q->data);
            
        }
        else
        {
            q = InPre(p->rchild); 
            p->data = q->data;      
            p->rchild = Delete(p->rchild,q->data);
           
        }
    }
    return p;
}

int main()
{
    root = RInsert(root,50);
    RInsert(root,10);
    RInsert(root,40);
    RInsert(root,20);
    RInsert(root,30);

    printf("BST\n");
    Inorder(root);


    printf("\n");
    Node *temp = Search(20);
    if(temp != NULL)
        printf("%d is found\n", temp->data);
    else 
        printf("Element is not found\n");

    Delete(root,50);
    Inorder(root);

    return 0;
}