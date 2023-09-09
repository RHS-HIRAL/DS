//INFIX TO POSTFIX WITH PARENTHESIS

#include<stdio.h>
#include<stdlib.h>
#define N 20
char infix[N],postfix[N]="",stack[N];
int I=0,P=0,top=-1;

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
        default : return 1;
    }
}

int f(char c){
    switch(c){
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 3;
        case '^': return 6;
        case '(': return 9;
        case ')': return 0;
        default : return 7;
    }
}

int g(char c){
    switch(c){
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '^': return 5;
        case '(': return 0;
        default : return 8;
    }
}

void disp(){
    int i=0;
    printf("\n\tstack : ");
    for(i=0;i<=top;i++){
        printf(" %c",stack[i]);
    }
}

int main(){
    char next,temp;
    int i,len,R=0;
    printf("Enter infix expression : ");
    gets(infix);
    len=strlen(infix);
    infix[len]=')';
    infix[len+1]='\0';
    printf("INFIX : ");
    puts(infix);
    push('(');
    disp();
    //3
    next=infix[I++];
    while(next!=NULL){
        // 5
        printf("\nnext = %c",next);
        if(top<0){
            printf("\n...INVALID....");
            exit(0);
        }
        while(f(next)<g(stack[top])){
            temp=pop();
            postfix[P++]=temp;
            R = R + r(temp);
            if(R<1){
                printf("\n.....R...INVALID....");
                exit(0);
            }
            disp();
        }
        //6
        if(f(next)!=g(stack[top])){
            push(next);
            disp();
        }
        else{
            pop();
            disp();
        }
        //7
        next=infix[I++];
    }

    //8
    if(top!=-1 || R!=1){
        printf("\n...Invalid Expression...");
    }
    else{
        printf("\n...Valid Expression...\n");
        puts(postfix);
    }

    return 0;
}
