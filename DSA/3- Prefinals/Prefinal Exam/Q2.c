/*

Given the definition of data type ListBST representing a list or a BST:

typedef struct{
    char name[30];
    char ID[10];
    char course[8];
    int yrLevel;
}studRec;

//Definition of List and BST
typedef struct node{
    studRec stud;
    struct node *prev; //NULL if node is used in the List
                       //Points to the Left child if node is used in BST
    struct node *next; //Points to the next node if used in the List
                       //Points to the Right child if node is used in BST
}*ListBST;

Write the code of the function convertBst2List(). The function will convert a given BST into a list sorted in ascending order to ID by continuously deleting the biggest remaining element in the BST until it is empty. BST is organized to the ID.

CONSTRAINTS:
    1 return statement only if necessary, no break/exit statement

*/