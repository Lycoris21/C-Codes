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

void convertBst2List(BST, BST *, BST *);
//void convertBst2List(BST *);
void initBST(BST *);
void insert(BST *, char *, char *, unsigned int);
void preorder(BST);
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
    preorder(L);
    BST prev = NULL;
    convertBst2List(L, &prev, &prev);
    //convertBst2List(&L);
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

void preorder(BST A){
    if(A != NULL){
        printf("%d ", A->stud.ID);
        preorder(A->prev);
        preorder(A->next);
    }
}

void display(BST A){
    BST trav;
    for(trav = A; trav != NULL; trav = trav->next){
        printf("%d ", trav->stud.ID);
    }
}

/* Convert the BST to a doubly linked list in place */
void convertBst2List(BST t, BST *prev, BST *head) {
    if (t != NULL) {
        // Recurse on the left subtree
        convertBst2List(t->prev, prev, head);

        // Adjust the pointers to form the doubly linked list
        if (*prev != NULL) {
            (*prev)->next = t;   // Link previous node to current node
            t->prev = *prev;     // Link current node to previous node
        } else {
            // If this is the first node, it becomes the head of the list
            *head = t;
        }
        *prev = t;  // Update previous node to current node

        // Recurse on the right subtree
        convertBst2List(t->next, prev, head);
    }
}

/* void convertBst2List(BST *A, BST *prev){
    if((*A) != NULL){
        convertBst2List(&(*A)->prev, prev);
        prev = *A;
        convertBst2List(&(*A)->next, prev);
        (*A)->next = prev;
    }
}
 */
/* void convertBst2List(BST *root, BST *prev) {
    if (*root == NULL) return;

    // Recursively traverse the left subtree
    convertBst2List(&(*root)->prev, prev);

    // Process the current node
    (*root)->prev = *prev; // Nullify the left child
    if (*prev != NULL) {
        (*prev)->next = *root; // Link previous node to current node
    }
    *prev = *root; // Update previous node to the current one

    // Recursively traverse the right subtree
    convertBst2List(&(*root)->next, prev);
} */