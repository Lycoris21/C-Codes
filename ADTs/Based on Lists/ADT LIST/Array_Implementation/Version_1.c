/*****************************************************************************/
/*      Christine Ann Dejito                                                 */
/*      Version 1 of Array Implementation of ADT Lists                       */
/*****************************************************************************/

#include <stdio.h>
#define MAX 10

typedef struct node{
    int Elements[MAX];
    int count;
}LIST;

typedef enum {FALSE, TRUE} bool;

void initList(LIST *); //initialize the list to be empty

void populateListSetUnsorted(LIST *); //populate the unsorted list without user input
void populateListSetSorted(LIST *); //populate the sorted list without user input
void populateListUser(LIST *); //user input population of the list
void getData(int *); //gets 1 user data input

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
    populateListSetSorted(&M);
    //populateListUser(&L);

    //insertFirst(&L, 0);
    //insertLast(&L, 0);
    //insertAtPos(&L, 0, 3);
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

    sortListSelection(&L);

    //displayAtPos(L, findElem(L, 3));
    displayList(L);
    return 0;
}

void initList(LIST *A){
    A->count = 0;
}

void populateListSetUnsorted(LIST *A){
    A->Elements[0] = 21;
    A->Elements[1] = 97;
    A->Elements[2] = 21;
    A->Elements[3] = 9;
    A->Elements[4] = 8;
    A->count = 5;
}

void populateListSetSorted(LIST *A){
    A->Elements[0] = 8;
    A->Elements[1] = 9;
    A->Elements[2] = 21;
    A->Elements[3] = 21;
    A->Elements[4] = 97;
    A->count = 5;
}

void populateListUser(LIST *A){
    int x, y;
    printf("How many elements do you want to add?\n");
    scanf("%d", &x);
    if((A->count) + x <= MAX){
        for(y=0; y<x; y++){
            getData(&A->Elements[A->count++]);
        }
    }else{
        printf("There is not enough space for that number of data.\n");
    }
}

void getData(int *B){
    printf("Enter data:\n");
    scanf("%d", B);
}

void displayList(LIST A){
    int x;
    for(x=0; x < A.count; x++){
        printf("%d\n", A.Elements[x]);
    }
}

void displayAtPos(LIST A, int pos){
    if(pos>=0 && pos<A.count){
        printf("%d\n", A.Elements[pos]);
    }else{
        printf("Invalid position.\n");
    }

}

void insertFirst(LIST *A, int data){
    if(A->count<MAX){
        int x;
        for(x=(A->count)++; x>0; x--){
            A->Elements[x] = A->Elements[x-1];
        }
        A->Elements[0] = data;
    }
}

void insertLast(LIST *A, int data){
    if(A->count<MAX){
        A->Elements[A->count++] = data;
    }
}

void insertAtPos(LIST *A, int data, int pos){
    if(A->count<MAX){
        int x;
        for(x=(A->count)++; x>pos-1; x--){
            A->Elements[x] = A->Elements[x-1];
        }
        A->Elements[x] = data;
    }
}

void insertSorted(LIST *A, int data){
    if(A->count<MAX){
        int x;
        for(x=A->count-1; A->Elements[x] > data; x--){
            A->Elements[x+1] = A->Elements[x];
        }
        A->Elements[x+1] = data;
        A->count++;
    }
}

void deleteFirst(LIST *A){
    int x;
    for(x=0; x < A->count; x++){
        A->Elements[x] = A->Elements[x+1];
    }
    A->count--;
}

void deleteLast(LIST *A){
    A->count--;
}

void deleteAtPos(LIST *A, int pos){
    int x;
    for(x=pos-1; x < A->count; x++){
        A->Elements[x] = A->Elements[x+1];
    }
    A->count--;
}

void deleteFirstOccur(LIST *A, int data){
    int x;
    for(x=0; x<A->count && A->Elements[x]!=data; x++){}
    if(x!=A->count){
        for(; x < A->count; x++){
            A->Elements[x] = A->Elements[x+1];
        }
        A->count--;
    }
}

void deleteAllOccur(LIST *A, int data){
    int x, y;
    for(x=0; x<A->count;){
        if(A->Elements[x]==data){
            for(y=x; y < A->count; y++){
                A->Elements[y] = A->Elements[y+1];
            }
            A->count--;
        }else{
            x++;
        }
    }
}

void deleteDuplicateSorted(LIST *A){
    int x, y;
    for(x=0; x < A->count;){
        if(A->Elements[x]==A->Elements[x+1]){
            for(y=x; y < A->count; y++){
                A->Elements[y] = A->Elements[y+1];
            }
            A->count--;
        }else{
            x++;
        }
    }
}

void deleteDuplicateUnsorted(LIST *A){
    int x, y, z;
    for(x=0; x < A->count; x++){
        for(y=x+1; y < A->count;){
            if(A->Elements[x]==A->Elements[y]){
                for(z=y; z < A->count; z++){
                    A->Elements[z] = A->Elements[z+1];
                }
                A->count--;
            }else{
                y++;
            }
        }
    }
}

int findElem(LIST A, int data){
    int x;
    for(x=0; x < A.count && A.Elements[x] != data; x++){}
    return (x < A.count)? x : -1;
}

int findAverage(LIST A){
    int x, sum = 0;
    for(x=0; x < A.count; x++){
        sum += A.Elements[x];
    }
    return sum/x;
}

int findMiddleElement(LIST A){
    return A.Elements[A.count/2];
}

bool isEqual(LIST A, LIST B){
    int x;
    for(x=0; x<A.count && x<B.count && A.Elements[x] == B.Elements[x]; x++){}
    
    return (x==A.count && x==B.count)? TRUE : FALSE;
}

bool isMember(LIST A, int data){
    int x;
    for(x=0; x < A.count && A.Elements[x] != data; x++){}
    return (x == A.count) ? FALSE : TRUE;
}

void sortListSelection(LIST *A){
    int x, y, small, temp;
    for(x=0, small = A->Elements[x]; x<A->count-1; x++){
        for(y=x+1; y<A->count; y++){
            if(A->Elements[small]>A->Elements[y]){
                small = y;
            }
        }
        temp = A->Elements[x];
        A->Elements[x] = A->Elements[small];
        A->Elements[small] = temp;
    }
}