#include <stdio.h>
#include<stdlib.h>
#define max 10
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node *root=NULL;
struct node* create_node(int no)
{
    struct node *cur;
    cur=malloc(sizeof(struct node));
    if(cur!=NULL)
    {
        cur->data=no;
        cur->left=cur->right=NULL;
    }
    return cur;
}
typedef struct
{
    int front;
    int rear;
    struct node *data[max];
}queue;
int insert(queue *q,struct node *v)
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
int delete(queue *q,struct node **v)
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
void initq(queue *q)
{
    q->front=q->rear=-1;
}
typedef struct
{
    struct node *data[max];
    int top;
}stack;
int push(stack *s,struct node *v)
{
    if(s->top==max-1)
    {
        printf("overflow \n");
        return 1;
    }
    if(v==NULL)
        return 0;
    s->top++;
    s->data[s->top]=v;
    return 0;
}
int pop(stack *s,struct node **v)
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
void displays(stack s)
{
    for(int i=0;i<=s.top;i++)
        printf("%d ",(s.data[i])->data);
    printf("%d ",s.top);
    printf("\n");
}
void inits(stack *s)
{
    s->top=-1;
}
int isemptyq(queue q)
{
    if(q.front==-1)
        return 1;
    else
        return 0;
}
int isemptys(stack s)
{
    if(s.top==-1)
        return 1;
    else
        return 0;
}
void dislevel(struct node *r)
{
    queue q1;
    initq(&q1);
    insert(&q1,r);
    while(!isemptyq(q1))
    {
        struct node *ptr;
        delete(&q1,&ptr);
        printf("%d",ptr->data);
        if(ptr->left!=NULL)
            insert(&q1,ptr->left);
        if(ptr->right!=NULL)
            insert(&q1,ptr->right);
    }
    printf("\n");
}
void inorder(struct node *r)
{
    stack s1;
    inits(&s1);
    struct node *ptr,*cur;
    for(cur=r;cur!=NULL;cur=cur->left)
        push(&s1,cur);
    while(!isemptys(s1))
    {
        pop(&s1,&ptr);
        printf("%d",ptr->data);
        if(ptr->right!=NULL)
        {
            for(cur=ptr->right;cur!=NULL;cur=cur->left)
                push(&s1,cur);
        }
    }
    printf("\n");
}
void preorder(struct node *r)
{
    stack s1;
    inits(&s1);
    struct node *ptr;
    ptr=r;
    push(&s1,ptr);
    while(!isemptys(s1))
    {
        pop(&s1,&ptr);
        printf("%d",ptr->data);
        push(&s1,ptr->right);
        push(&s1,ptr->left);
    }
    printf("\n");
}
void postorder(struct node *r)
{
    stack s1;
    inits(&s1);
    struct node *cur,*ptr,*ptr1;
    for(cur=r;cur!=NULL;cur=cur->left)
    {
        if(cur->right)
            push(&s1,cur->right);
        push(&s1,cur);
    }
    while(!isemptys(s1))
    {
        pop(&s1,&ptr);
        if(!ptr->right)
            printf("%d",ptr->data);
        else
        {
            if(isemptys(s1))
                printf("%d",ptr->data);
            else
            {
                pop(&s1,&ptr1);
                if(ptr!=ptr1)
                {
                    push(&s1,ptr1);
                    printf("%d",ptr->data);
                }
                else
                {
                    push(&s1,ptr);
                    for(cur=ptr1;cur!=NULL;cur=cur->left)
                    {
                        if(cur->right)
                            push(&s1,cur->right);
                        push(&s1,cur);
                    }
                }
            }
        }
    }
    printf("\n");
}
int main()
{
    root=create_node(6);
    root->left=create_node(4);
    root->right=create_node(8);
    root->left->left=create_node(3);
    root->left->right=create_node(5);
    root->right->left=create_node(7);
    root->right->right=create_node(9);
    dislevel(root);
    inorder(root);
    postorder(root);
    preorder(root);
    return 0;
}
