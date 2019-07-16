#include<stdio.h>
void input_array(int a[][30],int b[][30],int,int,int,int);
void multi(int a[][30],int b[][30],int c[][30],int,int,int);
void output_array(int c[][30],int,int);
void main()
{
    int a[30][30],b[30][30],c[30][30],m,n,p,q;
    printf("\nEnter no. of rows and columns of A: ");
    scanf("%d %d",&m,&n);
    printf("\nEnter no. of rows and columns of B: ");
    scanf("%d %d",&p,&q);
    if(p==n)
    {
        input_array(a,b,m,n,p,q);
        multi(a,b,c,m,q,p);
        output_array(c,m,q);
    }
    else
        printf("\nMultiplication not possible\n");
}

void input_array(int a[][30],int b[][30],int m,int n,int p,int q)
{
    int i,j;
    printf("\nEnter elements of A:\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    printf("\nEnter elements of B:\n");
    for(i=0;i<p;i++)
        for(j=0;j<q;j++)
            scanf("%d",&b[i][j]);
}

void multi(int a[][30],int b[][30],int c[][30],int m,int q,int p)
{
    int i,j,k;
    for(i=0;i<m;i++)
        for(j=0;j<q;j++)
            for(k=0;k<p;k++)
                c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
}

void output_array(int c[][30],int m,int q)
{
    int i,j;
    printf("\nMultiplication of A and B is:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<q;j++)
            printf("%3d",c[i][j]);
        printf("\n");
    }
}
