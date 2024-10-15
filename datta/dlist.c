#include<stdio.h>
#include<stdlib.h>

//node creation
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

//linklist creation
struct node *create(struct node *dlist,int n)
{
    struct node *temp, *newnode;
    int i;
    dlist=NULL;
    for(i=0;i<n;i++){
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter data part:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;
    if(dlist==NULL)
    {
        dlist=temp=newnode;
    }
    else
    {
        temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;
    }
    }
    return dlist;
}

//linklist display
struct node *display(struct node *dlist)
{
    struct node *temp;
    temp=dlist;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    return dlist;

}

//linlkist  insert
struct node *insert(struct node *dlist)
{
    int i,pos;
    struct node *temp, *newnode, *temp1;
    temp=dlist;
    printf("Enter the position:");
    scanf("%d",&pos);
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter data part:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(pos==1)
    {
        newnode->next=dlist;
        dlist->prev=newnode;
        dlist=newnode;
        printf("%d is inserted\n",newnode->data);
    }
    else
    {
        for(i=1;i<pos-1;i++)
        temp=temp->next;
        temp1=temp->next;
        newnode->next=temp1;
        temp1->prev=newnode;
        temp->next=newnode;
        newnode->prev=temp;
        printf("%d is inserted\n",newnode->data);
    }
    return dlist;
}

//linklist delete
struct node *delete(struct node *dlist)
{
    int i,pos;
    struct node *temp, *temp1;
    temp=dlist;
    printf("Enter the position:");
    scanf("%d",&pos);
    if(pos==1)
    {
        dlist=temp->next;
        dlist->prev=NULL;
        free(temp);
    }
    else{
        for(i=1;i<pos-1;i++)
            temp=temp->next;
            temp1=temp->next;
            temp->next=temp1->next;
            temp1->next->prev=temp;
            free(temp1);
    }
    return dlist;
}

//main function
int main()
{
    int i,n,ch;
    struct node *dlist=NULL;
    do{
    printf("Enter your choice :");
    printf("\n1.Create \n2.Display \n3.insert \n4.Delete 5.Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        printf("Enter the number of nodes to be created:");
        scanf("%d",&n);
        dlist=create(dlist,n);
        break;
        case 2:
        display(dlist);
        break;
        case 3:
        dlist=insert(dlist);
        break;
        case 4:
        dlist=delete(dlist);
        break;
        case 5:
        return 0;
    }
    }while(ch<6);
    return 0;
}