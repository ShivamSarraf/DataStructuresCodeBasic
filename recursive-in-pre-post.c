#include <stdio.h>
#include<stdlib.h>
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
    root=create_node(6);
    root->left=create_node(4);
    root->right=create_node(8);
    root->left->left=create_node(3);
    root->left->right=create_node(5);
    root->right->left=create_node(7);
    root->right->right=create_node(9);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
}
