#include <stdio.h>
#define MAX 15

typedef struct{
    int Elem[MAX];
    int last_ndx;
}MinHeap;

void initMinHeap(MinHeap *);
void insert(MinHeap *, int);
int deleteMin(MinHeap *);
void minHeapifySubtree(MinHeap *, int);
void minHeapifyAll(MinHeap *);
void heapSortDesc(MinHeap *);
void display(MinHeap);

int main(){
    MinHeap H;
    initMinHeap(&H);
    insert(&H, 21);
    insert(&H, 4);
    insert(&H, 7);
    insert(&H, 2);
    insert(&H, 9);
    insert(&H, 3);

    printf("=====MinHeap=====\n");
    minHeapifyAll(&H);
    display(H);

    printf("\n\n=====After deleteMin()=====\n");
    printf("root: %d\n", deleteMin(&H));
    display(H);

    printf("\n\n=====Heapsort Descending=====\n");
    heapSortDesc(&H);
    display(H);
    return 0;
}

void initMinHeap(MinHeap *A){
    A->last_ndx = -1;
}

/*
Steps for insertion:
    1. check if there is still space
    2. if there is, insert the element at the end 
    3. while child is smaller than parent, swap both child and parent (sift up)
*/
void insert(MinHeap *A, int elem){
    if(A->last_ndx+1 < MAX){
        A->last_ndx++;
        A->Elem[A->last_ndx] = elem;
        /* 
        int child = A->last_ndx;
        int parent = (child - 1) / 2;

        while(parent >= 0 && A->Elem[parent] > A->Elem[child]){
            int temp = A->Elem[parent];
            A->Elem[parent] = A->Elem[child];
            A->Elem[child] = temp;
            child = parent;
            parent = (child - 1) / 2;
        } */

    } else {
        printf("MinHeap is full. Cannot insert more elements.\n");
    }
}

/*
Steps for deletion:
    1. swap root(min) and the lowest level rightmost element(basically end of heap)
    2. delete min element(now at the lowest level rightmost element) (last_ndx--)
    3. heapify the tree (sift down the now root element till it is in its proper place)
        a. get the smaller child 
        b. swap the displaced element with the small child
        c. repeat till every element are in their proper place
    4. return min
*/
int deleteMin(MinHeap *A){
    int min = -1;
    if(A->last_ndx >= 0){
        min = A->Elem[0];
        A->Elem[0] = A->Elem[A->last_ndx];
        A->Elem[A->last_ndx--] = min;
        minHeapifySubtree(A, 0);
    }
    return min;
}

void minHeapifySubtree(MinHeap *A, int root){
    int parent = root;
    int LC = parent * 2 + 1;
    int small = (LC+1 <= A->last_ndx && A->Elem[LC+1] < A->Elem[LC]) ? LC+1 : LC;
    while(small <= A->last_ndx && A->Elem[parent] > A->Elem[small]){
        int temp = A->Elem[parent];
        A->Elem[parent] = A->Elem[small];
        A->Elem[small] = temp;
        parent = small;
        LC = parent * 2 + 1;
        small = (LC+1 <= A->last_ndx && A->Elem[LC+1] < A->Elem[LC]) ? LC+1 : LC;     
    }
}

void minHeapifyAll(MinHeap *A){
    int parent = (A->last_ndx - 1) / 2;
    while(parent >=0){
        minHeapifySubtree(A, parent);
        parent--;
    }
}

void display(MinHeap A){
    int x;
    for(x=0; x<=A.last_ndx; x++){
        printf("%d - ", A.Elem[x]);
    }
}

void heapSortDesc(MinHeap *A){
    int index = A->last_ndx;
    while(A->last_ndx >= 0){
        deleteMin(A);  
    }
    A->last_ndx = index;
}