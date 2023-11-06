#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front, *rear;

void insert();
void delete();
void display();

void insert(){
    struct node *temp;
    int x;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp == NULL){
        printf("\nOverflow!!");
    }
    else{
        printf("\nEnter value : ");
        scanf("%d",&x);
        temp->data = x;
        if(front == NULL){
            front = temp;
            rear = temp;
            front->next = NULL;
            rear->next = NULL;
        }
        else{
            rear->next = temp;
            rear = temp;
            rear->next = NULL;
        }
    }
}

void delete(){
    struct node *temp;
    if(front == NULL){
        printf("\nUnderflow!!");
    }
    else{
        temp = front;
        front = front->next;
    }
}

void display(){
    struct node *temp;
    temp = front;
    if(front == NULL){
        printf("\nQueue is empty.");
    }
    else{
        printf("\nPrinting value:\n");
        while(temp!=NULL){
            printf("%d\n",temp->data);
            temp = temp->next;
        }
    }
}

void main(){
    int choice;
    while(1){
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
        printf("\nEnter your choice :");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit (0);
        }
    }
}
