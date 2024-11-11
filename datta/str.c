#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char data;
    struct node *next;
};
struct node *top;

int isempty()
{
    if(top==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void push(char val)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
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
        printf("%c",temp->data);
        temp=temp->next;
    }
}

// void reverse(){
//     int i,a;
//     char str[30];
//     printf("Input string :");
//     scanf("%[^\n]s",&str);
//     for(i=0;i<strlen(str);i++){
//         push(str[i]);
//     }
//     printf("reverse string is:\n");
//     display();
    
// }

void reverse() {
    char a[30]; // Variable for input string
    char b[30]; // Variable for reversed string
    printf("Input string: ");
    scanf(" %[^\n]s", a);  // Read the input string

    // Push each character of the input string onto the stack
    for (int i = 0; i < strlen(a); i++) {
        push(a[i]);
    }

    // Pop each character from the stack to get the reversed string
    int index = 0;
    while (!isempty()) {
        b[index++] = pop();
    }
    b[index] = '\0'; // Null terminate the reversed string

    // Print both strings
    printf("Original string : %s\n", a);
    printf("Reversed string : %s\n", b);
    if(strcmp(a,b)==0){
        printf("\nEntered string is a palindrome");
    }
    else{
        printf("\nEntered string is not a palindrome");
    }
}

int main()
{
    int ch;
    reverse();
    return 0;
}