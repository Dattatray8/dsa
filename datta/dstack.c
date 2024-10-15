#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top;

int isempty()
{
    if(top==NULL)
    {
        printf("Stack is underflow\n");
        return 1;
    }
    else{
        printf("stack is not empty\n");
        return 0;
    }
}

void push()
{
    int val;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter data part:\n");
    scanf("%d",&val);
    if(top==NULL)
    {
        newnode->data=val;
        newnode->next=NULL;
        top=newnode;
    }
    else
    {
        newnode->data=val;
        newnode->next=top;
        top=newnode;
    }
}

int pop()
{
    int item;
    struct node *temp;
    if(top==NULL)
    {
        printf("stack is underflow\n");
    }
    else
    {
        item=top->data;
        temp=top;
        top=top->next;
        free(temp);
        return item;
    }
    return -1;
}

int peek()
{
    int data;
    data=top->data;
    printf("Peek values is %d",data);
    return data;
}

void display()
{
    struct node *temp=top;
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
        printf("\n 1.isEmpty \n 2.Push \n3.Pop \n4.Peek \n 5.Exit\n 6.Display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            isempty();
            break;
            case 2:
            push();
            break;
            case 3:
            pop();
            break;
            case 4:
            peek();
            break;
            case 5:
            return 0;
            case 6:
            display();
            break;
        }
    }while(ch<6);
    return 0;
}