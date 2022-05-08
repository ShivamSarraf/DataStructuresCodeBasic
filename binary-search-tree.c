#include <stdio.h>
#include<stdlib.h>
#define max 10
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node* insert(struct node *r,int v)
{
    if(r==NULL)
    {
        struct node *cur=malloc(sizeof(struct node));
        cur->left=cur->right=NULL;
        cur->data=v;
        return cur;
    }
    if(v>r->data)
    {
        r->right=insert(r->right,v);
        return r;
    }
    else if(v<r->data)
    {
        r->left=insert(r->left,v);
        return r;
    }
    else
        return r;
}
struct node* find_max(struct node *r)
{
    if(r==NULL)
        return r;
    struct node *cur;
    for(cur=r;cur->right!=NULL;cur=cur->right);
    return cur;
}
struct node* delete(struct node *r,int v)
{
    if(r==NULL)
        return r;
    if(v>r->data)
    {
        r->right=delete(r->right,v);
        return r;
    }    
    else if(v<r->data)
    {
        r->left=delete(r->left,v);
        return r;
    }
    else
    {
        if(r->left&&r->right)
        {
            struct node *cur=find_max(r->left);
            r->data=cur->data;
            r->left=delete(r->left,r->data);
            return r;
        }
        else if(r->right!=NULL)
        {
            struct node *temp=r->right;
            free(r);
            return temp;
        }
        else if(r->left!=NULL)
        {
            struct node *temp=r->left;
            free(r);
            return temp;
        }
        else
        {
            free(r);
            return NULL;
        }
    }
}
void inorder(struct node *r)
{
    if(r!=NULL)
    {
        inorder(r->left);
        printf("%d",r->data);
        inorder(r->right);
    }
}
void postorder(struct node *r)
{
    if(r!=NULL)
    {
        postorder(r->left);
        postorder(r->right);
        printf("%d",r->data);
    }
}
void preorder(struct node *r)
{
    if(r!=NULL)
    {
        printf("%d",r->data);
        preorder(r->left);
        preorder(r->right);
    }
}
int main()
{
    struct node *root;
    root=NULL;
    int n,d;
    do
    {
        printf("1)Insert \n2)Delete \n3)Inorder \n4)Exit \n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            printf("Enter the value to be inserted \n");
            scanf("%d",&d);
            root=insert(root,d);
            break;
            case 2:
            printf("Enter the value to be deleted \n");
            scanf("%d",&d);
            root=delete(root,d);
            break;
            case 3:
            inorder(root);
            printf("\n");
            postorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
            break;
            case 4:
            exit(0); 
            break;
        }
    }while(1);
    return 0;
}
