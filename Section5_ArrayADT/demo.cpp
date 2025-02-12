#include <stdio.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for(int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

void Append(struct Array *arr, int x)
{
    // insert end
    if(arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
}

void Insert(struct Array *arr,int index,int x)
{
    if(index >= 0 && index <= arr->length)
    {
        for(int i = arr->length; i>index;i--)
        {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index)
{
    int x = 0;
    if(index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for(int i = index; i < arr->length-1;i++)
        {
            arr->A[i] = arr->A[i+1];
            return x;
        }
    }

    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array arr, int key)
{
    for(int i = 0; i < arr.length; i++)
    {
        if(key == arr.A[i])
        {
            swap(&arr.A[i], &arr.A[i-1]); // transposition
            // swap(&arr.A[i], &arr.A[0]); move head
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key)
{
    int l, mid, h;
    l = 0; h = arr.length-1;
    while(l <= h)
    {
        mid = (l+h)/2;
        if(key==arr.A[mid])
            return mid;
        else if(key < arr.A[mid])
            h = mid-1;
        else 
            l = mid+1;
    }
    return -1;
}

int RBinSearch(int a[], int l, int h, int key)
{
    int mid;
    if(l <= h)
    {
        mid = (l+h)/2;
        if(key == a[mid])
            return mid;
        else if (key < a[mid])
            return RBinSearch(a,l,mid-1,key);
        else
            return RBinSearch(a,mid+1,h, key);
    }
    return -1;
}

int Get(struct Array arr, int index)
{
    if (index >= 0 && index<arr.length)
        return arr.A[index];
    return -1;
}

void Set(struct Array *arr,int index, int x)
{
    if(index >= 0 && index <arr->length)
        arr->A[index] = x;
}

int Max(struct Array arr)
{
    int max = arr.A[0];
    for(int i = 1; i < arr.length; i++)
    {
        if(arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

int Min(struct Array arr)
{
    int min = arr.A[0];
    for(int i = 1; i < arr.length; i++)
    {
        if(arr.A[i] > min)
            min = arr.A[i];
    }
    return min;
}

int Sum (struct Array arr)
{
    int s = 0;
    for(int i = 0; i < arr.length;i++)
        s += arr.A[i];

    return s;
}

float Avg(struct Array arr)
{
    return (float)Sum(arr)/arr.length;
}

void Reverse(struct Array *arr){
    int *B;
    B = new int (arr->length*sizeof(int));
    for(int i = arr->length-1, j = 0; i >= 0; i--,j++)
        B[j] = arr->A[i];
    for(int i = 0; i < arr->length; i++)
        arr->A[i] = B[i];
}

void Reverse2(struct Array *arr)
{
    for(int i = 0, j =arr->length-1;i<j;i++,j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}

void InsertSort(struct Array *arr, int x)
{
    if(arr->length==arr->size)
        return;
    int i = arr->length-1;
    while(i <= 0 && arr->A[i]>x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}

int isSorted(struct Array arr)
{
    for(int i = 0; i < arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
            return 0;
    }
    return 1;
}

void Rearrange(struct Array *arr)
{
    int i,j;
    i = 0;
    j = arr->length-1;
    while(i<j)
    {
        while(arr->A[i]<0) i++;
        while(arr->A[j]>=0)j--;
        if(i<j)
            swap(&arr->A[i], &arr->A[j]);
    }
}

int main()
{
    struct Array arr = {{2,3,4,5,6},20,5};
    // printf("Enter size of an array ");
    // scanf("%d", &arr.size);
    // arr.A = new int (arr.size);
    

    // printf("Enter number of numbers ");
    // scanf("%d", &n);
    // arr.length = n;

    // printf("Enter all Elements\n");
    // for(i = 0; i < n; i++)
    // {
    //     scanf("%d", &arr.A[i]);
    // }

    Display(arr);
    Append(&arr, 10);
    Display(arr);
    Insert(&arr,2,30);
    Display(arr);
    printf("%d\n",Delete(&arr,4));
    Display(arr);
    printf("\nLinear search: %d\n",LinearSearch(arr,4));
    printf("\nBinary search: %d\n",BinarySearch(arr,3));
    printf("\nRBin search: %d\n",RBinSearch(arr.A,0,arr.length-1,2));
    printf("Get: %d\n", Get(arr,9));
    Set(&arr,0,15);
    Display(arr);
    printf("Max: %d\n", Max(arr));
    printf("Min: %d\n", Min(arr));
    printf("Sum: %d\n", Sum(arr));
    printf("Avg: %f\n", Avg(arr));
    
    Display(arr);
    Reverse(&arr);
    Display(arr);

    Display(arr);
    Reverse2(&arr);
    Display(arr);

    arr = {{2,3,4,5,6},20,5};
    InsertSort(&arr,20);
    Display(arr);

    printf("\nIs sorted: %d\n", isSorted(arr));
    arr = {{2,3,-4,-5,6},20,5};
    Display(arr);
    Rearrange(&arr);
    Display(arr);

    return 0; 
}