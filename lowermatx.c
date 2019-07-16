#include<stdio.h>
void input_array(int a[][30],int);
void lmatx(int a[][30],int);
void main()
{
    int a[30][30],n;
    printf("\nEnter the dimension of square matrix A: ");
    scanf("%d",&n);
    input_array(a,n);
    lmatx(a,n);
}

void input_array(int a[][30],int n)
{
    int i,j;
    printf("\nEnter elements of A:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
}

void lmatx(int a[][30],int n)
{
    int i,j,flag=1;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i][j]!=0)
                flag=0;
        }
    }
    if(flag==1)
        printf("\nMatrix is a lower triangular matrix.\n");
    else
        printf("\nMatrix is not a lower triangular matrix.");
}
