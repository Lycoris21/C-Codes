#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node{
    int data;
    struct node *link;
}*NodePointer;

typedef NodePointer Dictionary[MAX];

typedef enum{FALSE, TRUE} bool;

void initDictionary(Dictionary);
void displayDictionary(Dictionary);
int hash(int data);
void insert(Dictionary, int);
void delete(Dictionary, int);
bool isMember(Dictionary, int);
void makeNull(Dictionary);

int main(){
    Dictionary D;
    initDictionary(D);
    insert(D, 31);
    insert(D, 1);
    insert(D, 11);
    insert(D, 21);
    insert(D, 97);
    displayDictionary(D);


    printf("\n\nDELETED\n\n");
    delete(D, 11);
    delete(D, 31);
    displayDictionary(D);

    printf("\nisMember: %s\n\n", isMember(D, 21)? "TRUE": "FALSE");
    printf("\nisMember: %s\n\n", isMember(D, 37)? "TRUE": "FALSE");

    makeNull(D);
    displayDictionary(D);
    return 0;
}

void initDictionary(Dictionary A){
    int x;
    for(x=0; x<MAX; x++){
        A[x] = NULL;
    }
}

void displayDictionary(Dictionary A){
    int x;
    NodePointer trav;
    for(x=0; x<MAX; x++){
        printf("Row %d: ", x);
        for(trav = A[x]; trav != NULL; trav = trav->link){
            printf("%d ", trav->data);
        }
        printf("\n");
    }
}

int hash(int data){
    return data%MAX;
}

void insert(Dictionary A, int data){
    NodePointer trav;
    for(trav = A[hash(data)]; trav != NULL && trav->data != data; trav = trav->link){}
    if(trav==NULL){
        NodePointer temp = (NodePointer) malloc(sizeof(struct node));
        if(temp!=NULL){
            temp->data = data;
            temp->link = A[hash(data)];
            A[hash(data)] = temp;
        }
    }
}

void delete(Dictionary A, int data){
    NodePointer *trav, temp;
    for(trav = &A[hash(data)]; (*trav) != NULL && (*trav)->data != data; trav = &(*trav)->link){}
    if((*trav)!=NULL){
        temp = (*trav);
        (*trav) = temp->link;
        temp->link = NULL;
        free(temp);
    }
}

bool isMember(Dictionary A, int data){
    NodePointer trav;
    for(trav = A[hash(data)]; trav != NULL && trav->data != data; trav = trav->link){}
    return (trav!=NULL)? TRUE: FALSE;
}

void makeNull(Dictionary A){
    initDictionary(A);
}