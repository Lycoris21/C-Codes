#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct node{
    int num;
    struct node* next;
}*List;

void selectionSort(int [], int);
void bubbleSort(int [], int);
void insertionSort(int [], int);

void combSort(int [], int);
void shellSortShifting(int [], int);
void shellSortSwapping(int [], int);

void gnomeSort(int [], int);
void strandSortArr(int [], int);

void displayArr(int [], int);
void displayLL(List);
List arrToLL(int [], int);



int main(){
    int arr[] = {55, 73, 62, 24, 41, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    List L = arrToLL(arr, size);
    
    //selectionSort(arr, size);
    //bubbleSort(arr, size);
    //insertionSort(arr, size);

    //combSort(arr, size);
    //shellSortShifting(arr, size);
    shellSortSwapping(arr, size);
    
    //gnomeSort(arr, size);
    //strandSortArr(arr, size);
    //strandSortLL(L);
    
    //printf("Array\n");
    //displayArr(arr, size);
    //List L = arrToLL(arr, size);
    //printf("\n\nLinked List\n");
    //displayLL(L);
    return 0;
}

void selectionSort(int arr[], int size){
    int i, j, min, temp;
    for(i = 0; i<size-1; i++){
        for(j=i+1, min = i; j<size; j++){
            if(arr[min]>arr[j]){
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
    
    printf("Selection Sort\n");
    displayArr(arr, size);
    printf("\n\n");
}

void bubbleSort(int arr[], int size){
    int i, j, temp;
    for(i=0; i<size-1; i++){
        for(j=0; j<size-1; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    printf("Bubble Sort\n");
    displayArr(arr, size);
    printf("\n\n");
}

void insertionSort(int arr[], int size){
    int i, j, temp;
    for(i=1; i<size; i++){
        for(j=i, temp = arr[i]; j>0 && temp<arr[j-1]; j--){
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
    
    printf("Insertion Sort\n");
    displayArr(arr, size);
    printf("\n\n");
}

void combSort(int arr[], int size){
    int x, gap = size, temp, sorted = 0;
    while(sorted == 0){
        gap /= 1.3;
        
        if(gap<1){
            gap = 1;
        }

        sorted = 1;

        for(x=0; x+gap<size; x++){
            if(arr[x]>arr[x+gap]){
                temp = arr[x];
                arr[x] = arr[x+gap];
                arr[x+gap] = temp;
                sorted = 0;
            }
        }
    }
    printf("Comb Sort\n");
    displayArr(arr, size);
    printf("\n\n");
}

void shellSortShifting(int arr[], int size){
    int gap, x, y, temp;
    for(gap = size/2; gap>0; gap/=2){
        for(x=gap; x<size; x++){
            temp = arr[x];
            for(y=x; y >= gap && arr[y-gap] > temp; y-=gap){
                arr[y] = arr[y-gap];
            }
            arr[y] = temp;
        }
    }
    printf("Shell Sort\n");
    displayArr(arr, size);
    printf("\n\n");
}

void shellSortSwapping(int arr[], int size){
    int gap, x, y, temp;
    for(gap = size/2; gap>0; gap/=2){
        for(x=gap; x<size; x++){
            for(y=x; y >= gap && arr[y] < arr[y-gap]; y-=gap){
                temp = arr[y];
                arr[y] = arr[y-gap];
                arr[y-gap] = temp;
            }
            
        }
    }
    printf("Shell Sort\n");
    displayArr(arr, size);
    printf("\n\n");
}
void gnomeSort(int arr[], int size){
    int i=0, temp;
    while(i<size){
        if(i>0 && arr[i]<arr[i-1]){
            temp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = temp;
            i--;
        } else{
            i++;    
        }
    }
    
    printf("Gnome Sort\n");
    displayArr(arr, size);
    printf("\n\n");
}

void strandSortArr(int arr[], int size){
    int i, j, x,count = 0;
    int strand[size], output[size], temp[size];
    while(count!=size){
        for(i=0, x=0; i<size; i++){
            if(arr[i]!=INF){
                strand[x] = arr[i];
                arr[i] = INF;
                x++;
            }
        }
        //union strand & output into temp
        
        count += x;
    }
}

void strandSortLL(List *L){
    List strand, output, temp;
    List trav;
    while(*L != NULL){
        // for(trav = *L, strand = *L; trav->next != NULL; trav = trav->next){
        //     if(trav->next->num >= strand->num){
        //         strand = trav->next;
        //     }
        // }
    }
    
    printf("Strand Sort Linked List\n");
    displayLL(*L);
    printf("\n\n");
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