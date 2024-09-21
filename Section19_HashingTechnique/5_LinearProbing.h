#define SIZE 10
#include <stdio.h>

class LinearProbing
{
    private:
    public:
        int HT[SIZE] = {0};
    private:
        int hash(int key);
        int probe(int key);
    public:  
        LinearProbing();
        ~LinearProbing();
        void Insert(int key);
        int Search(int key);
        void Delete(int key);
};

LinearProbing::LinearProbing()
{
    printf("\n[LinearProbing][LinearProbing] Initialize");
    HT[SIZE] = {0};
}

LinearProbing::~LinearProbing()
{
    printf("\n[LinearProbing][LinearProbing] Finalize");
}

void LinearProbing::Insert(int key)
{
    printf("\n[LinearProbing][Insert] Start: %d", key);
    int index = probe(key);
    HT[index] = key; 
    printf("\n[LinearProbing][Insert] End");
}

int LinearProbing::Search(int key)
{
    printf("\n[LinearProbing][Search] Start");
    int index = hash(key);
    int i = 0;

    while(HT[hash(index+i)] != key &&HT[hash(index+i)] != 0)
    {
        i++;
    }

    printf("\n[LinearProbing][Search] End");
    if(HT[index+i] != key)
    {
        return -1;
    }

    return index + i;
}

void LinearProbing::Delete(int key)
{
    printf("\n[LinearProbing][Search] Start");
    int index = Search(key);
    if (index == -1)
    {
        printf("\n%d is not found", key);
        printf("\n[LinearProbing][Search] End");
        return;
    }
    int i = 0;
    while(HT[hash(index + i)] != 0)
    {
        HT[hash(index + i)] = HT[hash(index + i + 1)];
        i++;
    }

    printf("\n[LinearProbing][Search] End");
}

int LinearProbing::hash(int key)
{
    printf("\n[LinearProbing][hash] %d", key%SIZE);
    return key%SIZE;
}

int LinearProbing::probe(int key)
{
    int index = hash(key);
    int i = 0;

    while(HT[hash(index+i)]!=0)
    {
        i++;
    }
    printf("\n[LinearProbing][probe] %d", index + i);
    return index + i;
}