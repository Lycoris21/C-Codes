#include <stdio.h>
#include <stdlib.h>
#include "STACKADT_LINKEDLIST_H"
//#include "STACKADT_ARRAY_H"

void insertBottom(Stack *, char);
void populateStack(Stack *S);

int main(){
    Stack MyStack;
    initStack(&MyStack);
    populateStack(&MyStack);
    printAll(&MyStack);
    return 0;
}

void insertBottom(Stack *S, char ch){
    if(isFull(*S)!=TRUE){
        Stack temp;
        initStack(&temp);
        while(isEmpty(*S)!=TRUE){
            push(&temp, top(*S));
            pop(S);
        }
        push(S, ch);   
        while(isEmpty(temp)!=TRUE){
            push(S, top(temp));
            pop(&temp);
        }   
    }
}

void populateStack(Stack *S){
    char a[] = {'1', '2', '3'};
    char b[] = {'a', 'b', 'c', };
    int x;   
    for(x=0; x < (sizeof(a)/sizeof(a[0])); x++){
        push(S, a[x]);
    }
    for(x=0; x< sizeof(b)/sizeof(b[0]); x++){
        insertBottom(S, b[x]);
    }
}