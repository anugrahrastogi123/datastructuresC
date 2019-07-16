#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void swap(int*, int*);
int choose_pivot(int, int);
void quicksort(int*, int, int);

int main()
{
    int p[10], pri[10] ;
    int i;
    for(i=0;i<10;i++)
    {
        scanf("%d",&p[i]);
        scanf("%d",&pri[i]);
    }

    // Manipulating input for best earning.
    for (i = 0; i < 10; i++) {
        if(pri[i] == -1) pri[i] = 2;
        else if(pri[i] == 1) pri[i] = -1;
        else if(pri[i] == 2) pri[i] = 1;

    }

/*	ENTER YOUR CODE HERE 	*/
    quicksort(pri, 0, 4);
    quicksort(pri, 5, 9);


    int earned = 0;
    int penalty = 0;
    int net = 0;
    // Checking orders of first half
    int time_spent = 0;
    int t, m;
    for(i = 4; i>=0; i--){
        if(pri[i] == 2){
            t = 10;
            m = 10;
        }
        else{
            if(pri[i] == -1 || pri[i] == 1){
                t = ceil(50 / (pri[i]+1));
                m = 10*(pri[i]+1);
            }
            else{
                t = ceil(50 / (pri[i]));
                m = 10*(pri[i]);
            }
        }
        if(time_spent+t > 50) break;
        time_spent+=t;
        earned+=m;
    }
    penalty = (i+1) * 20;

    // Checking orders of second half
    time_spent = 0;
    for(i = 9; i>=5; i--){
        if(pri[i] == 2){
            t = 10;
            m = 10;
        }
        else{
            if(pri[i] == -1 || pri[i] == 1){
                t = ceil(50 / (pri[i]+1));
                m = 10*(pri[i]+1);
            }
            else{
                t = ceil(50 / (pri[i]));
                m = 10*(pri[i]);
            }
        }
        if(time_spent+t > 50) break;
        time_spent+=t;
        earned+=m;
    }
    penalty += (i - 5 + 1) * 20;
    net = earned - penalty;

/*	DISPLAYING OUTPUT. DO NOT MODIFY THE LOOP FOR DISPLAYING VALUES	*/
    printf("Amount earned for orders processed = Rs. %d\n", earned);
    printf("Penalty for missed process or processes = Rs. %d\n", penalty);
    printf("Net Amount earned = Rs. %d", net);
    return 0;
}

void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int choose_pivot(int i,int j )
{
    return((i+j) /2);
}

void quicksort(int list[],int m,int n)
{
    int key,i,j,k;
    if( m < n)
    {
        k = choose_pivot(m,n);
        swap(&list[m],&list[k]);
        key = list[m];
        i = m+1;
        j = n;
        while(i <= j)
        {
            while((i <= n) && (list[i] <= key))
                i++;
            while((j >= m) && (list[j] > key))
                j--;
            if( i < j)
                swap(&list[i],&list[j]);
        }
        /* swap two elements */
        swap(&list[m],&list[j]);

        /* recursively sort the lesser list */
        quicksort(list,m,j-1);
        quicksort(list,j+1,n);
    }
}
