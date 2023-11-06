#include<stdio.h>
#include<stdlib.h>
#define N 5

int stk[N],top=-1;

void push(int x){
    if(top>=N-1){
        printf("Overflow!\nThe defined size of the stack is %d.",N);
    }
    else{
        top = top +1;
        stk[top]= x;
    }
}

int pop(){
    if(top==-1){
        printf("Underflow!\nThe stack is empty.");
        return 0;
    }
    else{
        top = top -1;
        return(stk[top+1]);
    }
}

int peep(int i){
    if(top-i+1<0){
        printf("You entered a position out of the range.");
        return 0;
    }
    else{
        return(stk[top-i+1]);
    }
}

void change(int i, int x){
    if(top-i+1<0){
        printf("You entered a position out of the range.");
        return 0;
    }
    else{
        (stk[top-i+1])=x;
    }
}

void display(){
    int i;
    printf("Stack: ");
    for(i=0;i<=top;i++){
        printf(" %d",stk[i]);
    }
}

void main(){
    printf("EN: 220410107028\nName: Hiral Shah.");
    int choice, x, d, i, val;
    while(1){
        printf("\n====================================================================\n\t\t\t\tGUIDE\n====================================================================\n 1.Push    2.Pop    3.Peep    4.Change    5.Display stack    6.Exit\n====================================================================\nEnter your choice= ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            printf("Enter data: ");
            scanf("%d",&x);
            push(x);
            break;
        case 2:
            d=pop();
            printf("The popped value is %d",d);
            break;
        case 3:
            printf("Enter position from top side: ");
            scanf("%d",i);
            d = peep(i);
            printf("The value at position %d is %d", i, d);
        case 4:
            printf("Enter position from top side: ");
            scanf("%d",i);
            printf("Enter new data: ");
            scanf("%d",&x);
            val = peep(i);
            change(i,x);
            printf("%d was replaced by %d", val, peep(i));
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Enter from the above given choices only.");
        }
    }
}
