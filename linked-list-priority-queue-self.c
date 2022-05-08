#include <stdio.h>
#include<stdlib.h>
#define max 6
struct pridata
{
    int val;
    int pri;
    struct pridata *next;
};
typedef struct
{
    struct pridata *front;
    struct pridata *rear;
}pqueue;
int insert(pqueue *q,int v,int p)
{
    struct pridata *cur,*ptr,*ptr1;
    cur=malloc(sizeof(struct pridata));
    if(cur==NULL)
    {
        printf("overflow \n");
        return 1;
    }
    cur->val=v;
    cur->pri=p;
    cur->next=NULL;
    if(q->front==NULL)
        q->front=q->rear=cur;
    else
    {
        if(q->front->pri>cur->pri)
        {
            cur->next=q->front;
            q->front=cur;
            return 0;
        }
        for(ptr=q->front;ptr!=NULL;ptr=ptr->next)
        {
            if(cur->pri<ptr->pri)
            break;
        }
        for(ptr1=q->front;ptr1->next!=ptr;ptr1=ptr1->next);
        cur->next=ptr;
        ptr1->next=cur;
        for(;q->rear->next!=NULL;q->rear=q->rear->next);
    }
    return 0;
}
int delete(pqueue *q,int *v)
{
    struct pridata *ptr;
    ptr=q->front;
    if(q->front==NULL)
    {
        printf("underflow \n");
        return 1;
    }
    else if(q->front==q->rear)
    {
        *v=ptr->val;
        free(ptr);
        q->front=q->rear=NULL;
    }
    else
    {
        *v=ptr->val;
        q->front=q->front->next;
        free(ptr);
    }
    return 0;
}
void init(pqueue *q)
{
    q->front=q->rear=NULL;
}
void display(pqueue q)
{
    for(struct pridata *q1=q.front;q1!=NULL;q1=q1->next)
        printf("%d ",q1->val);
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
            printf("Enter the value to be pushed and its priority \n");
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