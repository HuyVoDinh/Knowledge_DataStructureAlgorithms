/****
 * [Pointer to Structure]
 * 
 * struct Rectangle{
 *      int length;
 *      int breadth;
 * };
 * 
 * int main()
 * {
 *      struct Rectangle r = {10,5};        -> This variable occupies memory and it will have the values 10 and 5. Can directly access these members length and breadth by using variable name r. 
 *      struct Rectangle *p &r;                -> It only have 4 bytes, not 8 byte. A pointer diagrammatically. Assign the address of this r so this pointer will be pointing on this variable r.  
 * 
 *      r.length = 15;
 *      (*p).length = 20;                      -> p is a pointer, it's n ot a variable, it's not having members. So need * to access to address
 *      p->length = 2-;                         -> similar (*p).length = 20;   
 * }
 * 
 * //////
 * 
 * int main()
 * {
 *      struct Rectangle *p;               -> This will be created inside the stack. Now we want a variable of type structure, object of type structure in heap. 
 *      p = (struct Rectangle*)malloc(sizeof(struct Rectangle)); -> This will allocate the memory. This can allocate a object of type this rectangle in heap. 
 * }
 * ***/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main(){

    // Rectangle r = {10,5};
    // cout << r.length << endl;
    // cout << r.breadth << endl;

    // Rectangle *p = &r;
    // cout << p->length << endl;
    // cout << p->breadth << endl;

    Rectangle *p;
    // p = (Rectangle*)malloc(sizeof(Rectangle));
    p = new Rectangle();
    p->length = 15;
    p->breadth = 8;
    cout << p->length << endl;
    cout << p->breadth << endl;

    return 0;
}