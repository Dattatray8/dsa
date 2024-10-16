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

int sort(struct node *slist){
    struct node *i, *j;
    int temp;
    for(i=slist;i!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->data > j->data){
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }
    return slist;
}

int main(){
    int n;
    struct node *slist=NULL;
    printf("Enter the number of nodes to be created :\n");
    scanf("%d",&n);
    slist=create(slist,n);

    printf("ORIGINAL LIST:\n");
    display(slist);

    slist=sort(slist);

    printf("\nSORTED LIST :\n");
    display(slist);
    return 0;
}
