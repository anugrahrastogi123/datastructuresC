#include<stdio.h>

int fun(int i)
{
    if(i==0)
            return 0;
    return 1+fun(i/10);
}
void main()
{
    int count1=fun(536);
    printf("No. of digits : %d",count1);
}
