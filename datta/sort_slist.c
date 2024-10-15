#include <stdio.h>
struct node {
    int data;
    struct node *next;
};

struct node *create(struct node *slist, int n) {
    struct node *temp, *newnode;
    int i;
    slist = NULL;
    for (i = 1; i <= n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data part:\n");
        scanf("%d", &newnode->data);
        newnode->next = NULL; // Initialize next pointer to NULL
        if (slist == NULL) {
            temp = slist = newnode;
        } else {
            temp->next = newnode;
            temp = newnode; // Move temp to newnode
        }
    }
    return slist;
}
struct node *display(struct node *slist) {
    struct node *temp;
    temp = slist;
    while (temp != NULL) { // Traverse till the end of the list
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    return slist;
}
struct node *sort(struct node *slist)
{
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
int main()
{
  int n;
  struct node *slist=NULL;
printf("Enter number of nodes to be created: \n");
scanf("%d", &n);
slist = create(slist, n); // Assign return value
printf("List is:\n");
display(slist);

slist = sort(slist);

printf(" \nSorted list is :\n");
display(slist);
}