#include <stdio.h>
#define MAX 15

typedef struct{
    int Elem[MAX];
    int last_ndx;
}Heap;

void initHeap(Heap *);
void insert(Heap *, int elem);
int deleteMin(Heap *);
void display(Heap);

int main(){
    Heap H;
    initHeap(&H);
    insert(&H, 21);
    insert(&H, 4);
    insert(&H, 7);
    insert(&H, 2);
    insert(&H, 9);
    insert(&H, 3);
    display(H);

    int root = deleteMin(&H);
    printf("\nroot: %d\n", root);

    display(H);
    return 0;
}

void initHeap(Heap *A){
    A->last_ndx = -1;
}

void insert(Heap *A, int elem){
    if(A->last_ndx+1 < MAX){
        A->last_ndx++;
        A->Elem[A->last_ndx] = elem;
        int child = A->last_ndx;
        int parent = (child - 1) / 2;

        while(parent >= 0 && A->Elem[parent] > A->Elem[child]){
            int temp = A->Elem[parent];
            A->Elem[parent] = A->Elem[child];
            A->Elem[child] = temp;
            child = parent;
            parent = (child - 1) / 2;
        }
    } else {
        printf("Heap is full. Cannot insert more elements.\n");
    }
}

int deleteMin(Heap *A){
    int min = -1;
    if(A->last_ndx != -1){
        min = A->Elem[0];
        A->Elem[0] = A->Elem[A->last_ndx];
        A->last_ndx--;

        int parent = 0;
        int LC = parent * 2 + 1;
        int small = (A->Elem[LC] < A->Elem[LC+1])? LC : LC+1;

        while(parent < A->last_ndx/2 && A->Elem[parent] > A->Elem[small]){
            int temp = A->Elem[parent];
            A->Elem[parent] = A->Elem[small];
            A->Elem[small] = temp;
            parent = small;
            LC = parent * 2 + 1;
            small = (A->Elem[LC] < A->Elem[LC+1])? LC : LC+1;           
        }
    }
}

void display(Heap A){
    int x;
    for(x=0; x<=A.last_ndx; x++){
        printf("%d - ", A.Elem[x]);
    }
}