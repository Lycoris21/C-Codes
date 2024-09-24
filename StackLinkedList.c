#include <stdio.h>
#include <stdlib.h>

typedef enum{FALSE, TRUE} Bool;

typedef struct node{
    char elem;
    struct node *link;
}*Stack;

void initStack(Stack *);
void push(Stack *, char);
void pop(Stack *);
char top(Stack);
Bool isEmpty(Stack);
Bool isFull(Stack);
void printThis(char);
void printAll(Stack *);
void insertBottom(Stack *, char);
void populateStack(Stack *S);

void insertNoPushPop1(Stack *, char);
void insertSorted(Stack *, char);

int main(){
    Stack MyStack;
    initStack(&MyStack);
    populateStack(&MyStack);
    insertNoPushPop1(&MyStack, 'c');
    insertSorted(&MyStack, 'c');
    printAll(&MyStack);
    return 0;
}


void initStack(Stack *S){
    (*S) = NULL;
}

void push(Stack *S, char ch){
    if(isFull(*S) != TRUE){
        Stack temp = (Stack) malloc(sizeof(struct node));
        if(temp != NULL){
            temp->elem = ch;
            temp->link = (*S);
            (*S) = temp; 
        }
    }else {
        printf("Stack is full.\n");
    }
}

void pop(Stack *S){
    if(isEmpty(*S)!=TRUE){
        Stack temp = (*S);
        (*S) = temp->link;
        free(temp);
    }else {
        printf("Stack is empty.\n");
    }
}

char top(Stack S){
    return (isEmpty(S)!=TRUE)? (S->elem) : '\0';
}

Bool isEmpty(Stack S){
    return (S!=NULL)? FALSE: TRUE;
}

Bool isFull(Stack S){
    return FALSE;
}

void printThis(char ch){
    printf("%c\n", ch);
}

void printAll(Stack *S){
    Stack temp;
    initStack(&temp);
    while(isEmpty(*S)!=TRUE){
        printThis(top(*S));
        push(&temp, top(*S));
        pop(S);
    }   
    while(isEmpty(temp)!=TRUE){
        push(S, top(temp));
        pop(&temp);
    }   
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
    char b[] = {'a', 'b', 'd', };
    int x;   
    for(x=0; x < (sizeof(a)/sizeof(a[0])); x++){
        push(S, a[x]);
    }
    for(x=0; x< sizeof(b)/sizeof(b[0]); x++){
        insertBottom(S, b[x]);
    }
}

void insertNoPushPop1(Stack *A, char B){
    if(isFull(*A)!=TRUE){
        Stack *temp;
        
        for(temp = A; isEmpty(*temp)!=TRUE && B>(top(*temp)); temp = &((*temp)->link)){}
        Stack Z = (Stack) malloc(sizeof(struct node));
        Z->elem = B;
        Z->link = *temp;
        *temp = Z;
    }
}

void insertSorted(Stack *S, char ch){
    if(isFull(*S)!=TRUE){
        Stack temp;
        initStack(&temp);
        while(isEmpty(*S)!=TRUE && ch>(top(*S))){
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