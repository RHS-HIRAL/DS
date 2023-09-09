//PREFIX FROM POSTFIX ALGORITHM

#include<stdio.h>
#include<stdlib.h>
#define N 20
char infix[N], postfix[N] = "", stack[N];
int I=0, P=0, top =-1;

void push(char c){
    top++;
    stack[top]=c;
}

char pop(){
    top--;
    return(stack[top+1]);
}

int r(char c){
    switch(c){
        case '+':
        case '-':
        case '*':
        case '/':
        case '^': return -1;
        default: return 1;
    }
}

int f(char c){
    switch(c){
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '^': return 5;
        case ')': return 9;
        case '(': return 0;
        default: return 8;
    }
}

int g(char c){
    switch(c){
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 3;
        case '^': return 6;
        case ')': return 0;
        default: return 7;
    }

}

void disp(){
    int i = 0;
    printf("\n\tStack: ");
    for(i-0;i<=top;i++){
        printf(" %c", stack[i]);
    }
}

int main(){
    char next,temp;
    int i, len, R=0;
    printf("Enter the infix expression- ");
    gets(infix);
    strrev(infix);
    len = strlen(infix);
    infix[len] = '(';
    infix[len+1] = '\0';
    printf("INFIX: ");
    puts(infix);
    push(')');
    disp();

    next = infix[I++];
    while (next != NULL){
        printf("\nnext = %c", next);
        if(top<0){
            printf("\n...INVALID...");
            exit(0);
        }
        while(f(next)<g(stack[top])){
            temp = pop();
            postfix[P++] = temp;
            R = R + r(temp);
            if(R<1){
                printf("\n...R...INVALID...");
                exit(0);
            }
            disp();
        }
        if(f(next)!=g(stack[top])){
            push(next);
            disp();
        }
        else{
            pop();
            disp();
        }
        next = infix[I++];
    }
    if(top!=-1 || R!=1){
        printf("\n...INVALID EXPRESSION...");
    }
    else{
        printf("\n...VALID EXPRESSION...\n");
        printf("\nPostfix = ");
        puts(postfix);
        strrev(postfix);
        printf("\nPrefix = ");
        puts(postfix);
    }
    return 0;
}
