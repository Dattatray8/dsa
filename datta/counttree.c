#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int value){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node * insert(struct node *root,int data){
    if(root==NULL)
    return create(data);

    if(data < root->data)
    {
    root->left= insert(root->left,data);
    }
    else if(data > root->data){
        root->right=insert(root->right,data);
    }
    return root;
}

int cntleaf(struct node *root){
    if(root==NULL)
    return 0;

    if(root->left==NULL && root->right==NULL)
    return 1;

    return cntleaf(root->left)+cntleaf(root->right);
}

int cntnonleaf(struct node *root){
    if(root==NULL || root->left==NULL && root->right==NULL)
    return 0;

    return 1+cntnonleaf(root->left)+cntnonleaf(root->right);
}

void inorder(struct node *root){
    if(root==NULL)
    return;

    inorder(root->left);
    printf("%d->",root->data);
    inorder(root->right);
}

int main(){
    struct node *root=NULL;
    root=insert(root,99);
    insert(root,9);
    insert(root,88);
    insert(root,34);
    insert(root,45);
    insert(root,1);
    insert(root,98);
    insert(root,12);
    insert(root,77);

    printf("Inorder list is :");
    inorder(root);

    int leaf=cntleaf(root);
    int nleaf=cntnonleaf(root);
    printf("\nleaf nodes are :%d",leaf);
    printf("\nNon leaf nodes are :%d",nleaf);
    return 0;
}