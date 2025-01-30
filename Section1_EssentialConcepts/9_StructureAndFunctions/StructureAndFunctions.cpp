/***
 * [Structure And Function]
 * 
 * struct Rectangle
 * {
 *      int lenght;
 *      int breadth;
 * }
 * 
 * void initialize (struct Rectangle *r, int a, int b)          // call by address
 * {
 *      r->length = a;
 *      r->breadth = b;
 * }
 * 
 * int area (struct Rectangle r)           // call by value
 * {
 *      return r.length * r.breadth;
 * }
 * 
 * void changeLength(struct *r, int a)          // call by address
 * {
 *      r.length = a;
 * }
 * 
 * int main()
 * {
 *      struct Rectangle r;
 * 
 *      initialize (&r, 10, 5);
 *      area(r);
 *      changeLength(&r, 20);
 * }
 * 
 * Main function is not having any instructions of its own but only calling functions. Everything is done by calling functions. 
 * If observe these functions,  This initialize function should modify r, so function must be call by address.
 * Change length function should change this rectangle that is actual parameter 
 * for that we don't have to make any changes just we want the result, that is length * breadth -> call by value
 * 
 * 
 * OOP
 * All these functions are related to that structure only. Define a strucutre and write all the functions related to that structure because grouping of data at one place is a structure, grouping the instructions for performing a task is a function.
 * ** */