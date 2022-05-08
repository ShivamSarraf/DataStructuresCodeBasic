#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void traverse(struct node *h)
{
    struct node *ptr;
    ptr=h;
    do
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    } while (ptr!=h);
    printf("\n");
}
void create(struct node **h, int m)
{
    struct node *ptr,*cur;
    ptr=*h;
    for(int i=0;i<m;i++)
    {
        cur=malloc(sizeof(struct node));
        printf("Enter the value of %d element \n",i+1);
        scanf("%d",&cur->data);
	    cur->next=NULL;
        if(ptr==NULL)
        {
            *h=ptr=cur;
            cur->next=*h;
        }
        else
        {
            ptr->next=cur;
            ptr=cur;
            cur->next=*h;
        }
    }
    traverse(*h);
}
void insatstart(struct node **h)
{
    struct node *ptr,*tail;
    for(tail=*h;tail->next!=*h;tail=tail->next);
    ptr=malloc(sizeof(struct node));
    printf("Enter the no to be inserted at the start\n");
    scanf("%d",&ptr->data);
    ptr->next=*h;
    *h=ptr;
    tail->next=*h;
    traverse(*h);
}
void insert(struct node **h)
{
    struct node *ptr,*cur;
    ptr=malloc(sizeof(struct node));
    cur=*h;
    int d;
    printf("Enter the value after which you want to insert \n");
    scanf("%d",&d);
    printf("Enter the value to be inserted \n");
    scanf("%d",&ptr->data);
    while(cur->data!=d)
        cur=cur->next;
    ptr->next=cur->next;
    cur->next=ptr;
    traverse(*h);
}
void delete(struct node **h)
{
    struct node *ptr=NULL,*cur;
    cur=*h;
    int d;
    printf("Enter the value to be deleted \n");
    scanf("%d",&d);
    while(cur->data!=d)
    {
        ptr=cur;
        cur=cur->next;
    }
    if(cur==*h)
    {
        for(ptr=*h;ptr->next!=*h;ptr=ptr->next);
        ptr->next=cur->next;
        free(cur);
        *h=ptr->next;
        traverse(*h);
        return;
    }
    ptr->next=cur->next;
    free(cur);
    traverse(*h);
}
int main()
{
    struct node *head=NULL;
    int n;
    printf("Enter the no of elements \n");
    scanf("%d",&n);
    create(&head,n);
    do
    {
        printf("1)INSERT AT START \n2)INSERT \n 3)DELETE \n 4)EXIT \n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            insatstart(&head);
            break;
            case 2:
            insert(&head);
            break;
            case 3:
            delete(&head);
            break;
            case 4:
            exit(0);
            break;
        }
    }while(1);
    return 0;
}