#include <stdio.h>
#define MAX 10

typedef int maxHeap[MAX]; // maxHeap[0] stores the last index

int deleteMaxHeap(int *maxHeap);

int main(){

    maxHeap mh = {5, 1, 8, 2, 9, 1, 7, 2, 3};
    
    return 0;
}