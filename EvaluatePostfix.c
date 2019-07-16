#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 20
float st[MAX];
int top=-1;
float evaluatePostfix(char postfix[]);
void push(float st[],float val);
float pop(float st[]);
void main()
{
    float val;
    char postfix[20];
    printf("\nEnter the postfix expression : ");
    gets(postfix);
    val=evaluatePostfix(postfix);
    printf("\nValue of the postfix expression is : %.2f",val);
}
float evaluatePostfix(char postfix[])
{
    int i=0;
    float val1,val2,value;
    while(postfix[i]!='\0')
    {
        if(isdigit(postfix[i]))
        {
            push(st,(float)(postfix[i]-'0'));
        }
        else if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'||postfix[i]=='/')
        {
            val1=pop(st);
            val2=pop(st);
            printf("%f %f",val1,val2);
            switch(postfix[i])
            {
                case '+' : value=val2+val1;
                           break;
                case '-' : value=val2-val1;
                           break;
                case '*' : value=val2*val1;
                           break;
                case '/' : value=val2/val1;
                           break;
            }
            push(st,value);
        }
        i++;
    }
    return (pop(st));
}
void push(float st[],float val)
{
    if(top==MAX-1)
        printf("\nStack Overflow.");
    else
    {
        top++;
        st[top]=val;
    }
}
float pop(float st[])
{
    float item;
    if(top==-1)
        printf("\nStack Underflow.");
    else
    {
        item=st[top];
        top--;
    }
    return item;
}









































