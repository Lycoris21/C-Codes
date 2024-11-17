#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node{
    int set[MAX];
    int size;
}Set;

void insertToSet(Set *S, int data);
void deleteFromSet(Set *S, int data);
void populateSet(Set *S);
void printSet(Set S);
Set Union(Set A, Set B);
Set Intersection(Set A, Set B);
Set Difference(Set A, Set B);

int main(){

    return 0;
}

void insertToSet(Set *S, int data){
    
}

void deleteFromSet(Set *S, int data){
    
}