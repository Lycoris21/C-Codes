#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}Nodetype, *LIST;

typedef enum{FALSE, TRUE} bool;

void initList(LIST *); //initialize the list to be empty

void populateListSetUnsorted(LIST *); //populate the unsorted list without user input
void populateListSetSorted(LIST *); //populate the sorted list without user input
void populateListUser(LIST *); //user input population of the list
void getData(LIST *); //gets 1 user data input

void displayList(LIST); //displays the whole list 
void displayAtPos(LIST, int); //displays the data of a given position

void insertFirst(LIST *, int); //insert at first position
void insertLast(LIST *, int); //insert at last position
void insertAtPos(LIST *, int, int); //insert at a given position
void insertSorted(LIST *, int); //insert element at its proper position in a sorted list

void deleteFirst(LIST *); //delete at first position
void deleteLast(LIST *); //delete at last position
void deleteAtPos(LIST *, int); //delete at a given position
void deleteFirstOccur(LIST *, int); //delete the first occurence of a given element
void deleteAllOccur(LIST *, int); //delete all occurences of a given element
void deleteDuplicateSorted(LIST *); //delete all duplicate values in a sorted list
void deleteDuplicateUnsorted(LIST *); //delete all duplicate values in an unsorted list

int findElem(LIST, int); //returns the index of a given element
int findAverage(LIST); //returns the average value of the given list
int findMiddleElement(LIST); //returns the data at the middle position of a sorted list

bool isEqual(LIST, LIST); //returns true if two given lists are equal
bool isMember(LIST, int); //returns true if a given element is found in the list

void sortListSelection(LIST *); //sorts the list using selection sort
void sortListInsertion(LIST *); //sorts the list using insertion sort
void sortListBubble(LIST *); //sorts the list using bubble sort

int main(){
    LIST L, M;
    initList(&L);
    initList(&M);

    populateListSetUnsorted(&L);
    //populateListSetSorted(&M);
    //populateListUser(&L);

    //insertFirst(&L, 0);
    //insertLast(&L, 0);
    insertAtPos(&L, 0, 3);
    //insertSorted(&L, 23);
    
    //deleteFirst(&L);
    //deleteLast(&L);
    //deleteAtPos(&L, 3);
    //deleteFirstOccur(&L, 3);
    //deleteAllOccur(&L, 21);
    //deleteDuplicateSorted(&L);
    //deleteDuplicateUnsorted(&L);

    //findElem(L, 21);
    //printf("%d\n", findElem(L, 3));

    //findAverage(L);
    //printf("%d\n", findAverage(L));

    //findMiddleElement(L);
    //printf("%d\n", findMiddleElement(L));

    //isEqual(L, M);
    //printf("%s\n", (isEqual(L, M))? "TRUE" : "FALSE");

    //isMember(L, 21);
    //printf("%s\n", isMember(L, 21)? "TRUE" : "FALSE");

    //sortListSelection(&L);

    displayAtPos(L, 3);
    //displayAtPos(L, findElem(L, 21));
    displayList(L);
    displayList(M);
    return 0;
}

void initList(LIST *A){
    (*A) = NULL;
}

void populateListSetUnsorted(LIST *A){
    int arr[] = {8, 9, 21, 97, 21};
    int x;
    for(x=0; x < (sizeof(arr)/sizeof(arr[0])); x++){
        insertFirst(A, arr[x]);
    }
}

void populateListSetSorted(LIST *A){
    int arr[] = {8, 9, 21, 21, 97};
    int x;
    for(x=0; x < (sizeof(arr)/sizeof(arr[0])); x++){
        insertLast(A, arr[x]);
    }
}

void populateListUser(LIST *A){
    int x, y;
    printf("How many elements do you want to add?\n");
    scanf("%d", &x);
    for(y=0; y<x; y++){
        getData(A);
    }
}

void getData(LIST *A){
    int data;
    printf("Enter data:\n");
    scanf("%d", &data);
    insertLast(A, data);
}

void displayList(LIST A){
    LIST trav;
    printf("\n========================DATA=====================================\n");
    for(trav = A; trav != NULL; trav = trav->link){
        printf("%d\n", trav->data);
    }
}

void displayAtPos(LIST A, int pos){
    int x;
    LIST trav;
    for(trav = A, x=1; trav != NULL && x<pos; trav = trav->link, x++){}
    printf("%d\n", trav->data);
}

void insertFirst(LIST *A, int data){
    LIST temp = (LIST) malloc(sizeof(Nodetype));
    temp->data = data;
    temp->link = (*A);
    (*A) = temp;
}

void insertLast(LIST *A, int data){
    LIST *trav;
    for(trav = A; (*trav) != NULL; trav = &(*trav)->link){}
    (*trav) = (LIST) malloc(sizeof(Nodetype));
    (*trav)->data = data;
    (*trav)->link = NULL;
}

void insertAtPos(LIST *A, int data, int pos){
    int x;
    LIST *trav, temp;
    for(trav = A, x=1; (*trav) != NULL && x < pos; trav = &(*trav)->link , x++){}
    temp = (LIST) malloc(sizeof(Nodetype));
    temp->data = data;
    temp->link = (*trav);
    (*trav) = temp;
}

void insertSorted(LIST *A, int data){

}