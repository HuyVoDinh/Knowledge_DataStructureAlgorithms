#include <stdlib.h>
#include <malloc.h>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct  Node*next;
};

class HashTable
{
    private:
    public:
        Node **HT;
    private:
        int hash(int key);
    public:
        HashTable();
        ~HashTable();
        void Insert(int key);
        Node *Search(int key);
        void Delete(int key);
};

HashTable::HashTable()
{
    printf("Init HashTable - Start\n");
    HT = new Node*[10];
    for(int i = 0; i < 10; i++)
    {
        HT[i] = nullptr;
    }
    printf("Init HashTable - End\n");
}

HashTable::~HashTable()
{
    for(int i = 0; i < 10; i++)
    {
        Node *p = HT[i];
        while(HT[i])
        {
            HT[i] = HT[i]->next;
            delete p;
            p = nullptr;
            p = HT[i];
        }
    }
    delete HT;
    HT = nullptr;
}

int HashTable::hash(int key)
{
    int hashKey = key%10;
    printf("Key: %d -> hash: %d\n", key, hashKey);
    return hashKey;
}

void HashTable::Insert(int key)
{
    printf("Insert - Start\n");
    int hashKey = hash(key);
    Node *p = HT[hashKey];
    Node *q = nullptr;

    Node *newNode = new Node;
    newNode->data = key;
    newNode->next = nullptr;

    if(HT[hashKey] == nullptr)
    {
        HT[hashKey] = newNode;
    }
    else
    {
        while(p && p->data < key)
        {
            q = p;
            p = p->next;
        }
        if(p == HT[hashKey])
        {
            newNode->next = HT[hashKey];
            HT[hashKey] = newNode;
        }
        else
        {
            newNode->next = p;
            q->next = newNode;
        }
    }
    printf("Insert - End\n");
}

Node *HashTable::Search(int key)
{
    printf("Search: %d - Start\n", key);
    Node *p;
    p = HT[hash(key)];
    while(p && p->data != key)
    {
        p = p->next;
    }
    printf("Search - End\n");
    return p;
}

void HashTable::Delete(int key)
{
    printf("Delete: %d - Start\n", key);
    int hashkey = hash(key);
    Node *p ;
    Node *q;
    p = HT[hashkey];
    if(HT[hashkey] == nullptr)
    {
        printf("Delete - End\n");
        return;
    }
    else
    {
        while(p && p->data != key)
        {
            q = p;
            p = p->next;
        }

        if(p == HT[hashkey])
        {
            HT[hashkey] = HT[hashkey]->next;
        }
        else
        {
            q->next = p->next;
            delete p;
        }
    }
    printf("Delete - End\n");
}