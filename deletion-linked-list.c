#include <stdio.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *cur,*head=NULL,*tail=NULL;
    int n;
    printf("Enter the no on inputs \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cur=malloc(sizeof(struct node));
        printf("Enter the value of %d data \n",i+1);
        scanf("%d",&cur->data);
        if(head==NULL)
        {
            head=tail=cur;
        }
        else
        {
            tail->next=cur;
            tail=cur;
        }
    }
    cur=head;
    struct node *ptr=NULL;
    int d;
    printf("Enter the value to be deleted \n");
    scanf("%d",&d);
    while(cur->data!=d)
        {
            ptr=cur;
            cur=cur->next;
        }
    ptr->next=cur->next;
    free(cur);
    cur=head;
    while(cur!=NULL)
    {
        printf("%d ",cur->data);
        cur=cur->next;
    }
    return 0;
}

