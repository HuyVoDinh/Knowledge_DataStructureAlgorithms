/***
 * [Structures]
 * 
 * 1. Defining structure -> like how much memory is consumed
 * 2. Size of structure
 * 3. Declaring a structure
 * 4. Accessing members
 * 
 * Structure can be defined as a collection of data members that are related data members under one name, and those data members may be of similar type. 
 * So usually it is defined as collection of the similar data items under one name that is grouping the data items. 
 * Structure is used for defining user define data types apart from the primitive data types. 
 * 
 * Example rectangle. In programs need something like a rectangle then you can define a structure for it because a rectangle is not defined by just one value. 
 * It is defined by a set of values. So that is length and breadth so we can group them together under one name and define it as a structure. 
 * 
 * struct Rectangle
 * {
 *      int length;
 *      int breadth;
 * };
 * -> structure rectangle is defined by its length and breadth these two members together are defining a rectangle. This is a definition of a structure. 
 * How much memory this rectangle will be consuming? The size of a structure is the total amount of memory consumed by all its members. 
 * 
 * int main()
 * {
 *      struct Rectangle r = {10,5};
 *      r.length = 15;
 * }
 * 
 * <Structure2.png>
 * ****/

#include <iostream>
#include <stdio.h>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    struct Rectangle r1 ={10,5};
    printf("%lu", sizeof(r1));
    cout << r1.length << " - " << r1.breadth << endl;
    return 0;
}