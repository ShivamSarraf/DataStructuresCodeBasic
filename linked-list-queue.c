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
    struct node *front;
    struct node *rear;
}queue;
int insert(queue *q,int v)
{
    struct node *cur;
    cur=malloc(sizeof(struct node));
    if(cur==NULL)
    {
        printf("overflow \n");
        return 1;
    }
    cur->data=v;
    cur->next=NULL;
    if(q->front==NULL)
        q->front=q->rear=cur;
    else
    {
        q->rear->next=cur;
        q->rear=cur;
    }
    return 0;
}
int delete(queue *q,int *v)
{
    if(q->front==NULL)
    {
        printf("underflow \n");
        return 1;
    }
    *v=q->front->data;
    struct node *ptr;
    ptr=q->front;
    if(q->front==q->rear)
    {
        free(ptr);
        q->front=q->rear=NULL;
    }
    else
    {
        q->front=q->front->next;
        free(ptr);
    }
    return 0;
}
void init(queue *q)
{
    q->front=q->rear=NULL;
}
void display(queue q)
{
    for(struct node *q1=q.front;q1!=NULL;q1=q1->next)
        printf("%d ",q1->data);
    printf("\n");
}
int main()
{
    int p,n,d,k,t;
    queue q1;
    init(&q1);
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
            k=insert(&q1,d);
            if(k==0)
                display(q1);
            break;
            case 2:
            t=delete(&q1,&p);
            if(t==0)
                display(q1);
            break;
            case 3:
            exit(0);
            break;
        }
    }while(1);
    return 0;
}