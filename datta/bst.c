#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void inorder(struct node *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    printf("%d->",root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if(root==NULL)
    return;
    printf("%d->",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    printf("%d->",root->data);
}

struct node *create(int value)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
}

struct node *insert(struct node *root,int data)
{
    if(root==NULL)
    return create(data);

    if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }
    return root;
}

int main(){
    struct node *root=NULL;
    root=insert(root,99);
    insert(root,10);
    insert(root,54);
    insert(root,33);
    insert(root,1);
    insert(root,98);
    insert(root,89);
    insert(root,22);
    insert(root,74);

    printf("INORDER LIST IS :\n");
    inorder(root);
    printf("\nPREORDER LIST IS:\n");
    preorder(root);
    printf("\nPOSTORDER LIST IS:\n");
    postorder(root);

}