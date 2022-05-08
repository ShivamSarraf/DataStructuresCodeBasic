#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void traverse(struct node *h)
{
    for(;h!=NULL;h=h->next)
        printf("%d ",h->data);
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
            *h=ptr=cur;
        else
        {
            ptr->next=cur;
            ptr=cur;
        }
    }
    traverse(*h);
}
 void reverse(struct node **h)
    {
        struct node *cur = *h;
        struct node *prev = NULL, *next = NULL;
        while (cur != NULL) 
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        *h = prev;
        traverse(*h);
    }
int main()
{
    struct node *head=NULL;
    int n;
    printf("Enter the no of elements \n");
    scanf("%d",&n);
    create(&head,n);
    reverse(&head);
    return 0;
}