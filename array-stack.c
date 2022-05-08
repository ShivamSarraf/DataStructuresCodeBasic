#include <stdio.h>
#include<stdlib.h>
#define max 6
typedef struct
{
    int data[max];
    int top;
}stack;
int push(stack *s,int v)
{
    if(s->top==max-1)
    {
        printf("overflow \n");
        return 1;
    }
    s->top++;
    s->data[s->top]=v;
    return 0;
}
int pop(stack *s,int *v)
{
    if(s->top==-1)
    {
        printf("underflow \n");
        return 1;
    }
    *v=s->data[s->top];
    s->top--;
    return 0;
}
void init(stack *s)
{
    s->top=-1;
}
void display(stack s)
{
    for(int i=0;i<=s.top;i++)
        printf("%d ",s.data[i]);
    printf("\n");
}
int main()
{
    int p,n,d,k,t;
    stack s1;
    init(&s1);
    char a;
    do
    {
        printf("1)PUSH \n2)POP \n 3)EXIT \n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            printf("Enter the value to be pushed \n");
            scanf("%d",&d);
            k=push(&s1,d);
            if(k==0)
                display(s1);
            break;
            case 2:
            t=pop(&s1,&p);
            if(t==0)
                display(s1);
            break;
            case 3:
            exit(0);
            break;
        }
    }while(1);
    return 0;
}