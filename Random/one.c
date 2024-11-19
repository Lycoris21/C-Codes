#include <stdio.h>
#define MAX 10
#define ROOT -1
#define NOPE  -2

typedef int Node;

typedef struct{
    Node parent;
    char label;
}PTnode;

typedef PTnode PTtree[MAX];

void initTree(PTtree *);
void insertTree(PTtree *, int, int, char);
void displayTree(PTtree);
char getRightLabel(PTnode *, Node parent);

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

    //printf("Label: %c\n", getRightLabel());
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

char getRightLabel(PTnode *, Node parent){

}
