#include<stdio.h>
#include<stdlib.h>

//node creation
struct node
{
    int data;
    struct node *next;
};

//linklist creation
struct node *create(struct node *slist,int n)
{
    struct node *temp, *newnode;
    int i;
    slist=NULL;
    for(i=0;i<n;i++){
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter data part:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
    if(slist==NULL)
    {
        slist=temp=newnode;
    }
    else
    {
        temp->next=newnode;
        temp=newnode;
    }
    }
    return slist;
}

//another linklist create
// struct node *create2(struct node *slist2,int n)
// {
//     struct node *temp, *newnode;
//     int i;
//     slist2=NULL;
//     for(i=0;i<n;i++){
//         newnode=(struct node *)malloc(sizeof(struct node));
//         printf("Enter data part:");
//         scanf("%d",&newnode->data);
//         newnode->next=NULL;
//     if(slist2==NULL)
//     {
//         slist2=temp=newnode;
//     }
//     else
//     {
//         temp->next=newnode;
//         temp=newnode;
//     }
//     }
//     return slist2;
// }

// // concate linklist
// struct node *concat(struct node *slist,struct node  *slist2)
// {
//     struct node *temp, *temp1;
//     temp=slist;
//     temp1=slist2;
//     while(temp!=NULL)
//     {
//         temp=temp->next;
//     }
//     temp->next=slist2;
    
// }


//linklist display
struct node *display(struct node *slist)
{
    struct node *temp;
    temp=slist;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    return slist;

}

//linlkist  insert
struct node *insert(struct node *slist)
{
    int i,pos;
    struct node *temp, *newnode, *temp1;
    temp=slist;
    printf("Enter the position:");
    scanf("%d",&pos);
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter data part:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(pos==1)
    {
        newnode->next=slist;
        slist=newnode;
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
    return slist;
}

//linklist delete
struct node *delete(struct node *slist)
{
    int i,pos;
    struct node *temp, *temp1;
    temp=slist;
    printf("Enter the position:");
    scanf("%d",&pos);
    if(pos==1)
    {
        slist=temp->next;
        free(temp);
    }
    else{
        for(i=1;i<pos-1;i++)
            temp=temp->next;
            temp1=temp->next;
            temp->next=temp1->next;
            free(temp1);
    }
    return slist;
}

//main function
int main()
{
    int i,n,ch;
    struct node *slist=NULL;
    do{
    printf("Enter your choice :");
    printf("\n1.Create \n2.Display \n3.insert \n4.Delete 5.Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        printf("Enter the number of nodes to be created:");
        scanf("%d",&n);
        slist=create(slist,n);
        break;
        case 2:
        display(slist);
        break;
        case 3:
        slist=insert(slist);
        break;
        case 4:
        slist=delete(slist);
        break;
        case 5:
        return 0;
    }
    }while(ch<6);
    return 0;
}