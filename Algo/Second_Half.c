#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INF INT_MAX

typedef struct node{
    int num;
    struct node* next;
}*List;

void minHeapifySubtree(int [], int, int);
void maxHeapifySubtree(int [], int, int);
void minHeapifyAll(int [], int);
void maxHeapifyAll(int [], int);

void quickSort(int [], int, int);
int lomutoPartition(int [], int, int);
int hoarePartition(int [], int, int);

void countingSort(int [], int);

void displayArr(int [], int);
void displayLL(List);
List arrToLL(int [], int);



int main(){
    int arr[] = {9, 4, 10, 3, 15, 7, 20, 17, 2, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    List L = arrToLL(arr, size);
    
    //quickSort(arr, 0, size-1);
    //printf("Quick Sort\n");
    
    //countingSort(arr, size);
    //printf("Counting Sort\n");
    
    //minHeapifySubtree(arr, size, 0);
    //minHeapifyAll(arr, size);
    //printf("Min Heapify\n");
    
    maxHeapifySubtree(arr, size, 0);
    //maxHeapifyAll(arr, size);
    printf("Max Heapify\n");
    
    displayArr(arr, size);
    printf("\n\n");
    
    //printf("Array\n");
    //displayArr(arr, size);
    //List L = arrToLL(arr, size);
    //printf("\n\nLinked List\n");
    //displayLL(L);
    return 0;
}

void minHeapifySubtree(int arr[], int size, int root){
    int parent = (size-1)/2;
    int LC = (parent*2)+1;
    int RC = (LC+1 < size)? LC+1 : LC;
    int smaller;
    
    while(parent>=0 && LC < size){
        smaller = (arr[LC] <= arr[RC]) ? LC : RC;
        if(arr[smaller] < arr[parent]){
            int temp = arr[smaller];
            arr[smaller] = arr[parent];
            arr[parent] = temp;
        }
        parent--;
        LC = (parent*2)+1;
        RC = (LC+1 < size)? LC+1 : LC;
        
    }
}

void maxHeapifySubtree(int arr[], int size, int root){
    int parent = root;
    int LC = (parent*2)+1;
    int RC = (LC+1 < size)? LC+1 : LC;
    int big;
    while(parent < size && LC < size){
        big = (arr[LC] >= arr[RC]) ? LC : RC;
            int temp = arr[big];
            arr[big] = arr[parent];
            arr[parent] = temp;
        parent = big;
        LC = (parent*2)+1;
        RC = (LC+1 < size)? LC+1 : LC;
    }
}

void minHeapifyAll(int arr[], int size){
    int x;
    for(x = size/2; x>=0; x--){
        minHeapifySubtree(arr, size, x);
    }
}

void maxHeapifyAll(int arr[], int size){
    int x;
    for(x = size/2; x>=0; x--){
        maxHeapifySubtree(arr, size, x);
    }
}

void heapSort(int arr[], int size){
    //maxHeapifyAll
    //deleteAll
    //set size into original size
}

void quickSort(int arr[], int start, int end){
    if(start<end){
        //int p = lomutoPartition(arr, start, end);
        //QuickSort(arr, start, p-1);
        int p = hoarePartition(arr, start, end);
        quickSort(arr, start, p);
        quickSort(arr, p+1, end);
    }
}

int lomutoPartition(int arr[], int start, int end){
    int x = start, y = start-1, pivot = arr[end];
    while(x<=end){
        if(arr[x]<=pivot){
            int temp = arr[++y];
            arr[y] = arr[x];
            arr[x] = temp;
        }
        x++;
    }
    return y;
}

int hoarePartition(int arr[], int start, int end){
    int x = start-1, y = end+1, pivot = arr[start];
    while(x<y){
        do{
            x++;
        }while(arr[x]<pivot);
        do{
            y--;
        }while(arr[y]>pivot);
        if(x<y){
            int temp = arr[x];
            arr[x] = arr[y];
            arr[y] = temp;
        }
    }
    return y;
}

void countingSort(int arr[], int size){
    if(size > 0){
        int x, max = 0;
        for(x=0; x<size; x++){
            if(arr[x] > max){
                max = arr[x];
            }
        }
        
        int countArr[++max];
        for(x=0; x<max; x++){
            countArr[x] = 0;
        }
        for(x=0; x<size; x++){
            countArr[arr[x]]++;
        }
        for(x=1; x<size; x++){
            countArr[x] += countArr[x-1];
        }
        
        int outputArr[size];
        for(x=size-1; x>=0; x--){
            outputArr[--countArr[arr[x]]] = arr[x];
        }
        
        memcpy(arr, outputArr, size*sizeof(int));
    }
    
}

void displayArr(int arr[], int size){
    int i;
    for(i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
}

void displayLL(List L){
    List trav;
    for(trav = L; trav != NULL; trav = trav->next){
        printf("%d ", trav->num);
    }
}

List arrToLL(int arr[], int size){
    int i;
    List L = NULL, temp;
    for(i=size-1; i>=0; i--){
        temp = (List) malloc(sizeof(struct node));
        temp->num = arr[i];
        temp->next = L;
        L = temp;
    }
    return L;
}
