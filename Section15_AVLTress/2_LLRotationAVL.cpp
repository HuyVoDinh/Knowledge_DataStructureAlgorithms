#include <stdio.h>

struct Node
{
    Node *lchild;
    int data;
    int height;
    Node *rchild;
}* root = NULL;

int NodeHeight(Node *p)
{
    int hl,hr;
    hl = p&& p->lchild ? p->lchild->height:0;
    hl = p&& p->rchild ? p->rchild->height:0;

    return hl>hr? hl+1:hr+1;
}

int BalanceFactor(Node *p)
{
    int hl,hr;
    hl = p&& p->lchild ? p->lchild->height:0;
    hl = p&& p->rchild ? p->rchild->height:0;
    return hl-hr;
}

Node *LLRotation(Node *p)
{
    Node * pl = p->lchild;
    Node * plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root == p)
        root = pl;
    return pl;
}

Node * LRRotation (Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->rchild = pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if(root == p)
        root = plr;

    return plr;
}

Node *RRRotation(Node *p)
{
    Node * pl = p->rchild;
    Node * plr = pl->lchild;

    pl->lchild = p;
    p->rchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root == p)
        root = pl;
    return pl;
}

Node *RLRotation (Node *p)
{
    Node *pl = p->rchild;
    Node *plr = pl->lchild;

    pl->lchild = plr->rchild;
    p->rchild = plr->lchild;

    plr->lchild = pl;
    plr->lchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if(root == p)
        root = plr;

    return plr;
}

Node *RInsert(Node *p, int key)
{
    Node *t = NULL;
    
    if (p==NULL)
    {
        t = new Node();
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if(key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if(key > p->data)
        p->rchild = RInsert(p->rchild,key);
    p->height = NodeHeight(p);

    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LLRotation(p);
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
        return RRRotation(p); 
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == 1)
        return RLRotation(p); 
    return p;
}

int main()
{
    root = RInsert(root,50);
    RInsert(root, 10);
    RInsert(root, 20);
    

}