#include<stdio.h>
#include<stdlib.h>
#define n 3
int rear=-1,front=-1,queue[n];

void insert(){
    if(rear>=n-1){
        printf("==========================================");
        printf("\nOverflow\n");
        printf("==========================================\n");
        return;
    }
    if(front==-1) front=rear=0;
    else rear=rear+1;
    printf("Enter element : ");
    scanf("%d",&queue[rear]);
}

void dlt(){
    int item;
    if(front==-1){
        printf("==========================================");
        printf("\nUnderflow\n");
        printf("==========================================\n");
    }
    item=queue[front];
    if(front==rear){
        front=rear=-1;
    }
    else{
        front=front+1;
    }
}

void main(){
    printf("EN: 220410107028\nName: Hiral Shah.");
    int i,choice;
    while(1){
        printf("\n=======================================================");
        printf("\nWhat operation would you like to do : ");
        printf("\n1.Insert \t2.Delete \t3.Display \t4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                dlt();
                break;
            case 3:
                printf("\nElement in queue are:");
                for(i=front;i<=rear;i++){
                    printf("\n%d",queue[i]);
                }
                break;
            case 4:
                exit (0);
            default:
                printf("\nInvalid choice...");
        }
    }
}
