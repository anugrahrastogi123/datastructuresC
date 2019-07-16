#include <stdio.h>
int b(int a[],int,int);
void main()
{
    int a[50],value,n,pos,i;
    printf("Enter desired array size: ");
    scanf("%d",&n);
    printf("\nEnter array elements(must be stored in Asc order)\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\nEnter element to searched for: ");
    scanf("%d",&value);
    b(a,n,value);
}

int b(int a[50],int size,int search)
{
    int first,last,middle;
    first=0; last=size-1;
    middle = (first+last)/2;

   while (first <= last)
    {
      if (a[middle] < search)
         first = middle + 1;
      else if (a[middle] == search)
      {
         printf("%d found at location %d.\n", search, middle+1);
         break;
      }
      else
         last = middle - 1;

      middle = (first + last)/2;
   }
   if (first > last)
      printf("Not found! %d isn't present in the list.\n", search);
    return 0;
}
