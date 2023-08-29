//malloc, calloc, free

#include<stdio.h>
#include<stdlib.h>

int main(){
    int* a;
    int n, i, x;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    for(i=0;i<n;i++){
        printf("Enter %d element: ", i+1);
        scanf("%d", &x);
        *(a+i)=x;
    }
    for(i=0;i<n;i++){
        printf("Element %d : %d\n", i+1, *(a+i));
        printf("Address of %d : %d\n", i+1, a+i);
    }
    return 0;
}
