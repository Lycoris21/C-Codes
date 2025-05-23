#include <stdio.h>
#include <stdlib.h>

#define MAX 5
#define SENTINEL 999

typedef int Vertex;
typedef int BitVector[MAX];
typedef int AdjMatrix[MAX][MAX];

typedef struct node{
    int distance[MAX];
    int Prev[MAX];
}dijkstra;

dijkstra Dijkstra(Vertex source, AdjMatrix matrix);
void displayDijkstra(dijkstra D);

int main(){
    AdjMatrix G = {
        { SENTINEL, 2, 4, SENTINEL, SENTINEL },
        { SENTINEL, SENTINEL, 1, 7, SENTINEL },
        { SENTINEL, SENTINEL, SENTINEL, SENTINEL, 3 },
        { SENTINEL, SENTINEL, SENTINEL, SENTINEL, SENTINEL },
        { SENTINEL, SENTINEL, SENTINEL, 2, SENTINEL }
    };

    dijkstra D = Dijkstra(0, G);
    displayDijkstra(D);
    return 0;
}

dijkstra Dijkstra(Vertex source, AdjMatrix matrix){
    dijkstra MST;
    BitVector visited = {0};
    for(int x = 0; x < MAX; x++){
        MST.distance[x] = SENTINEL;
    }

    for(int x = 0; x < MAX; x++){
        if(matrix[source][x] < SENTINEL){
            MST.distance[x] = matrix[source][x];
            MST.Prev[x] = source;
            visited[x] = 1;
        }
    }

    for(int x = 0; x < MAX; x++){
        if(visited[x] == 0){
            for(int y=0; y < MAX; y++){
                if(visited[y] == 1 && (matrix[y][x] + MST.distance[y] < MST.distance[x])){
                    MST.distance[x] = matrix[y][x] + MST.distance[y];
                    MST.Prev[x] = y;
                }
            }
            visited[x] = 1;
        }
    }

    return MST;
}

void displayDijkstra(dijkstra D) {
    printf("Vertex\tDistance\tPrevious\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d\t%d\t\t%d\n", i, D.distance[i], D.Prev[i]);
    }
}