#include<stdio.h>
#define max 5
void accecpt(int n,int a[5][5]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("IS THERE ANY EDGE BETWEEEN V%d AND V%d (1 for Yes and 0 for No):",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
        printf("\n");
    }
}

void display(int n,int a[5][5]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}

void adjlist(int n,int a[5][5]){
    int i,j;
    printf("\nAdjacency List is :\n");

    for(i=0;i<n;i++){
        printf("\nV%d:",i+1);
        for(j=0;j<n;j++){
            if(a[i][j]==1){
                printf("\tV%d");
            }
        }
        printf("\n");
    }
}

int main(){
    int ver, a[max][max];

    printf("Enter the number of vertix:\n");
    scanf("%d",&ver);
    accecpt(ver,a);

    printf("\nAdjacency Matrix is :\n");
    display(ver,a);

    adjlist(ver,a);

    return 0;
}