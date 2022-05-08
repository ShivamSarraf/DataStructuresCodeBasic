#include <stdio.h>
#include<stdlib.h>
#define max 6
typedef struct
{
    int front;
    int rear;
    int data[max];
}queue;
int insert(queue *q,int v)
{
    if(q->rear==max-1)
    {
        printf("Overflow \n");
        return 1;
    }
    else if(q->rear==-1)
    {
        q->front=q->rear=0;
        q->data[q->rear]=v;
        return 0;
    }
    else
    {
        q->rear++;
        q->data[q->rear]=v;
        return 0;
    }
}
int delete(queue *q,int *v)
{
    if(q->front==-1)
    {
        printf("Underflow \n");
        return 1;
    }
    else if(q->front==q->rear)
    {
        *v=q->data[q->front];
        q->front=q->rear=-1;
        return 0; 
    }
    else
    {
        *v=q->data[q->front];
        q->front++;
        return 0;
    }
}
void init(queue *q)
{
    q->front=q->rear=-1;
}
void display(queue q)
{
    if(q.front==-1)
        printf("Underflow");
    else
    {
        for(int i=q.front;i<=q.rear;i++)
            printf("%d ",q.data[i]);
    }
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
        printf("1)INSERT \n2)DELETE \n 3)EXIT \n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            printf("Enter the value to be inserted \n");
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