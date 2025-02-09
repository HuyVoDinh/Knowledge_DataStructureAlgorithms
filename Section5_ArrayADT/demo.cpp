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
    printf("Elements are\n");
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
    printf(%"%d",Delete(&arr,4));
    Display(arr);

    return 0; 
}