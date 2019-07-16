#include<stdio.h>
#include<string.h>
#define MAX 30
int top=-1,t=-1,x=0;
char stack[MAX];
void push(char);
void pop();

void main()
{
            int i, choice;
            char s[MAX], b;
            printf("Enter the String\n");
            scanf("%s", s);
            for (i=0;s[i]!='\0';i++)
            {
                b=s[i];
                push(b);
            }
            for (i=0;i<(strlen(s)/2);i++)
            {
                if (stack[top]==stack[x])
                {
                    pop();
                    x++;
                }
                else
                {
                    int j;
                    for(j=t;j>=0;j--)
                        printf("%c",stack[j]);
                    printf(" is not a palindrome of %s\n",s);
                    break;
                }
            }
            if ((strlen(s)/2)==x)
                printf("%s is palindrome\n",  s);
}
void push(char a)
{
    top++;
    t++;
    stack[top]=a;
}
void pop()
{
    top--;
}
