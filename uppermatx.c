#include<stdio.h>
void input_array(int a[][30],int *);
void umatx(int a[][30],int *);
void main()
{
    int a[30][30],*n;
    input_array(a,&n);
    umatx(a,&n);
}

void input_array(int a[][30],int *n)
{
    int i,j;
    printf("\nEnter the dimension of square matrix A: ");
    scanf("%d",&n[0]);
    printf("\nEnter elements of A:\n");
    for(i=0;i<*n;i++)
        for(j=0;j<*n;j++)
            scanf("%d",&a[i][j]);
}

void umatx(int a[30][30],int *n)
{
    int i,j,flag=1;
    for(i=0;i<*n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[i][j]!=0)
                flag=0;
        }
    }
    if(flag==1)
        printf("\nMatrix is an upper triangular matrix.\n");
    else
        printf("\nMatrix is not an upper triangular matrix.");
}
