#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    int priority;
    char traffic[60];
    int time; //in seconds
}Traffic;

Traffic enqueue(int, char[], int);
//now I need dequeue
//also peek but not really
//I also need heapify
//i also need swap to swap shit huhu
//I shall do a min-heap



int main(){

    Traffic scenario[5];
    int totalTime = 0;

    scenario[0] = enqueue(5, "Turn Right from Main Lane", 20);
    scenario[1] = enqueue(8, "Pedestrian on Diversion Lane", 25);
    scenario[2] = enqueue(1, "Main Lane", 40);
    scenario[3] = enqueue(7, "Pedestrian on Main Lane", 30);
    scenario[4] = enqueue(2, "Diversion Lane", 35);

    

    return 0;
}

Traffic enqueue(int prior, char traff[], int time){
    Traffic q;
    q.priority = prior;
    strcpy(q.traffic, traff);
    q.time = time;
    return q;
}

