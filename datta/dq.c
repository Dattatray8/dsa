#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *rear=NULL;
struct node *front=NULL;

int isempty()
{
    if(front==NULL)
    {
        printf("Queue is underflow\n");
        return 1;
    }
    else{
        printf("Queue is not empty\n");
        return 0;
    }
}

void enqueue()
{
    int val;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter data part:\n");
    scanf("%d",&val);
    newnode->data=val;
    if(rear==NULL)
    {
        newnode->next=NULL;
        front=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}

int dequeue()
{
    int item;
    struct node *temp;
    if(front==NULL)
    {
        printf("Queue is underflow\n");
        return -1;
    }
        item=front->data;
        temp=front;
        front=front->next;
        free(temp);
        printf("element is deleted");
        return item;
    
}

int peek()
{
    int data;
    data=front->data;
    printf("Peek values is %d",data);
    return data;
}

void display()
{
    if (isempty()) {
        printf("Queue is empty\n");
        return;
    }
    struct node *temp=front;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

int main()
{
    int ch;
    do{
        printf("Enter your choice:\n");
        printf("\n 1.isEmpty \n 2.Push \n3.Pop \n4.Peek \n 5.Display\n 6.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            isempty();
            break;
            case 2:
            enqueue();
            break;
            case 3:
            dequeue();
            break;
            case 4:
            peek();
            break;
            case 5:
            display();
            break;
            case 6:
            return 0;
        }
    }while(ch<6);
    return 0;
}   