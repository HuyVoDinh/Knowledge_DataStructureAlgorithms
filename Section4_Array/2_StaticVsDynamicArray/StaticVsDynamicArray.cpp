 /****
  * [Static vs Dynamic Array]
  * 
  * void main()
  * {
  *         int a[5];       // it is mentioned inside the main function as a variable, just a vector variable. Then the memory for this array will be created inside stack.
  *                         // It í static because the size of this array was decided at the compile time. So memory will be allocated during runtime and the size of that memory was decided already at the compilation time. 
  *         
  *         int n;
  *         cin >> n;
  *         int B[n];       // Size of an array is a decided at runtime. An array of that size  will be created inside the stack. 
  * }
  * <StaticVsDynamicArray1.png>
  * How to create an array inside heap?
  * Accessing anything from heap, must have a pointer. So at runtime, a size of an array can be decided and it'll be created inside the stack only. 
  * 
  * void main()
  * {
  *     int *p;
  *     p = new int [5];
  * }
  * When get the memory from heap, whenever say new, then only get the memory from heap.
  * Otherwise, all the variables, whatever the variables you declare, they will get the memory inside the stack only. 
  * 
  * When have allocated the memory in heap and after some time during the execution of program, at any stage, if that memory is not required, then you must delete the memory also.
  * If don't delete the memory, unused memory, then it causes memory leak problem. 
  * delete []p;
  * 
  * If want to increase the size of an array, it is possible only in heap. Stack array cannot be resized at all. 
  * But a heap array, same array cannot be resized, but we have some alternative for that. 
  * ** */

 #include <stdio.h>

 int main()
 {
    int A[5] = {2,4,6,8,10};
    int *p;
    p = new int[5];
    p[0]=1;
    p[1]=1;
    p[2]=1;
    p[3]=1;
    p[4]=1;
    for(int i = 0; i < 5; i++)
    {
        printf("%d ", p[i]);
    }
    delete []p;
    p = nullptr;
 }