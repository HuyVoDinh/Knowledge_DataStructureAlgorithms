/***
 * [Array as Parameter]
 * 
 * void func (int A[], int n)   // It is taking parameter array A, and for passing array as parameter, we have to mention empty brackets A[]. This function doesn't know the size of an array because array actually belong to main function. So we should also pass what is the size of an array, how many elements to access. So A is actually like a pointer to an array.It's not a array itself, it's a pointer to an array. Array is passed by address. Arrays cannot be passed by value at all.    
 *                              // n, there is no * so it's not call by address. There is no ampersand & it is not cal by reference. => It is call by value, just a normal variable.
 * {
 *      int i;
 *      for(i = 0; i < n; i++)
 *          printf("%d", A[i]);
 * }
 * 
 * int main()
 * {
 *      int A[5] = {2,4,6,8,10};
 *      func(A,5);
 * }
 * 
 * C++, arrays can be passed only by address, so it means the address of the array, the base address of this array is given to this pointer. The bracket means it's a pointer to an array.
 * Instead of writing brackets [], even Can write star *. So this will be a integer pointer and that ponter will be pointing to an array. See the difference is this pointer can point on any integer and even it can point on an array.
 * But if using brackets [] it means it's a pointer to array only.
 * 
 * The array belongs to a main function only and this function is able to modify the contents of the array because it is call by address so you can modify the array also and you can modify all the elements. 
 * 
 * int [] func (int n)
 * {
 *      int *p;
 *      p = (int *) malloc(n*sizeof(int));      // malloc will allocate the memory in heap, so inside heap, an array of size 5 will be created. Then the address of that will be present in p, because that is stored in p, and that p belongs to function. That array in the heap is inderectly accessible by this pointer p now. After allocating it returns p, so it is returning that pointer.
 *      return p;       // return an array
 * }
 * 
 * int main()
 * {
 *      int *A;
 *      A = func(5);        // A will be pointing to that array.
 * }
 * 
 * Sometimes like a function is allocating a memory in heap and manipulating storing some data, and then it is returning the array to the calling function. So it is returning and this function is getting that arry created by that function.
 * Once the function ends its activationg record is deleted. So this p is gone but A is still there and A is accessing that array. 
 * <ArrayAsParameter1.png> 
 * 
 * Instead of writing square bracket [], even can write astirx(*) because it is returning a pointer. SO pointer can point on one element or array of element.
 * But when you have given a square bracket [] means it should point on array of elements only that
 * Note: Some compilers don't allow[] repleace [] with *. 
 * If the square bracket [] is used, the code itself is readable and from the code we can read that it is related to array.
 * ** */
#include <iostream>
using namespace std;

void func(int A[], int n)
{
    cout << sizeof(A)/sizeof(int) << endl;// There is a warning given here that size of an array function parameter A will return the size of integer * (ingeger pointer). Actually it is not giving the size of this array, the size of the array is 5.
                                            // It's not giving the size of this array, it is giving the size of a pointer and the pointer in lastest compiler takes bytes and integer 4 bytes. 
                                            // When we pass it to a function, function is taking it as a pointer to an array.
    // for(int x : A)  //In this scope begin and end is not declara in this scope. When pass array to some other function inside that function, you cannot access that array using for each loop because the parameter is a pointer
    //     cout << x << " "; 

    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
}

int * func2(int size)
{
    int *p;
    p = new int [size];
    for(int i = 0; i < size; i++)
        p[i] = i+1;
    return p;
}

int main()
{
    int A[] = {2,4,6,8,10};
    int n = 5;
    func(A,n);  // Arrays are always pass by address and the parameter is a pointer. 
    cout << sizeof(A)/sizeof(int) << endl; 
    
    int *ptr, sz=5;
    ptr = func2(sz);

    func(ptr,sz);
    return 0;
}