#include <stdio.h>
#define MAX_VERTEX 8
#define SENTINEL INT_MAX

typedef char vertexType; //vertices are characters A B C D E F G H
typedef int labelType; //labels/weight for the edges

typedef struct{
    vertexType tail; //the tail of the arc
    vertexType head; //head of the arc
    labelType mLabel; //or weight
}edgeType; //edges for adjacency matrix

typedef struct{
    vertexType adj; 
    labelType lLabel;
}adjType; //edges for adjacency list

typedef struct node{
    adjType info;
    struct node * link;
}*nodePtrType; //nodes for adjacency list

typedef struct{
    nodePtrType List[MAX_VERTEX]; //array of node pointers for adjacency list
    int edgeCount; //number of edges
}directedAdjList; 

typedef struct{
    labelType matrix[MAX_VERTEX][MAX_VERTEX]; //2d array for matrix
    int edgeCount; //number of edges
}directedAdjMatrix;

void initMatrix(directedAdjMatrix *);
void populateMatrix(directedAdjMatrix *);
void display(directedAdjMatrix);

int main(){
    directedAdjMatrix M;
    initMatrix(&M);
    populateMatrix(&M);
    display(M);
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

void populateMatrix(directedAdjMatrix *A){ //unweighted graph 1 for exist
    edgeType Edges[MAX_VERTEX * MAX_VERTEX] = {{'A', 'B', 1},
                                  {'A', 'H', 1},
                                  {'B', 'F', 1},
                                  {'C', 'A', 1},
                                  {'D', 'H', 1},
                                  {'D', 'E', 1},
                                  {'E', 'B', 1},
                                  {'E', 'H', 1},
                                  {'F', 'C', 1},
                                  {'G', 'A', 1},
                                  {'G', 'C', 1},
                                  {'G', 'F', 1}
    };

    //A=0 B=1 C=2 D=3 E=4 F=5 G=6 H=7
    int x, size = sizeof(Edges)/sizeof(Edges[0]);
    for(x = 0; x<size; x++){
        A->matrix[(Edges[x].tail - 'A')][(Edges[x].head - 'A')] = Edges[x].mLabel;
    }
    //I give up figure this out later HAHA 
    //I FIGURED IT OUT SHEESH

    /* A->matrix['A'-'A']['B'-'A'] = 1;
    A->matrix[0][7] = 1;
    A->matrix[1][5] = 1;
    A->matrix[2][0] = 1;
    A->matrix[3][7] = 1;
    A->matrix[3][4] = 1;
    A->matrix[4][7] = 1;
    A->matrix[5][2] = 1;
    A->matrix[6][2] = 1;
    A->matrix[6][5] = 1;
    A->edgeCount = 10; */
}

void display(directedAdjMatrix A){
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