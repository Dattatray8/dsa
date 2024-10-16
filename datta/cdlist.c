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
struct node *create(struct node *cdlist,int n)
{
    struct node *temp, *newnode;
    int i;
    cdlist=NULL;
    for(i=0;i<n;i++){
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter data part:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;
    if(cdlist==NULL)
    {
        cdlist=temp=newnode;
        temp->next=cdlist;
    }
    else
    {
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=cdlist;
        temp=newnode;
    }
    }
    return cdlist;
}

//linklist display
struct node *display(struct node *cdlist)
{
    struct node *temp;
    temp=cdlist;
    do
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }while(temp!=cdlist);
    return cdlist;

}

//linlkist  insert
struct node *insert(struct node *cdlist)
{
    int i,pos;
    struct node *temp, *newnode, *temp1;
    temp=cdlist;
    printf("Enter the position:");
    scanf("%d",&pos);
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter data part:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(pos==1)
    {
        while(temp->next!=cdlist)
        temp=temp->next;
        newnode->next=cdlist;
        cdlist->prev=newnode;
        temp->next=newnode;
        cdlist=newnode;
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
    return cdlist;
}

//linklist delete
struct node *delete(struct node *cdlist)
{
    int i,pos;
    struct node *temp, *temp1;
    temp=cdlist;
    printf("Enter the position:");
    scanf("%d",&pos);
    if(pos==1)
    {
        while(temp->next!=cdlist)
        temp=temp->next;
        temp1=temp->next;
        cdlist=temp1->next;
        temp->next=cdlist;
        cdlist->prev=temp;
        free(temp1);
    }
    else{
        for(i=1;i<pos-1;i++)
            temp=temp->next;
            temp1=temp->next;
            temp->next=temp1->next;
            temp1->next->prev=temp;
            free(temp1);
    }
    return cdlist;
}

//main function
int main()
{
    int i,n,ch;
    struct node *cdlist=NULL;
    do{
    printf("Enter your choice :");
    printf("\n1.Create \n2.Display \n3.insert \n4.Delete 5.Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        printf("Enter the number of nodes to be created:");
        scanf("%d",&n);
        cdlist=create(cdlist,n);
        break;
        case 2:
        display(cdlist);
        break;
        case 3:
        cdlist=insert(cdlist);
        break;
        case 4:
        cdlist=delete(cdlist);
        break;
        case 5:
        return 0;
    }
    }while(ch<6);
    return 0;
}