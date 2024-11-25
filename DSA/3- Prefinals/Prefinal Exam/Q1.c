    /*

    Given the Tree and a Node, get the label of the right sibling of the given node.

    */

    #include <stdio.h>
    #define MAX 10
    #define ROOT -1
    #define NOPE -2

    typedef int Node;

    typedef struct{
        Node parent;
        char label;
    }PTNode;

    typedef PTNode PTtree[MAX];

    void initTree(PTtree *);
    void populateTree(PTtree*); 
    void displayTree(PTtree);
    char getRightSiblingLabel(Node, PTtree); 

    int main(){
        PTtree Tree;
        initTree(&Tree);
        printf("==========INITIALIZATION CHECK==========\n");
        displayTree(Tree);
        populateTree(&Tree);
        printf("\n\n==========POPULATED TREE==========\n");
        displayTree(Tree);
        printf("\n\nRight sibling label: %c", getRightSiblingLabel(4, Tree));

        return 0;
    }

    void initTree(PTtree *T){
        int x;
        for(x=0; x<MAX; x++){
            (*T)[x].parent = NOPE;
            (*T)[x].label = '!';
        }
    }

    void populateTree(PTtree *T){
        PTtree temp = {
                        {7, 'A'},
                        {4, 'B'},
                        {4, 'C'},
                        {ROOT, 'D'},
                        {3, 'E'},
                        {9, 'F'},
                        {9, 'G'},
                        {3, 'H'},
                        {7, 'I'},
                        {3, 'J'}
        };
        int x;
        for(x=0; x<MAX; x++){
            (*T)[x].parent = temp[x].parent;
            (*T)[x].label = temp[x].label;
        }
    }
    void displayTree(PTtree T){
        int x;
        for(x=0; x<MAX; x++){
            printf("Parent: %d\tLabel: %c\n", T[x].parent, T[x].label);
        }
    }
    char getRightSiblingLabel(Node node, PTtree tree){
        int x;
        char label = '#';
        if(tree[node].parent != ROOT){
            for(x=node+1; x<MAX && tree[node].parent != tree[x].parent; x++){}
            if(x<MAX){
                label = tree[x].label;
            }
        }
        return label;
    }