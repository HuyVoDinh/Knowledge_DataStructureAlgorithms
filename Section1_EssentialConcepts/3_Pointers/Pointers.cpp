/***
 * [Pointers]
 * 
 * Pointer is an address variable that is mean for storing address of data, not the data itself; normal variables are data variables, but the pointers are address variables. 
 * Pointers are used for indirectly accessing the data. 
 * 
 * <Pointer1.png> 
 * 
 * Main memory. And this is the CPU which will execute program. How this main memory is utilized?
 * Divided into three parts. 
 * Main (code section), stack, heap. 
 * The main memory is divided into three sections and utilized this is code section. 
 * Program can directly access these two areas. Program will not directly access heap. The policy of a program is it will not directly access it. So heap memory is external to the program, outside the program. 
 * So program doesn't directly access -> it needs a pointer to access heap memory. So program should have a pointer within itself and with that point that it can access anything in the heap. 
 * I may have an array or anything inside heap and the program can access it. For accessing this memory from the program we need a pointer. So, pointer is useful for accessing the resources that are outside the program. 
 * So this is one example, heap is one thing. Then if suppose on the hard disk there are some files, now for accessing a file, program cannot access this hard disk files directly, because hard disk is external or files are external to a program, so far that, it needs a pointer for accessing and that pointer should be a file type and we can access that file. 
 * Then a program may be accessing a keyboard, a program may be accessing a monitor, a program may be accessing internet or network connection, all these things are external to a program, so all these things can be accessed with the help of pointers. 
 * So one major usage of pointer is accessing the resources which are outside the program. So, I will list it, see pointers are used for accessing heap memory, and for accessing resources and third pointers are used for parameter passing also. 
 * How pointers are useful for passing parameters? So these are the major usages of pointer. Accessing heap, which is like a resource accessing, other resources or parameter passing. 
 * 
 * How to declare a pointer, how to initialize and how to use it? 
 * 
 * 
 * <Pointer2.png>
 * Data variable    int a = 10;
 * Address variable int *p;         -> initialize pointer
 *                  p = &a;         -> this will store the address of a. p will also occupy memory, pointer is also variable. So created inside the stack frame of the same main function. 
 *                                      p will have the address of a variable. So inside the memory it pointing to a. 
 * 
 *                  printf("%d", a);
 *                  printf("%d", &p); -> this is dereferencing
 * 
 * /////
 * malloc the the size for pointer. 
 * Example: Want to 5 integer with int data type. => malloc (5 * sizeof(int)) => It will allocate total 5 integers -> That should be pointed by a pointer because we cannot access it unless we have a pointer. So I will assign this to a pointer p = (int *) malloc(5 * sizeof(int)); This line will allocate heap memory in the heap. 
 * Can use p = new int[5]; 
 * ***/

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{

    int a = 10;
    int *p;
    p = &a;

    cout << a << endl;
    cout << "Using pointer" << *p << endl;

    int A[5] = {2,4,6,8,10};
    int *q;
    q = A; 

    for(int i = 0; i < 5; i++)
        cout << q[i] << endl;


    int *p1;
    char *p2;
    float *p3;
    double *p4;
    cout << "Size of\n";
    cout << sizeof(p1) << endl;
    cout << sizeof(p2) << endl;
    cout << sizeof(p3) << endl;
    cout << sizeof(p4) << endl;
    // Whatever the data type of pointer is, pointer takes same amount of memory. Every pointer takes the same amount of memory. All these pointers are taking 8bytes.
    // -> Whatever the type of pointer is, it is independent size of a pointer is independent of its data type

        delete []p; // make a request for memory in heap so then have finished using it. Whenever you are dynamically allocating memory, you must release the memory by the when you have finished using it.
    // free(p);    // free is used in C language. Delete using in C++. This is for deallocating the memory that is allocated in a heap. So heap memory should be deallocated. 
    // This is a very crucial thing. When memory is not required, you must delete the memory for these small practiced programs. If skip, that's not 
    delete []q;
    return 0;
}