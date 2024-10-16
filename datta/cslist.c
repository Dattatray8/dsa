#include<stdio.h>
#include<stdlib.h>

//node creation
struct node
{
    int data;
    struct node *next;
};

//linklist creation
struct node *create(struct node *cslist,int n)
{
    struct node *temp, *newnode;
    int i;
    cslist=NULL;
    for(i=0;i<n;i++){
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter data part:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
    if(cslist==NULL)
    {
        cslist=temp=newnode;
        temp->next=cslist;
    }
    else
    {
        temp->next=newnode;
        newnode->next=cslist;
        temp=newnode;
    }
    }
    return cslist;
}


//linklist display
struct node *display(struct node *cslist)
{
    struct node *temp;
    temp=cslist;
    do
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }while(temp!=cslist);
    return cslist;

}

//linlkist  insert
struct node *insert(struct node *cslist)
{
    int i,pos;
    struct node *temp, *newnode, *temp1;
    temp=cslist;
    printf("Enter the position:");
    scanf("%d",&pos);
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter data part:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(pos==1)
    {
        while(temp->next!=cslist)
            temp=temp->next;
        newnode->next=cslist;
        temp->next=cslist;
        cslist=newnode;
        printf("%d is inserted\n",newnode->data);
    }
    else
    {
        for(i=1;i<pos-1;i++)
        temp=temp->next;
        temp1=temp->next;
        newnode->next=temp1;
        temp->next=newnode;
        printf("%d is inserted\n",newnode->data);
    }
    return cslist;
}

//linklist delete
struct node *delete(struct node *cslist)
{
    int i,pos;
    struct node *temp, *temp1;
    temp=cslist;
    printf("Enter the position:");
    scanf("%d",&pos);
    if(pos==1)
    {
        while(temp->next!=cslist)
        temp=temp->next;
        temp1=temp->next;
        cslist=temp1->next;
        temp->next=temp1->next;
        free(temp1);
    }
    else{
        for(i=1;i<pos-1;i++)
            temp=temp->next;
            temp1=temp->next;
            temp->next=temp1->next;
            free(temp1);
    }
    return cslist;
}

//main function
int main()
{
    int i,n,ch;
    struct node *cslist=NULL;
    do{
    printf("Enter your choice :");
    printf("\n1.Create \n2.Display \n3.insert \n4.Delete 5.Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        printf("Enter the number of nodes to be created:");
        scanf("%d",&n);
        cslist=create(cslist,n);
        break;
        case 2:
        display(cslist);
        break;
        case 3:
        cslist=insert(cslist);
        break;
        case 4:
        cslist=delete(cslist);
        break;
        case 5:
        return 0;
    }
    }while(ch<6);
    return 0;
}
