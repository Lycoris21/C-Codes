#include <stdio.h>

#define LENGTH 100

typedef struct{
   int elem[LENGTH];
   int count;
}List;

List TwoWaySortMerge(List A, List B);

int main() {
    List A = {{1,8,7}, 3};
    List B = {{2, 3, 9, 11}, 4};
    List C = TwoWaySortMerge(A, B);
    for(int x=0; x<C.count; x++){
        printf("%d ", C.elem[x]);
    }
    return 0;
}

List TwoWaySortMerge(List A, List B){
    List C;
    C.count = 0;
    int x, y;
    x = y = 0;
    while(x<A.count && y<B.count){
        C.elem[(C.count)++] = (A.elem[x] < B.elem[y])? (A.elem[x++]) : (B.elem[y++]);
    }
    if(x==A.count){
        A = B;
    }
    while(y<A.count){
        C.elem[(C.count)++] = A.elem[y++];
    }
    return C;
}