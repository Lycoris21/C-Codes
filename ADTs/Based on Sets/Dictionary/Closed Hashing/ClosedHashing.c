#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define EMPTY '?'
#define DELETED '#'

typedef char Dictionary[SIZE];
typedef enum{FALSE, TRUE} bool;

void initDictionary(Dictionary);
void displayDictionary(Dictionary);
int hash(char);
void insert(Dictionary, char);
void delete(Dictionary, char);
bool isMember(Dictionary, char);
bool isFull(Dictionary);

int main(){
    Dictionary D;
    initDictionary(D);

    insert(D, 'a');
    insert(D, 'C');
    insert(D, 'A');
    insert(D, 'd');
    insert(D, 'Z');
    insert(D, 'p');
    insert(D, 'i');
    //insert(D, 'I');
    insert(D, 'J');
    insert(D, 'W');
    displayDictionary(D);

    printf("\n%s\n", isMember(D, 'h')? "TRUE": "FALSE");

    delete(D, 'a');
    delete(D, 'C');
    displayDictionary(D);

    printf("\n%s\n", isMember(D, 'h')? "TRUE": "FALSE");
    printf("\n%s\n", isMember(D, 'J')? "TRUE": "FALSE");

    printf("\n%s\n", isFull(D)? "FULL": "NOT FULL");
    return 0;
}

void initDictionary(Dictionary A){
    int x;
    for(x=0; x<SIZE; x++){
        A[x] = EMPTY;
    }
}

void displayDictionary(Dictionary A){
    int x;
    printf("\nMembers of the set are:\n");
    for(x=0; x<SIZE; x++){
        printf("ROW %d: ", x);
        if(A[x]!=EMPTY && A[x]!=DELETED){
            printf("%c\n", A[x]);
        }else{
            printf("%s\n", (A[x]!=DELETED)? "EMPTY": "DELETED");
        }
    }
}

int hash(char data){
    return data % SIZE;
}

void insert(Dictionary A, char data){
    if(isMember(A, data)!=TRUE){
        int x;
        for(x=hash(data); A[x]!=EMPTY && A[x]!=DELETED; x =  x + 1 % SIZE){}
        A[x] = data;
    }
}

void delete(Dictionary A, char data){
    if(isMember(A, data)!=FALSE){
        int x;
        for(x=hash(data); A[x]!=data && A[x]!=EMPTY; x = x + 1 % SIZE){}
        A[x] = DELETED;
    }
}

bool isMember(Dictionary A, char data){
    int x;
    for(x=hash(data); A[x]!=data && A[x]!=EMPTY && x!=(((hash(data)+SIZE)-1)%SIZE); x = (x + 1) % SIZE){}
    return (A[x]==data)? TRUE: FALSE;
}

bool isFull(Dictionary A){
    int x;
    for(x=0; x<SIZE && A[x]!=EMPTY; x++){}
    return (x<SIZE)? FALSE: TRUE;
}

