#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *next;
}*List;


void initListWithHeader(List *); //Look-Ahead Only DONE
void initListNoHeader(List *); // DONE

void insertLastWithHeader(List, int); //Look-Ahead Only DONE
//void insertLastNoHeaderPPN(); 
void insertLastNoHeaderLookAhead(List *, int); // DONE

//void deleteFirstOccurNoHeaderPPN(List *);
//void deleteFirstOccurNoHeaderLookAhead(List *);
void deleteFirstOccurWithHeaderLookAhead(List *);

void displayListNoHeader(List); 
void displayListWithHeader(List);


int main() {
    List X, Y;
    initListWithHeader(&X);
    initListNoHeader(&Y);
    insertLastWithHeader(X, 1);
    insertLastWithHeader(X, 2);
    insertLastWithHeader(X, 3);
    insertLastWithHeader(X, 4);
    insertLastWithHeader(X, 5);
    insertLastNoHeaderLookAhead(&Y , 6);
    insertLastNoHeaderLookAhead(&Y , 7);
    insertLastNoHeaderLookAhead(&Y , 8);
    insertLastNoHeaderLookAhead(&Y , 9);
    insertLastNoHeaderLookAhead(&Y , 10);
    
    displayListWithHeader(X);
    displayListNoHeader(Y);
    return 0;
}


//Initialize List with header
void initListWithHeader(List *L){
    (*L) = (List) malloc(sizeof (struct node));
    (*L)->next = NULL;
}


//Initialize List with no header
void initListNoHeader(List *L){
    (*L) = NULL;
}


//Look-ahead insert last with header
void insertLastWithHeader(List L, int elem){
    List *trav;
    for(trav = &L; (*trav)->next != NULL; trav = &(*trav)->next){}
    (*trav)->next = (List) malloc(sizeof(struct node));
    (*trav)->next->data = elem;
    (*trav)->next->next = NULL;
}


//Look-ahead insert last without header
void insertLastNoHeaderLookAhead(List *L , int elem){
    if(*L != NULL){
        List *trav;
        for(trav = L; (*trav)->next != NULL; trav = &(*trav)->next){}
        (*trav)->next = (List) malloc(sizeof(struct node));
        (*trav)->next->data = elem;
        (*trav)->next->next = NULL;
    }else{
        *L = (List) malloc(sizeof(struct node));
        (*L)->data = elem;
        (*L)->next = NULL;
    }
}


//Display List with header with PN
void displayListWithHeader(List L){
    printf("===========================================================\n");
    List trav;
    for(trav = L->next; trav != NULL; trav = trav->next){
        printf("%d\n", trav->data);
    }
}


//Display List no header with PN
void displayListNoHeader(List L){
    printf("===========================================================\n");
    List trav;
    for(trav = L; trav != NULL; trav = trav->next){
        printf("%d\n", trav->data);
    }
}


void deleteFirstOccurNoHeaderLookAhead(List *L){
    
}