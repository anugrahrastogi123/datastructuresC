#include <stdio.h>

int main(void) 
{
    int a[][3]={{0,2,1},{4,9,6},{0,8,9}};
    int k,i,j,sum=0;
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=2;j++)
        {
            printf("%5d",a[i][j]);
        }
        printf("\n");
    }
    /*for(k=0;k<=2;k++)
    {
        sum+=a[k][2-k];
    }*/
    for(k=0;k<=2;k++)
    {
        sum+=a[k][k];
    }
    printf("sum is %d",sum);
	return 0;
}

