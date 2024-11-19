#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char firstName[16];
    char lastName[24];
    unsigned int ID; // Used as comparison value
    // idfk im just making up fields now, the important bit is the ID in this struct
} StudRec;

typedef struct node {
    StudRec stud;
    struct node *prev; // Set to null if used as List
                            // Set to left child if used as tree
    struct node *next; // Set to right child if used as tree
} *BST;

void convertBst2List(BST *A);
void initBST(BST *);
void insert(BST *, char *, char *, unsigned int);
void display(BST);

int main(){
    BST L; 
    initBST(&L);
    insert(&L, "Kwesten", "Ann", 10);
    insert(&L, "Kwesten", "Ann", 5);
    insert(&L, "Kwesten", "Ann", 14);
    insert(&L, "Kwesten", "Ann", 7);
    insert(&L, "Kwesten", "Ann", 12);
    insert(&L, "Kwesten", "Ann", 18);
    insert(&L, "Kwesten", "Ann", 15);
    display(L);
    convertBst2List(&L);
    printf("\n");
    display(L);
    return 0;
}

void initBST(BST *A){
    *A = NULL;
}

void insert(BST *A, char *fname, char* lname, unsigned int ID){
    BST * trav = A;
    while(*trav != NULL){
        if((*trav)->stud.ID >= ID){
            trav = &(*trav)->prev;
        }else{
            trav = &(*trav)->next;
        }
    }
    *trav = (BST) malloc(sizeof(struct node));
    strcpy((*trav)->stud.firstName, fname);
    strcpy((*trav)->stud.lastName, lname);
    (*trav)->stud.ID = ID;
    (*trav)->prev = NULL;
    (*trav)->next = NULL;
}

void display(BST A){
    if(A != NULL){
        printf("%d ", A->stud.ID);
        display(A->prev);
        display(A->next);
    }
}

void convertBst2List(BST *A){
    if((*A)->prev != NULL){
        convertBst2List(&(*A)->prev);
    }else if((*A)->next != NULL){
        convertBst2List(&(*A)->next);
    }
    else{
        (*A)->next = *A;
        (*A) = NULL;
    }
}