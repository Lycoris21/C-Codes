#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int keys[2]; // Maximum of 2 keys
    struct Node *children[3]; // Maximum of 3 children
    int numKeys; // Number of keys in the node
    int isLeaf; // 1 if the node is a leaf, 0 otherwise
} Node;

Node* createNode(int key, int isLeaf) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->keys[0] = key;
    newNode->numKeys = 1;
    newNode->isLeaf = isLeaf;
    for (int i = 0; i < 3; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

void splitChild(Node* parent, int index) {
    Node* child = parent->children[index];
    Node* newChild = createNode(child->keys[1], child->isLeaf);

    if (!child->isLeaf) {
        newChild->children[0] = child->children[1];
        newChild->children[1] = child->children[2];
    }

    child->numKeys = 1;

    for (int i = parent->numKeys; i > index; i--) {
        parent->children[i + 1] = parent->children[i];
        parent->keys[i] = parent->keys[i - 1];
    }

    parent->children[index + 1] = newChild;
    parent->keys[index] = child->keys[1];
    parent->numKeys++;
}

void insertNonFull(Node* node, int key) {
    int i = node->numKeys - 1;

    if (node->isLeaf) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->numKeys++;
    } else {
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }
        i++;
        if (node->children[i]->numKeys == 2) {
            splitChild(node, i);
            if (key > node->keys[i]) {
                i++;
            }
        }
        insertNonFull(node->children[i], key);
    }
}

Node* insert(Node* root, int key) {
    if (root->numKeys == 2) {
        Node* newRoot = createNode(0, 0);
        newRoot->children[0] = root;
        splitChild(newRoot, 0);
        int i = (key > newRoot->keys[0]) ? 1 : 0;
        insertNonFull(newRoot->children[i], key);
        return newRoot;
    } else {
        insertNonFull(root, key);
        return root;
    }
}

int search(Node* root, int key) {
    int i = 0;
    while (i < root->numKeys && key > root->keys[i]) {
        i++;
    }

    if (i < root->numKeys && key == root->keys[i]) {
        return 1; // Key found
    }

    if (root->isLeaf) {
        return 0; // Key not found
    }

    return search(root->children[i], key);
}

void traverse(Node* root) {
    if (root == NULL) return;

    for (int i = 0; i < root->numKeys; i++) {
        if (!root->isLeaf) {
            traverse(root->children[i]);
        }
        printf("%d ", root->keys[i]);
    }
    if (!root->isLeaf) {
        traverse(root->children[root->numKeys]);
    }
}

// Helper function to merge children during deletion
void merge(Node* root, int idx) {
    Node* child = root->children[idx];
    Node* sibling = root->children[idx + 1];

    child->keys[1] = root->keys[idx];

    if (!child->isLeaf) {
        child->children[1] = sibling->children[0];
        child->children[2] = sibling->children[1];
    }

    for (int i = idx; i < root->numKeys - 1; i++) {
        root->keys[i] = root->keys[i + 1];
        root->children[i + 1] = root->children[i + 2];
    }

    root->numKeys--;
    child->numKeys = 2;

    free(sibling);
}

// Helper function to find the predecessor key
int getPredecessor(Node* root, int idx) {
    Node* current = root->children[idx];
    while (!current->isLeaf) {
        current = current->children[current->numKeys];
    }
    return current->keys[current->numKeys - 1];
}

// Helper function to find the successor key
int getSuccessor(Node* root, int idx) {
    Node* current = root->children[idx + 1];
    while (!current->isLeaf) {
        current = current->children[0];
    }
    return current->keys[0];
}

// Helper function to fill a child during deletion
void fill(Node* root, int idx) {
    if (idx != 0 && root->children[idx - 1]->numKeys > 1) {
        Node* child = root->children[idx];
        Node* sibling = root->children[idx - 1];

        for (int i = child->numKeys - 1; i >= 0; i--) {
            child->keys[i + 1] = child->keys[i];
        }

        if (!child->isLeaf) {
            for (int i = child->numKeys; i >= 0; i--) {
                child->children[i + 1] = child->children[i];
            }
        }

        child->keys[0] = root->keys[idx - 1];
        if (!child->isLeaf) {
            child->children[0] = sibling->children[sibling->numKeys];
        }

        root->keys[idx - 1] = sibling->keys[sibling->numKeys - 1];
        child->numKeys++;
        sibling->numKeys--;
    } else if (idx != root->numKeys && root->children[idx + 1]->numKeys > 1) {
        Node* child = root->children[idx];
        Node* sibling = root->children[idx + 1];

        child->keys[child->numKeys] = root->keys[idx];
        if (!child->isLeaf) {
            child->children[child->numKeys + 1] = sibling->children[0];
        }

        root->keys[idx] = sibling->keys[0];

        for (int i = 1; i < sibling->numKeys; i++) {
            sibling->keys[i - 1] = sibling->keys[i];
        }

        if (!sibling->isLeaf) {
            for (int i = 1; i <= sibling->numKeys; i++) {
                sibling->children[i - 1] = sibling->children[i];
            }
        }

        child->numKeys++;
        sibling->numKeys--;
    } else {
        if (idx != root->numKeys) {
            merge(root, idx);
        } else {
            merge(root, idx - 1);
        }
    }
}

// Helper function to delete a key from a node
void deleteFromNode(Node* root, int key) {
    int idx = 0;
    while (idx < root->numKeys && key > root->keys[idx]) {
        idx++;
    }

    if (idx < root->numKeys && key == root->keys[idx]) {
        if (root->isLeaf) {
            for (int i = idx; i < root->numKeys - 1; i++) {
                root->keys[i] = root->keys[i + 1];
            }
            root->numKeys--;
        } else {
            if (root->children[idx]->numKeys > 1) {
                int pred = getPredecessor(root, idx);
                root->keys[idx] = pred;
                deleteFromNode(root->children[idx], pred);
            } else if (root->children[idx + 1]->numKeys > 1) {
                int succ = getSuccessor(root, idx);
                root->keys[idx] = succ;
                deleteFromNode(root->children[idx + 1], succ);
            } else {
                merge(root, idx);
                deleteFromNode(root->children[idx], key);
            }
        }
    } else {
        if (root->isLeaf) {
            printf("Key %d not found in the tree.\n", key);
            return;
        }

        int flag = (idx == root->numKeys);
        if (root->children[idx]->numKeys == 1) {
            fill(root, idx);
        }

        if (flag && idx > root->numKeys) {
            deleteFromNode(root->children[idx - 1], key);
        } else {
            deleteFromNode(root->children[idx], key);
        }
    }
}

Node* delete(Node* root, int key) {
    if (!root) {
        printf("The tree is empty.\n");
        return NULL;
    }

    deleteFromNode(root, key);

    if (root->numKeys == 0) {
        Node* temp = root;
        if (root->isLeaf) {
            root = NULL;
        } else {
            root = root->children[0];
        }
        free(temp);
    }

    return root;
}

int main() {
    Node* root = createNode(10, 1); // Start with a single key in the root

    int keys[] = {20, 5, 15, 30, 25, 35};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, keys[i]);
    }

    printf("Traversal of the 2-3 Tree:\n");
    traverse(root);
    printf("\n");

    printf("Searching for 15: %s\n", search(root, 15) ? "Found" : "Not Found");
    printf("Searching for 40: %s\n", search(root, 40) ? "Found" : "Not Found");

    printf("Deleting 15...\n");
    root = delete(root, 15);
    printf("Traversal after deletion:\n");
    traverse(root);
    printf("\n");

    return 0;
}