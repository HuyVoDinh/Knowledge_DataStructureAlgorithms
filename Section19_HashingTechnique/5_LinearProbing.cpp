#include <stdio.h>
#include "5_LinearProbing.h"
#define SIZE 10

int main()
{
    LinearProbing *HT = new LinearProbing();
    // LinearProbing HT;
    HT->Insert(12);
    HT->Insert(25);
    HT->Insert(35);
    HT->Insert(26);

    int key = 35;

    HT->Delete(25);

    int index = HT->Search(key);
    if(index == -1)
    {
        printf("\n%d is not found", key);
    }
    else 
    {
        printf("\n%d is found at %d.", key, index);
    }

    return 0;
}