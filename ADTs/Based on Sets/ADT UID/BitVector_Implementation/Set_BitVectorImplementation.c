#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int Set[MAX];

void insertToSet(Set *S, int data);
void deleteFromSet(Set *S, int data);
void populateSet(Set *S);
void printSet(Set S);
Set *Union(Set A, Set B);
Set *Intersection(Set A, Set B);
Set *Difference(Set A, Set B);

int main(){
    Set A = {};
    Set B = {};
    populateSet(&A);
    populateSet(&B);

    

    return 0;
}

void insertToSet(Set *S, int data){
    (*S)[data] = 1;
}

void deleteFromSet(Set *S, int data){
    (*S)[data] = 0;
}

void populateSet(Set *S){
    (*S)[0] = 1;
    (*S)[1] = 1;
    (*S)[2] = 1;
    (*S)[3] = 0;
    (*S)[4] = 0;
    (*S)[5] = 1;
    (*S)[6] = 0;
    (*S)[7] = 1;
    (*S)[8] = 0;
    (*S)[9] = 1;
}

void printSet(Set S){
    int x;
    printf("==========================SET MEMBERS===============================\n");
    for(x=0; x<MAX; x++){
        if(S[x]==1){
            printf("%d\n", x);
        }
    }
}

Set *Union(Set A, Set B){
    Set *C = (Set *) malloc(sizeof(Set));
    int x;
    for(x=0; x<MAX; x++){
        if(A[x]==1 || B[x]==1){
            (*C)[x] = 1;
        }else{
            (*C)[x] = 0;
        }
    }
    return C;
}

Set *Intersection(Set A, Set B){
    Set *C = (Set *) malloc(sizeof(Set));
    int x;
    for(x=0; x<MAX; x++){
        if(A[x]==1 && B[x]==1){
            (*C)[x] = 1;
        }else{
            (*C)[x] = 0;
        }
    }
    return C;
}

Set *Difference(Set A, Set B){
    Set *C = (Set *) malloc(sizeof(Set));
    int x;
    for(x=0; x<MAX; x++){
        if(A[x]==1 && B[x]==0){
            (*C)[x] = 1;
        }else{
            (*C)[x] = 0;
        }
    }
    return C;
}