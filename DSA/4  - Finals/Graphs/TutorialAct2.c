/* 

This is about dijktra's shortest path algorithm
using adjacency matrix

*/

#include <stdio.h>
#define MAX_VERTEX 8
#define SENTINEL INT_MAX

typedef char vertexType; //vertices are characters A B C D E F G H
typedef int labelType; //labels/weight for the edges
typedef enum{FALSE, TRUE} bool;

typedef struct{
    vertexType tail; //the tail of the arc
    vertexType head; //head of the arc
    labelType mLabel; //or weight
}edgeType;

typedef struct{
    labelType matrix[MAX_VERTEX][MAX_VERTEX]; //2d array for matrix
    int edgeCount; //number of edges
}directedAdjMatrix;

void initMatrix(directedAdjMatrix *);
void initVisited(bool**);
void initSPRecord(int*);
void populateMatrix(directedAdjMatrix *);
void displayMatrix(directedAdjMatrix);

int main(){
    directedAdjMatrix M;
    initMatrix(&M);
    populateMatrix(&M);
    displayMatrix(M);
    bool visitedArr[MAX_VERTEX];
    initVisited(&visitedArr);
    int SPRecord[MAX_VERTEX];
    //initSPRecord(&SPRecord);

    return 0;
}

void initMatrix(directedAdjMatrix *A){
    A->edgeCount = 0;
    int x, y;
    for(x=0; x<MAX_VERTEX; x++){
        for(y=0; y<MAX_VERTEX; y++){
            A->matrix[x][y] = 0;
        }
    }
}

void initVisited(bool **visited){
    int x;
    for(x=0; x<MAX_VERTEX; x++){
        (*visited)[x] = FALSE;
    }
}
void initSPRecord(int*);

void populateMatrix(directedAdjMatrix *A){ //unweighted graph 1 for exist
    edgeType Edges[MAX_VERTEX * MAX_VERTEX] = {
                                {'A', 'B', 4},
                                {'A', 'H', 8},
                                {'B', 'C', 8},
                                {'B', 'H', 11},
                                {'C', 'D', 7},
                                {'C', 'F', 4},
                                {'C', 'I', 2},
                                {'D', 'E', 9},
                                {'D', 'F', 14},
                                {'E', 'F', 10},
                                {'F', 'G', 2},
                                {'G', 'I', 6},
                                {'G', 'H', 1},
    };

    //A=0 B=1 C=2 D=3 E=4 F=5 G=6 H=7
    int x, size = sizeof(Edges)/sizeof(Edges[0]);
    for(x = 0; x<size; x++){
        A->matrix[(Edges[x].tail - 'A')][(Edges[x].head - 'A')] = Edges[x].mLabel;
        A->matrix[(Edges[x].head - 'A')][(Edges[x].tail - 'A')] = Edges[x].mLabel;
    }
}

void displayMatrix(directedAdjMatrix A){
    int x, y, vertex;
    printf("ADJACENCY MATRIX\n  ");
    for(y=0, vertex = 65; y<MAX_VERTEX; y++){
        printf("%c ", vertex++);
    }
    printf("\n");
    for(x=0, vertex = 65; x<MAX_VERTEX; x++){
        printf("%c ", vertex++);
        for(y=0; y<MAX_VERTEX; y++){
            printf("%d ", A.matrix[x][y]);
        }
        printf("\n");
    }
}