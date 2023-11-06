#include<stdio.h>
#include<stdlib.h>
#define N 4

int Q[N],f=-1,r=-1;

void CQ_enqueue(int y){
    if(r>=N-1)
        r = 0;
    else
        r = r + 1;

    if(r==f){
        printf("\nQueue is Overflow...!!!");
        if(r==0) r = N-1;
        else r = r - 1;
    }
    else{
        Q[r] = y;
        if(f==-1) f=0;
    }
   printf("\nr = %d and f = %d",r,f);
}

int CQ_dequeue(){
    int y;
    if(f==-1){
        printf("\nQueue is Underflow....!!!\n");
        printf("\nr = %d and f = %d",r,f);
        y = 0;
    }
    else{
        y = Q[f];
        if(f==r){
            f = -1;
            r = -1;
        }
        if(f>=N-1) f = 0;
        else f = f + 1;
        printf("\nr = %d and f = %d",r,f);
    }
    return y;
}

void CQ_display(){
    int i;
    printf("\nf = %d and r = %d",f,r);
    printf("\nQueue : ");
    if(f<=r){
        for(i=f;i<=r;i++){
            printf("%d ",Q[i]);
        }
    }
    else{
        for(i=f;i<=N-1;i++){
            printf("%d ",Q[i]);
        }
        for(i=0;i<=r;i++){
            printf("%d ",Q[i]);
        }
    }
}

int main(){
    printf("EN: 220410107028\nName: Hiral Shah.\n");
    int c,d,y;
    while(1){
        printf("\n1.Insert\t2.Delete\t3.Display\t4.Exit\nEnter choice :");
        scanf("%d",&c);
        switch(c){
            case 1:
                printf("\nEnter new Value : ");
                scanf("%d",&y);
                CQ_enqueue(y);
                break;
            case 2:
                d = CQ_dequeue();
                printf("\nDeleted Value is %d",d);
                break;
            case 3:
                CQ_display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nEnter proper choice....");
        }
    }
    return 0;
}
