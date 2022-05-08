#include <stdio.h>
#include<stdlib.h>
#define max 6
struct node
{
    int data;
    struct node *next;
};
typedef struct
{
    struct node *top;
}stack;
int push(stack *s,int v)
{
    struct node *cur;
    cur=malloc(sizeof(struct node));
    if(cur==NULL)
    {
        printf("overflow \n");
        return 1;
    }
    cur->data=v;
    cur->next=s->top;
    s->top=cur;
    return 0;
}
int pop(stack *s,int *v)
{
    if(s->top==NULL)
    {
        printf("underflow \n");
        return 1;
    }
    *v=s->top->data;
    struct node *ptr;
    ptr=s->top;
    s->top=ptr->next;
    free(ptr);
    return 0;
}
void init(stack *s)
{
    s->top=NULL;
}
void display(stack s)
{
    for(struct node *s1=s.top;s1!=NULL;s1=s1->next)
        printf("%d ",s1->data);
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