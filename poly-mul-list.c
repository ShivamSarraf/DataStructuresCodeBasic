#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int power;
    struct node *next;
};
void create(struct node **h,int a)
{
    for(int i=0;i<a;i++)
    {
    struct node *ptr,*cur;
    cur=malloc(sizeof(struct node));
    printf("Enter the value of and power of %d input \n",i+1);
    scanf("%d%d",&cur->data,&cur->power);
    if(*h==NULL)
    {
        *h=ptr=cur;
    }
    else
    {
        ptr->next=cur;
        ptr=cur;
    }
    }
}
void print(struct node *h)
{
    for(;h!=NULL;h=h->next)
    {
        printf("%dx^%d ",h->data,h->power);
    }
    printf("\n");
}
int main()
{
    int n,m;
    printf("Enter the no of inputs in each list \n");
    scanf("%d%d",&n,&m);
    struct node *h1=NULL,*h2=NULL,*h3=NULL,*ptr1,*ptr2,*ptr3,*ptr4,*ptr5;
    create(&h1,n);
    create(&h2,m);
    create(&h3,n*m);
    print(h1);
    print(h2);
    ptr1=h1;
    ptr2=h2;
    ptr3=h3;
    for(;ptr1!=NULL;ptr1=ptr1->next)
    {
        for(;ptr2!=NULL;ptr2=ptr2->next)
        {
            ptr3->data = ptr2->data * ptr1->data;
            ptr3->power = ptr2->power + ptr1->power;
            ptr3=ptr3->next;
        }
        ptr2=h2;
    }
    ptr3=h3;
    ptr4=ptr5=NULL;
    print(h3);
    for(;ptr3!=NULL;ptr3=ptr3->next)
    {
        ptr4=ptr3->next;
        ptr5=ptr3;
        while(ptr4!=NULL)
        {
            if(ptr3->power==ptr4->power)
            {
                ptr3->data = ptr3->data + ptr4->data;
                ptr5->next=ptr4->next;
                free(ptr4);
            }
            ptr5=ptr4;
            ptr4=ptr4->next;
        }
    }
    print(h3);
    return 0;
}

