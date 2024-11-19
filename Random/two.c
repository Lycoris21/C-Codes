#include <stdio.h>

typedef struct {
    char firstName[25];
    char lastName[25];
    unsigned int ID; // Used as comparison value
    // idfk im just making up fields now, the important bit is the ID in this struct
} StudRec;

typedef struct node {
    StudRec stud;
    struct node *prev; // Set to null if used as List
                           // Set to left child if used as tree
    struct node *next; // Set to right child if used as tree
} *BST;

void convertBst2List(ListBst *);