#include <stdio.h>
#include <stdlib.h>

#define MAX (sizeof(unsigned int) * 8) //32 is the highest number of elements that can be stored: powers 0-31

typedef unsigned int Set; //32 bits

typedef enum{FALSE, TRUE} bool;

void init(Set *);
void setSetValue(Set *, int[], int);
void displayBitPattern(Set);
void insertElem(Set *, int);
void deleteElem(Set *, int);
bool isMember(Set, int);
void displayElems(Set);

int main() {
    int SetMembers[] = {1,3,5,7,9};
    int size = 5;
    Set S;
    init(&S);
    setSetValue(&S, SetMembers, size);

    /* printf("The current members of the Set are: [ ");
    for(int x=0; x < (sizeof(SetMembers) / sizeof(SetMembers[0])); x++){
        printf("%d ", SetMembers[x]);
    }
    printf("]\n"); */

    //display elems here
    displayElems(S);
    displayBitPattern(S);
    
    insertElem(&S, 21);
    printf("After inserting 21, the ");
    displayBitPattern(S);

    insertElem(&S, 32);
    displayBitPattern(S);

    deleteElem(&S, 5);
    printf("After deleting 5, the ");
    displayBitPattern(S);

    deleteElem(&S, 32);
    displayBitPattern(S);

    printf("\nisMember 24: %s\n\n", isMember(S, 24)? "TRUE": "FALSE");

    printf("\nisMember 7: %s\n\n", isMember(S, 7)? "TRUE": "FALSE");


    return 0;
}

void init(Set *A) {
    *A = 0;
}

void setSetValue(Set *A, int B[], int size){
    int x;
    for(x=0; x<size; x++){
        if(B[x] < MAX){
            //(*A) += 1 << B[x]; //this works yes but let's do bitwise or
            (*A) = (*A) | 1 << B[x];
        }else{
            printf("The element %d exceeds the max element that can be stored.\n\n", B[x]);
        }

    }
    
}

void displayBitPattern(Set A) {
    Set mask;
    printf("BIT PATTERN OF SET A\n");
    for (mask = 1 << (MAX-1); mask > 0; mask = mask >> 1) {
        printf("%d", ((A & mask)? 1:0));
        if(mask%10==6){
            printf(" ");
        }
    }
    printf("\n\n");
}

void insertElem(Set *A, int data){
    //(*A) += 1 << data; //this works yes but let's do bitwise or
    if(data < MAX){
        (*A) = (*A) | (1 << data);
    }else{
        printf("The element %d exceeds the max element that can be stored.\n");
    }
}

void deleteElem(Set *A, int data){
    if(data < MAX && data > -1){
        (*A) = (*A) ^ (1 << data);
    }else{
        printf("The element %d is not a member of the elements stored.\n");
    }
}

bool isMember(Set A, int data){
    printf("Mask of isMember: %d", A & 1<<data);
    return A & 1<<data;
}

void displayElems(Set A){
    int mask = 1;
    printf("The current members of the Set are: [ ");

    int x;
    for(x=0; x<MAX; x++){
        if((A & 1<<x) > 0){
            printf("%d ", x);
        }
    } 
    printf("]\n");   
}

/* my own idea/logic but it doesnt work haha ill try to make it work soon... someday...
    void displayElems(Set A) {
    Set mask = 1;

    printf("The current members of the Set are: [ ");

    while (mask < (1 << MAX-1)) {
        if ((A & mask) > 0) {
            printf("%d ", A & mask);
        }
        mask = mask << 1;
    }
    printf("]\n");
} */