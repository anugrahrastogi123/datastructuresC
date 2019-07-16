#include<stdio.h>
#include<math.h>
#include<limits.h>
/* Q.1
void input_arr(int a[10])
{
    int i;
    for(i=0;i<10;i++)
    {
        printf("Enter a[%d]: ",i);
        scanf("%d",&a[i]);
        printf("\n");
    }
}
void pair(int a[10])
{
    int i,j;
    for(i=0;i<10;i++)
    {
        for(j=i+1;j<10;j++)
        {
            if(a[i]+a[j]==70)
            {
                printf("(%d,%d)\n",a[i],a[j]);
            }
        }
    }
}
void main()
{
    int a[10];
    input_arr(a);
    pair(a);
}
*/
/* Q.2
void input_arr(int a[10])
{
    int i;
    for(i=0;i<10;i++)
    {
        printf("Enter marks of student %d: ",i);
        scanf("%d",&a[i]);
        printf("\n");
    }
}
void frequency(int a[10])
{
    int f[11]={0},i,j;
    for(i=0;i<10;i++)
    {
        f[a[i]]++;
    }
    for(j=0;j<11;j++)
    {
        printf("Frequency of marks %d : %d\n",j,f[j]);
    }
}
void main()
{
    int a[10];
    input_arr(a);
    frequency(a);
}
*/
/* Q.3
void input_arr(float a[20],int n)
{
    int i;
    printf("Enter %d numbers \n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%f", &a[i]);
    }
}
float arr_mean(float a[20],int n)
{
    int i;
    float sum,mean;
    for(i=0;i<n;i++)
        sum=sum+a[i];
    mean=sum/n;
    return mean;
}
float arr_variance(float a[20],int n,float mean)
{
    int i;
    float sum1,variance;
    for(i=0;i<n;i++)
    {
        sum1=sum1+pow((a[i]-mean),2);
    }
    variance=sum1/n;
    return variance;
}
float std_dev(float a[20],float variance)
{
    float std_deviation=sqrt(variance);
    return std_deviation;
}
void main()
{
    int n;
    float mean,variance,std_deviation;
    printf("Enter the value of N \n");
    scanf("%d", &n);
    float a[n];
    input_arr(a,n);
    mean=arr_mean(a,n);
    variance=arr_variance(a,n,mean);
    std_deviation=std_dev(a,variance);
    printf("Mean of all elements = %.2f\n", mean);
    printf("variance of all elements = %.2f\n", variance);
    printf("Standard deviation = %.2f\n", std_deviation);
}
*/
/* Q.4
void input_arr(int a[20],int n)
{
    int i;
    printf("Enter %d numbers \n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
void large1(int a[20],int n)
{
    int largest1,i;
    largest1 = a[0];
    for (i = 0; i < n; i++)
        if (a[i] > largest1)
            largest1 = a[i];
    printf("The largest element is %d\n",largest1);
}
void large2(int arr[20],int arr_size)
{
    int i,first,second;
    if (arr_size < 2)
    {
        printf(" Invalid Input ");
        return;
    }

    first = second = INT_MIN;
    for (i = 0; i < arr_size ; i ++)
    {
        if (arr[i] > first)
        {
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second && arr[i] != first)
            second = arr[i];
    }
    if (second == INT_MIN)
        printf("There is no second largest element\n");
    else
        printf("The second largest element is %d\n", second);
}
void main()
{
    int n;
    printf("Enter the value of N \n");
    scanf("%d", &n);
    int a[n];
    input_arr(a,n);
    large1(a,n);
    large2(a,n);
}
*/
/* Q.5
void input_arr(int a[20],int n)
{
    int i;
    printf("Enter %d numbers \n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
int linear_search(int a[20], int n, int val)
{
    int i;
    for (i = 0; i < n; i++)
        if (a[i] == val)
            return i;
    return -1;
}
void main()
{
    int n,pos,val;
    printf("Enter the value of N \n");
    scanf("%d", &n);
    int a[n];
    input_arr(a,n);
    printf("Enter the value you want to search:\n");
    scanf("%d",&val);
    pos=linear_search(a,n,val);
    if(pos==-1)
        printf("Value not found.\n");
    else
        printf("%d is at position %d.\n",val,pos);
}*/
/* Q.6
void input_arr(int a[20],int n)
{
    int i;
    printf("Enter %d numbers \n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
int linear_search(int a[20], int n, int val)
{
    int i,count;
    for (i = 0; i < n; i++)
    {
        if (a[i] == val)
            count++;
        if(i==n-1)
            return count;
    }
}
void main()
{
    int n,count,val;
    printf("Enter the value of N \n");
    scanf("%d", &n);
    int a[n];
    input_arr(a,n);
    printf("Enter the value to count its no. of occurrences:\n");
    scanf("%d",&val);
    count=linear_search(a,n,val);
    printf("no. of occurrences of %d is %d.\n",val,count);
}
*/
/* Q.7
int binarySearch(int arr[], int lb, int ub, int x)
{
   if (ub >= lb)
   {
        int mid = lb + (ub - lb)/2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, lb, mid-1, x);
        return binarySearch(arr, mid+1, ub, x);
   }
   return -1;
}

int main(void)
{
   int arr[] = {2, 3, 4, 10, 40};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x = 10;
   int result = binarySearch(arr, 0, n-1, x);
   (result == -1)? printf("Element is not present in array")
                 : printf("Element is present at index %d",
                                                   result);
   return 0;
}
*/
/* Q.8
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}*/
/* Q.9
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
*/

