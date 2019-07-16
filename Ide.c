#include <stdio.h>

int main(void)
{
    int i,j,k,f=1,sum=0;
    int a[][4]={{8,7,6,4},{10,11,12,13},{5,11,8,9}};
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=3;j++)
        {
            for(k=2;k<=a[i][j]/2;k++)
            {
                if(a[i][j]%k==0)
                {
                    f=0;
                    //break;
                }
            }
            if(f==1)
            {
                sum=sum+a[i][j];
            }
        }
    }
    for(i=0;i<=2;i++)
    {
        for(j=0;j<=3;j++)
        {
            printf("%5d",a[i][j]);
        }
        printf("\n");
    }
    printf("Sum is %d ",sum);
	return 0;
}

