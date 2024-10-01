#include <stdio.h>
#include <stdlib.h>

#define MAX (sizeof(unsigneed int) * 8)

typedef unsigned int Set;

void init(Set *S);
void displayBitPattern(Set S);

void insertElem(Set *S, int elem);
void deleteElem(Set *S, int elem);
void displayElem(Set S);

int main(void) {
    Set S = 21;
    
    displayBitPattern(S);
    
    return 0;
}

void init(Set *S) {
    *S = 0;
}

void displayBitPattern(Set S) {
    Set mask = 1 << MAX;
    
    for (; mask < S; mask << 1) {
        printf("%d ", ((S & mask!=0)? 1:0));
    }
}