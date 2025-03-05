#include <stdio.h>

void deleteAllOccur(int[], int*, int);
void displayArr(int [], int);

int main() {
    int Arr[] = {1, 1, 7, 2, 1 , 5, 1};
    int count = sizeof(Arr)/sizeof(Arr[0]);
    int elem = 1;
    displayArr(Arr, count);
    deleteAllOccur(Arr, &count, elem);
    displayArr(Arr, count);

    return 0;
}

void deleteAllOccur(int Arr[], int *count, int elem){
    int x, y;
    for(x=y=0; x<*count; x++){
        if(Arr[x] != elem){
            Arr[y++] = Arr[x];
        }
    }
    *count = y;
}


void displayArr(int Arr[], int count){
    int x;
    for(x=0; x<count; x++){
        printf("%d ", Arr[x]);
    }
    printf("\n\n");
}