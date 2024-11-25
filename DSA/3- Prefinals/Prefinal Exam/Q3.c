    /*

    Given the definition of a max heap:

    #define MAX 0XD 
    typedef int maxHeapList[MAX];
    typedef enum{TRUE, FALSE} Boolean;

    A variation of the max heap or list stores the number of elements in the max heap or list at the first position in the array. In effect, the first element of the heap or list is stored at the second position of the array. Write the code of the function isMaxHeap(). The function will return TRUE if the given list is also a heap; otherwise return FALSE.

    CONSTRAINTS: 
        1 return statement only, no break/exit statement

    */

    #include <stdio.h>

    #define MAX 0XD 
    typedef int maxHeapList[MAX];
    typedef enum{TRUE, FALSE} Boolean;

    void initHeap(maxHeapList *);
    void populateHeap(maxHeapList *);
    void displayHeap(maxHeapList);
    Boolean isMaxHeap(maxHeapList);

    int main(){

        maxHeapList heap;
        initHeap(&heap);
        printf("==========INITIALIZATION CHECK==========\n");
        displayHeap(heap);
        populateHeap(&heap);
        printf("\n\n==========POPULATED HEAP==========\n");
        displayHeap(heap);
        printf("\n\nMaxHeap? %s", (isMaxHeap(heap))? "FALSE" : "TRUE"); //baliktad coz when I return TRUE from the function, in enum TRUE is index 0 and so in ternary it will result in a false :/
        printf("\nMaxHeap? %d", isMaxHeap(heap)); //THIS IS PROOF ARGHHH
        printf("\nIn the enum, TRUE is in index 0 :/");

        return 0;
    }

    void initHeap(maxHeapList *H){
        (*H)[0] = 0;
    }

    void populateHeap(maxHeapList *H){
        maxHeapList temp = {7, 21, 15, 18, 7, 3, 11, 9};
        int x;
        for(x=0; x <= temp[0]; x++){
            (*H)[x] = temp[x];
        }
    }
    void displayHeap(maxHeapList H){
        int x;
        for(x=1; x <= H[0]; x++){
            printf("%d ", H[x]);
        }
    }

    Boolean isMaxHeap(maxHeapList H){
        int parent = H[0] / 2;
        int LC = parent * 2;
        int RC = ((LC + 1) <= H[0]) ? LC + 1 : LC;
        int big = (H[LC] > H[RC]) ?  LC : RC;

        while(parent > 0 && H[parent] >= H[big]){
            LC = parent * 2;
            RC = ((LC + 1) <= H[0]) ? LC + 1 : LC;
            big = (H[LC] > H[RC]) ?  LC : RC;
            parent--;
        }
        return (parent > 0) ? FALSE : TRUE;
    }