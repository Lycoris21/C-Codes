#include <stdio.h> //this
#define MAX 10 //this
#define ROOT -1
#define NOPE  -2

typedef int Node; //this

typedef struct{
    Node parent;
    char label;
}PTnode; //this whole thing

typedef PTnode PTtree[MAX]; //this

void initTree(PTtree *);
void insertTree(PTtree *, int, int, char);
void displayTree(PTtree);
char getRightLabel(PTtree, Node parent); //this

int main(){
    PTtree T = {}; 
    initTree(&T);

    insertTree(&T, 5, ROOT, 'A'); //root
    int root = 5;
    insertTree(&T, 0, 5, 'B');
    insertTree(&T, 1, 6, 'F');
    insertTree(&T, 2, 5, 'D');
    insertTree(&T, 3, 6, 'E');
    insertTree(&T, 4, 1, 'H');
    insertTree(&T, 6, 5, 'C');
    insertTree(&T, 7, 1, 'I');  
    insertTree(&T, 8, 2, 'G');
    displayTree(T);

    printf("Rightmost Child Label: %c\n", getRightLabel(T, 5));
    return 0;
}

void initTree(PTtree *A){
   int x;
   for(x=0; x<MAX; x++){
        (*A)[x].parent = NOPE;
        (*A)[x].label = '\0';
   }
}

void insertTree(PTtree *A, int node, int parent, char label){
    if((*A)[node].parent==NOPE){
        (*A)[node].parent = parent;
        (*A)[node].label = label;
    } 
}

void displayTree(PTtree A){
    int x;
    for(x=0; x<MAX; x++){
        printf("Parent: %d ", A[x].parent);
        printf("Label: %c\n", A[x].label);
    }
}

char getRightLabel(PTtree A, Node parent){
    char temp = '\0';
    int x;
    for(x=0; x<MAX; x++){
        if(A[x].parent == parent){
            if(A[x].label > temp){
                temp = A[x].label;
            }
        }
    }
    return temp;
}
