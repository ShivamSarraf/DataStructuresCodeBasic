#include <stdio.h>
#include<stdlib.h>
#define max 6
struct pridata
{
    int val;
    int pri;
};
typedef struct
{
    int front;
    int rear;
    struct pridata data[max];
}pqueue;
int insert(pqueue *q,int v,int p)
{
    int i,j;
    if(q->rear==max-1)
    {
        printf("Overflow \n");
        return 1;
    }
    else if(q->rear==-1)
    {
        q->front=q->rear=0;
        q->data[q->rear].val=v;
        q->data[q->rear].pri=p;
        return 0;
    }
    else
    {
        for(i=q->front;i<=q->rear;i++)
        {
            if(q->data[i].pri>p)
            break;
        }
        for(j=q->rear;j>=i;j--)
            q->data[j+1]=q->data[j];
        q->data[i].val=v;
        q->data[i].pri=p;
        q->rear++;
        return 0;
    }
}
int delete(pqueue *q,int *v)
{
    int i,j;
    if(q->front==-1)
    {
        printf("Underflow \n");
        return 1;
    }
    else if(q->front==q->rear)
    {
        *v=q->data[q->front].val;
        q->front=q->rear=-1;
        return 0; 
    }
    else
    {
        int min=q->front;
        for(i=q->front+1;i<=q->rear;i++)
        {
            if(q->data[i].pri<q->data[min].pri)
                min=i;
        }
        *v=q->data[min].val;
        for(i=min+1;i<=q->rear;i++)
            q->data[i-1]=q->data[i];
        q->rear--;
        return 0;
    }
}
void init(pqueue *q)
{
    q->front=q->rear=-1;
}
void display(pqueue q)
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
    int p,n,d,k,t,m;
    pqueue q1;
    init(&q1);
    char a;
    do
    {
        printf("1)INSERT \n2)DELETE \n 3)EXIT \n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            printf("Enter the value to be inserted and its priority \n");
            scanf("%d %d",&d,&m);
            k=insert(&q1,d,m);
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