#include <stdio.h>
#include <stdlib.h>
struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m;
    int n;
    int num;
    struct Element *ele;
};

void create(struct Sparse *s)
{
    printf("Enter Dimensions: ");
    scanf("%d%d", &s->m, &s->n);
    printf("Number of non-zero: ");
    scanf("%d", &s->num);

    s->ele = new Element[s->num];
    printf("Enter non-zero elements\n");
    for(int i = 0; i <s->num;i++)
    {
        scanf("%d%d%d",&s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
    }
}

void display(struct Sparse s)
{
    int k = 0;
    for(int i = 0; i < s.m; i++)
    {
        for(int j = 0; j < s.n; j++)
        {
            if(i==s.ele[k].i && j == s.ele[k].j)
            {
                printf("%d ", s.ele[k++].x);
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}

struct Sparse *add(Sparse *s1, Sparse *s2)
{
    struct Sparse *sum;

    sum = new Sparse[sizeof(Sparse)];
    sum->ele = new Element[s1->num + s2->num];
    int i,j,k;
    i = j = k = 0;
    while(i<s1->num && j<s2->num)
    {
        if(s1->ele[i].i < s2->ele[j].i)
            sum->ele[k++] = s1->ele[i++];
        else if(s1->ele[i].i > s2->ele[j].i)
            sum->ele[k++] = s2->ele[j++];
        else
        {
            if(s1->ele[i].j < s2->ele[j].j)
                sum->ele[k++] = s1->ele[i++];
            else if (s1->ele[i].j > s2->ele[j].j)
                sum->ele[k++] = s2->ele[j++];
            else
            {
                sum->ele[k] = s1->ele[i];
                sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
            }
        }
            
    }
    //Copy the rest of the elements from the remaining matrix. 
    for(;i<s1->num;i++) sum->ele[k++] = s1->ele[i];
    for(;j<s2->num;j++) sum->ele[k++] = s2->ele[j];
    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;

    return sum;
}

int main()
{
    struct Sparse s1,s2, *s3;

    create (&s1);
    create (&s2);

    s3 = add(&s1,&s2);
    printf("First matrix\n");
    display(s1);
    printf("Second matrix\n");
    display(s2);
    printf("Sum matrix\n");
    display(*s3);
    return 0;
}