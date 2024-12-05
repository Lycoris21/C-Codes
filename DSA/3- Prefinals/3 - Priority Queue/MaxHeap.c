#include <stdio.h>
#define MAX 15

typedef struct{
    int Elem[MAX];
    int last_ndx;
}MaxHeap;

void initMaxHeap(MaxHeap *);
void insert(MaxHeap *, int);
int deleteMax(MaxHeap *);
void maxHeapifySubtree(MaxHeap *, int);
void maxHeapifyAll(MaxHeap *);
void display(MaxHeap);

int main(){
    MaxHeap H;
    initMaxHeap(&H);
    insert(&H, 21);
    insert(&H, 4);
    insert(&H, 7);
    insert(&H, 2);
    insert(&H, 9);
    insert(&H, 3);
    printf("=====MaxHeap=====\n");
    maxHeapifyAll(&H);
    display(H);
    
    printf("\n\n=====After deleteMax()=====\n");
    printf("root: %d\n", deleteMax(&H));
    display(H);
    return 0;
}

void initMaxHeap(MaxHeap *A){
    A->last_ndx = -1;
}

/*
Steps for insertion:
    1. check if there is still space
    2. if there is, insert the element at the end 
    3. while child is greater than parent, swap both child and parent (sift up)
*/
void insert(MaxHeap *A, int elem){
    if(A->last_ndx+1 < MAX){
        A->Elem[++A->last_ndx] = elem; 
        /* 
        int child = A->last_ndx;
        int parent = (child - 1) / 2;

        while(parent >= 0 && A->Elem[child] > A->Elem[parent]){
            int temp = A->Elem[child];
            A->Elem[child] = A->Elem[parent];
            A->Elem[parent] = temp;
        } */
    }else{
        printf("Heap is full.\n");
    }
}

/*
Steps for deletion:
    1. swap root(max) and the lowest level rightmost element(basically end of heap)
    2. delete max element(now at the lowest level rightmost element) (last_ndx--)
    3. heapify the tree (sift down the now root element till it is in its proper place)
        a. get the bigger child 
        b. swap the displaced element with the bigger child
        c. repeat till every element are in their proper place
    4. return max
*/
int deleteMax(MaxHeap *A){
    int max = -1;
    if(A->last_ndx >=0){
        max= A->Elem[0];
        A->Elem[0] = A->Elem[A->last_ndx--];
        maxHeapifySubtree(A, 0);
    }
    return max;
}

void maxHeapifySubtree(MaxHeap *A, int root){
    int parent = root;
    int LC = parent * 2 + 1;
    int big = (LC+1 <= A->last_ndx && A->Elem[LC+1] > A->Elem[LC]) ? LC+1 : LC;
    while(big <= A->last_ndx && A->Elem[parent] < A->Elem[big]){
        int temp = A->Elem[parent];
        A->Elem[parent] = A->Elem[big];
        A->Elem[big] = temp;
        parent = big;
        LC = parent * 2 + 1;
        big = (LC+1 <= A->last_ndx && A->Elem[LC+1] > A->Elem[LC]) ? LC+1 : LC;     
    }
}

void maxHeapifyAll(MaxHeap *A){
    int parent = (A->last_ndx - 1) / 2;
    while(parent >=0){
        maxHeapifySubtree(A, parent);
        parent--;
    }
}

void display(MaxHeap A){
    int x;
    for(x=0; x <= A.last_ndx; x++){
        printf("%d - ", A.Elem[x]);
    }
}