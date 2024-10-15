#include<stdio.h>
#define max 10
struct queue
{
    int a[max];
    int front,rear;
};

//queue initialization
int init(struct queue *q)
{
    q->rear=-1;
    q->front=-1;
    printf("Queue is initialized.\n");
}

//Queue isempty
int isempty(struct queue *q)
{
    if(q->front==-1)
    {
    printf("Queue is empty\n");
    return 1;
    }
    else{ 
    printf("Queue is not empty.\n");
    return 0;
    }
}

//stack isfull
int isfull(struct queue *q)
{
    if(q->rear==max-1)
    {
        printf("Queue is full.");
        return 1;
    }
    else
    {
        printf("Queue is not full.");
        return 0;
    }
}

//queue push
void push(struct queue *q,int n)
{
    if(isfull(q)){
        printf("\n");
    }
    else
    {
    q->rear++;
    q->a[q->rear]=n;
    printf("Elemnt is inserted.");
    }
}

//queue pop
int pop(struct queue *q)
{
    int n;
    if(isempty(q))
    {
        printf("\n");
    }
    else{
    n=q->a[q->front];
    q->front++;
    printf("Element is deleted.");
    return n;
    }
}

//queue peek
int peek(struct queue *q)
{
    int idx = q->rear;
    int data = q->a[idx];
    printf("Peek value is %d",data);
    return data;
}

//display
void display(struct queue *q)
{
    int i;
    for(i=q->rear;i>-1;i--)
    {
        printf("%d\t",q->a[i]);
    }
}

int main()
{
    int n,ch;
    struct queue q; 
    init(&q);
    do{
        printf("Enter your choice:\n");
        printf("\n 1.isEmpty \n 2.isFull \n3.Push \n4.Pop \n 5.Peek \n 6.Display\n7.Exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            isempty(&q);
            break;
            case 2:
            isfull(&q);
            break;
            case 3:
            printf("Enter the data");
            scanf("%d",&n);
            push(&q,n);
            break;
            case 4:
            pop(&q);
            break;
            case 5:
            peek(&q);
            break;
            case 6:
            display(&q);
            break;
            case 7:
            return 0;
        }
    }while(ch<8);
    return 0;
}