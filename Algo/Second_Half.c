#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct node{
    int num;
    struct node* next;
}*List;

void lomutoQuickSort(int [], int, int);
int lomutoPartition(int [], int, int);

void displayArr(int [], int);
void displayLL(List);
List arrToLL(int [], int);



int main(){
    int arr[] = {55, 73, 62, 24, 41, 1, 45};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    List L = arrToLL(arr, size);
    
    lomutoQuickSort(arr, 0, size-1);
    printf("Lomuto Quick Sort\n");
    displayArr(arr, size);
    printf("\n\n");
    
    //printf("Array\n");
    //displayArr(arr, size);
    //List L = arrToLL(arr, size);
    //printf("\n\nLinked List\n");
    //displayLL(L);
    return 0;
}

void lomutoQuickSort(int arr[], int start, int end){
    if(start<end){
        int p = lomutoPartition(arr, start, end);
        lomutoQuickSort(arr, start, p-1);
        lomutoQuickSort(arr, p+1, end);
    }
}

int lomutoPartition(int arr[], int start, int end){
    int x = start, y = start-1, pivot = arr[end];
    if(start<end){
        while(x<=end){
            if(arr[x]<=pivot){
                int temp = arr[++y];
                arr[y] = arr[x];
                arr[x++] = temp;
            }
        }
    }
    return y;
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
