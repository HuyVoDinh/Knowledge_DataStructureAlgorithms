#include <iostream>
#include <stdio.h>
#include "3_Chaining.h"
using namespace std;

int main()
{
    HashTable *HT = new HashTable();
    HT->Insert(12);
    HT->Insert(22);
    HT->Insert(42);
    HT->Insert(32);
    HT->Insert(9);


    int keyFind = 9;
    HT->Delete(9);
    Node *temp = HT->Search(keyFind);
    if(temp==nullptr)
    {
        printf("Search %d is not found",keyFind);
    }
    else 
    {
        printf("Search %d is found",keyFind);
    }
    return 0;
}