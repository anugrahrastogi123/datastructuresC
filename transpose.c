#include<stdio.h>
void input_array(int a[][30],int,int);
void trans(int a[][30],int b[][30],int,int);
void output_array(int b[][30],int,int);
int main()
{
    int a[30][30],b[30][30],m,n;
    printf("\nEnter no. of rows and columns of A: ");
    scanf("%d %d",&m,&n);
    input_array(a,m,n);
    trans(a,b,m,n);
    output_array(b,m,n);
}

void input_array(int a[][30],int m,int n)
{
    int i,j;
    printf("\nEnter elements of A:\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
}

void trans(int a[][30],int b[][30],int m,int n)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            b[i][j]=a[j][i];
}

void output_array(int b[][30],int m,int n)
{
    int i,j;
    printf("\nTranspose of A is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            printf("%3d",b[i][j]);
        printf("\n");
    }
}
