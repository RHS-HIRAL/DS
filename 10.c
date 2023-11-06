#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node{
    struct node *next;
    int data;
    struct node *prev;
};
struct node *start = NULL, *create_ll(struct node *), *display(struct node *), *insert_beg(struct node *), *insert_end(struct node *), *delete_end(struct node *), *delete_before(struct node *);

int main(){
    printf("EN: 220410107028\nName: Hiral Shah.");
    int option;
    while(1){
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Delete a node from the end");
        printf("\n 6: Delete a node before a given node");
        printf("\n 7: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch(option){
            case 1: start = create_ll(start);
                printf("\n DOUBLY LINKED LIST CREATED");
                break;
            case 2: start = display(start);
                break;
            case 3: start = insert_beg(start);
                break;
            case 4: start = insert_end(start);
                break;
            case 5: start = delete_end(start);
                break;
            case 6: start = delete_before(start);
                break;
            case 7:
                exit(0);
            default:
                printf("Enter valid option.");
                break;}}
    return 0;
}

struct node *create_ll(struct node *start){
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);
    while(num != -1){
        if(start == NULL){
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node -> prev = NULL;
            new_node -> data = num;
            new_node -> next = NULL;
            start = new_node;
        }
        else{
            ptr=start;
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node->data=num;
            while(ptr->next!=NULL)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->prev=ptr;
            new_node->next=NULL;
        }
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
    return start;
}

struct node *display(struct node *start){
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL){
        printf("\t %d", ptr -> data);
        ptr = ptr -> next;
    }
    return start;
}

struct node *insert_beg(struct node *start){
    struct node *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;
    start -> prev = new_node;
    new_node -> next = start;
    new_node -> prev = NULL;
    start = new_node;
    return start;
}

struct node *insert_end(struct node *start){
    struct node *ptr, *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;
    ptr=start;
    while(ptr -> next != NULL)
        ptr = ptr -> next;
    ptr -> next = new_node;
    new_node -> prev = ptr;
    new_node -> next = NULL;
    return start;
}

struct node *delete_end(struct node *start){
    struct node *ptr;
    ptr = start;
    while(ptr -> next != NULL)
        ptr = ptr -> next;
    ptr -> prev -> next = NULL;
    free(ptr);
    return start;
}

struct node *delete_before(struct node *start){
    struct node *ptr, *temp;
    int val;
    printf("\n Enter the value before which the node has to deleted:");
    scanf("%d", &val);
    ptr = start;
    while(ptr -> data != val)
        ptr = ptr -> next;
    temp = ptr -> prev;
    if(temp == start)
        start = delete_end(start);
    else{
        ptr -> prev = temp -> prev;
        temp -> prev -> next = ptr;
    }
    free(temp);
    return start;
}
