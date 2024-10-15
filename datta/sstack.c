#include<stdio.h>
#define max 10
struct stack
{
    int a[max];
    int top;
};

//stack initialization
int init(struct stack *s)
{
    s->top=-1;
    printf("Stack is initialized.\n");
}

//stack isempty
int isempty(struct stack *s)
{
    if(s->top==-1)
    {
    printf("Stack is empty");
    return 1;
    }
    else{ 
    printf("stack is not empty.");
    return 0;
    }
}

//stack isfull
int isfull(struct stack *s)
{
    if(s->top==max-1)
    {
        printf("Stack is full.");
        return 1;
    }
    else
    {
        printf("Stack is not full.");
        return 0;
    }
}

//stack push
void push(struct stack *s,int n)
{
    if(s->top==max-1){
        printf("stack is overflow");
    }
    else
    {
    s->top++;
    s->a[s->top]=n;
    printf("Elemnt is inserted.");
    }
}

//stack pop
int pop(struct stack *s)
{
    if(s->top==-1)
    {
        printf("stack is underflow");
    }
    else{
    s->top--;
    printf("Element is deleted.");
    return s->a[s->top];
    }
}

//stack peek
int peek(struct stack *s)
{
    int idx = s->top;
    int data = s->a[idx];
    printf("Peek value is %d",data);
    return data;
}

//display
void display(struct stack *s)
{
    int i;
    for(i=s->top;i>-1;i--)
    {
        printf("%d\t",s->a[i]);
    }
}

int main()
{
    int n,ch;
    struct stack s; 
    init(&s);
    do{
        printf("Enter your choice:\n");
        printf("\n 1.isEmpty \n 2.isFull \n3.Push \n4.Pop \n 5.Peek \n 6.Display\n7.Exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            isempty(&s);
            break;
            case 2:
            isfull(&s);
            break;
            case 3:
            printf("Enter the data");
            scanf("%d",&n);
            push(&s,n);
            break;
            case 4:
            pop(&s);
            break;
            case 5:
            peek(&s);
            break;
            case 6:
            display(&s);
            break;
            case 7:
            return 0;
        }
    }while(ch<8);
    return 0;
}