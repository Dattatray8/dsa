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
// concate linklist
struct node *concat(struct node *slist,struct node  *slist2)
{
    struct node *temp, *temp1;
    temp=slist;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=slist2;
    return slist;
}

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

//count nodes
void cnt(struct node *slist)
{
    struct node * temp;
    temp=slist;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;

    }
    printf("\n %d nodes are present in list",count);
}

int main()
{
    int i,n;
    struct node *slist=NULL;
    struct node *slist2=NULL;
    struct node *combine=NULL;
    printf("Enter no of node to be created in linklist1:");
    scanf("%d",&n);
    slist=create(slist,n);
    printf("Enter no of node to be created in linklist2:");
    scanf("%d",&n);
    slist2=create(slist2,n);
    printf("Combine linklist is:");
    combine=concat(slist,slist2);
    display(combine);
    cnt(slist);
    return 0;
}