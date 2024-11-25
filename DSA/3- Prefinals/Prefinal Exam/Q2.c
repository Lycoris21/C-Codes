/*

Given the definition of data type ListBST representing a list or a BST:

typedef struct{
    char name[30];
    char ID[10];
    char course[8];
    int yrLevel;
}studRec;

//Definition of List and BST
typedef struct node{
    studRec stud;
    struct node *prev; //NULL if node is used in the List
                       //Points to the Left child if node is used in BST
    struct node *next; //Points to the next node if used in the List
                       //Points to the Right child if node is used in BST
}*ListBST;

Write the code of the function convertBst2List(). The function will convert a given BST into a list sorted in ascending order to ID by continuously deleting the biggest remaining element in the BST until it is empty. BST is organized to the ID.

CONSTRAINTS:
    1 return statement only if necessary, no break/exit statement

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[30];
    char ID[10]; 
    //int ID;
    char course[8];
    int yrLevel;
}studRec;

//Definition of List and BST
typedef struct node{
    studRec stud;
    struct node *prev; //NULL if node is used in the List
                       //Points to the Left child if node is used in BST
    struct node *next; //Points to the next node if used in the List
                       //Points to the Right child if node is used in BST
}*ListBST;

void initBST(ListBST *);
void populateBST(ListBST *);
void insertBST(ListBST *, studRec);
void preorderBST(ListBST);
void convertBst2List(ListBST *);

int main(){
    ListBST bst;
    initBST(&bst);
    populateBST(&bst);
    preorderBST(bst);
    //convertBst2List(&bst);
    return 0;
}

void initBST(ListBST *B){
    (*B) = NULL;
}

void populateBST(ListBST *B){
    studRec arr[] = {
                    {"Kwesten", "21", "BSCS", 2},
                    {"Kwesten", "15", "BSCS", 2},
                    {"Kwesten", "32", "BSCS", 2},
                    {"Kwesten", "11", "BSCS", 2},
                    {"Kwesten", "18", "BSCS", 2},
                    {"Kwesten", "28", "BSCS", 2},
                    {"Kwesten", "39", "BSCS", 2},
                    {"Kwesten", "9", "BSCS", 2},
                    {"Kwesten", "13", "BSCS", 2},
                    {"Kwesten", "35", "BSCS", 2}
    };
    int x, size = sizeof(arr)/sizeof(arr[0]);
    for(x = 0; x < size; x++){
        insertBST(B, arr[x]);
    }
}

/* void populateBST(ListBST *B){
    studRec arr[] = {
                    {"Kwesten", 21, "BSCS", 2},
                    {"Kwesten", 15, "BSCS", 2},
                    {"Kwesten", 32, "BSCS", 2},
                    {"Kwesten", 11, "BSCS", 2},
                    {"Kwesten", 18, "BSCS", 2},
                    {"Kwesten", 28, "BSCS", 2},
                    {"Kwesten", 39, "BSCS", 2},
                    {"Kwesten", 9, "BSCS", 2},
                    {"Kwesten", 13, "BSCS", 2},
                    {"Kwesten", 35, "BSCS", 2}
    };
    int x, size = sizeof(arr)/sizeof(arr[0]);
    for(x = 0; x < size; x++){
        insertBST(B, arr[x]);
    }
} */

void insertBST(ListBST *B, studRec data){
    ListBST *trav = B;
    while((*trav) != NULL){
        //printf("Inserting ID: %s into BST\n", data.ID);
        // printf("%s: %d\n", data.ID, strcmp(data.ID, (*trav)->stud.ID));
        if(strcmp(data.ID, (*trav)->stud.ID) > 0){
            trav = &(*trav)->next;
        }else{
            trav = &(*trav)->prev;
        }
    }
    (*trav) = (ListBST) malloc(sizeof(struct node));
    strcpy((*trav)->stud.name, data.name);
    strcpy((*trav)->stud.ID, data.ID);
    strcpy((*trav)->stud.course, data.course);
    (*trav)->stud.yrLevel = data.yrLevel;
    (*trav)->prev = NULL;
    (*trav)->next = NULL;
}

/* void insertBST(ListBST *B, studRec data){
    ListBST *trav = B;
    while((*trav) != NULL){
        if(data.ID > (*trav)->stud.ID){
            trav = &(*trav)->next;
        }else{
            trav = &(*trav)->prev;
        }
    }
    (*trav) = (ListBST) malloc(sizeof(struct node));
    strcpy((*trav)->stud.name, data.name);
    (*trav)->stud.ID = data.ID;
    strcpy((*trav)->stud.course, data.course);
    (*trav)->stud.yrLevel = data.yrLevel;
    (*trav)->prev = NULL;
    (*trav)->next = NULL;
} */

void preorderBST(ListBST B){
    if(B != NULL){
        printf("ID: %s\n", B->stud.ID);
        preorderBST(B->prev);
        preorderBST(B->next);
    } 
}

/* void preorderBST(ListBST B){
    if(B != NULL){
        printf("ID: %d\n", B->stud.ID);
        preorderBST(B->prev);
        preorderBST(B->next);
    } 
} */

void convertBst2List(ListBST *B){
    ListBST *list = NULL, *temp = B;
    //insert first
    while (*temp) != NULL; 
}