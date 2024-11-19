#include <stdio.h>
#define MAX 10
#define ROOT -1
#define NOPE  -2

typedef int Tree[MAX];

void initTree(Tree *);
void insertTree(Tree *, int, int);
int getRoot(Tree);
void displayTree(Tree);
void preorder(Tree, int);
void inorder(Tree, int);
void postorder(Tree, int);


int main(){
    Tree T = {};
    initTree(&T);
    insertTree(&T, 5, ROOT); //inserting Root
    int root = getRoot(T);
    insertTree(&T, 0, 5);
    insertTree(&T, 1, 6);
    insertTree(&T, 2, 5);
    insertTree(&T, 3, 6);
    insertTree(&T, 4, 1);
    insertTree(&T, 6, 5);
    insertTree(&T, 7, 1);
    insertTree(&T, 8, 2);
    displayTree(T);
    printf("\nPREORDER\n");
    preorder(T, root);
    /* printf("\nINORDER\n");
    inorder(T, root);
    printf("\nPOSTORDER\n");
    postorder(T, root); */
    return 0;
}

void initTree(Tree *A){
    int x;
    for(x=0; x<MAX; x++){
        (*A)[x] = NOPE;
    }
}

void insertTree(Tree *A, int node, int parent){
    if((*A)[node]==NOPE){
        (*A)[node] = parent;
    } 
}

int getRoot(Tree A){
    int x = NOPE;
    for(x=0; x<MAX && A[x] != ROOT; x++){}
    return x;
}

void displayTree(Tree A){
    int x;
    for(x=0; x<MAX; x++){
        printf("%d  ", A[x]);
    }
}

//get parent = (child - 1) / 2
//get left child = parent * 2 + 1
//get right child = parent * 2 + 2

/* void preorder(Tree A, int root){
    if(root!=NOPE && root < MAX){
        printf("%d ", root);
        preorder(A,  );
        preorder(A, );
    }
}

void inorder(Tree A, int root){
    if(root!=NOPE && root < MAX){
        inorder(A, );
        int newRoot;
        for(newRoot=)
        printf("%d ", root);
        inorder(A, );
    }
}

void postorder(Tree A, int root){
    if(root!=NOPE && root < MAX){
        postorder(A, );
        postorder(A, );
        printf("%d ", root);
    }
} */