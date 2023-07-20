#include <stdio.h>
#include <stdlib.h>

struct Node {
    double Value;
    struct Node* LeftNode;
    struct Node* RightNode;
};

struct BST {
    struct Node* root;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->Value = value;
    newNode->LeftNode = NULL;
    newNode->RightNode = NULL;
    return newNode;
}

void addNode(struct Node* root, int value, int flag) {
    if (value < root->Value) {
        if (root->LeftNode == NULL) {
            root->LeftNode = createNode(value);
            if (flag == 1) {
                FILE* file = fopen("input.txt", "a");
                if (file == NULL) {
                    printf("Error opening file.\n");
                    return;
                }
                fprintf(file, "%d ",value);
                fclose(file);
            }
        } else {
            addNode(root->LeftNode, value, flag);
        }
    } else if (value > root->Value) {
        if (root->RightNode == NULL) {
            root->RightNode = createNode(value);
            if (flag == 1) {
                FILE* file = fopen("input.txt", "a");
                if (file == NULL) {
                    printf("Error opening file.\n");
                    return;
                }
                fprintf(file, "%d ", value);
                fclose(file);
            }
        } else {
            addNode(root->RightNode, value, flag);
        }
    }
}


struct BST* generateBST(const char* filename) {
    struct BST* bst = (struct BST*)malloc(sizeof(struct BST));
    bst->root = NULL;
    
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return bst;
    }
    
    int value;
    if (fscanf(file, "%d", &value) == 1) {
        bst->root = createNode(value);
    }
    
    while (fscanf(file, "%d", &value) == 1) {
        addNode(bst->root, value,0);
    }
    
    fclose(file);
    return bst;
}

void removeNode(struct Node* root, int value) {
    if (root == NULL) {
        return;
    }
    
    if (value < root->Value) {
        removeNode(root->LeftNode, value);
    } else if (value > root->Value) {
        removeNode(root->RightNode, value);
    } else {
        // Node to be deleted found
        if (root->LeftNode == NULL && root->RightNode == NULL) {
            // Case 1: Node is a leaf node
            free(root);
            root = NULL;
        } else if (root->LeftNode == NULL) {
            // Case 2: Node has only right child
            struct Node* temp = root;
            root = root->RightNode;
            free(temp);
        } else if (root->RightNode == NULL) {
            // Case 3: Node has only left child
            struct Node* temp = root;
            root = root->LeftNode;
            free(temp);
        } else {
            // Case 4: Node has both left and right children
            struct Node* minValueNode = root->RightNode;
            while (minValueNode->LeftNode != NULL) {
                minValueNode = minValueNode->LeftNode;
            }
            root->Value = minValueNode->Value;
            removeNode(root->RightNode, minValueNode->Value);
        }
    }
}

struct Node* searchNode(struct Node* root, int value) {
    if (root == NULL || root->Value == value) {
        return root;
    }
    
    if (value < root->Value) {
        return searchNode(root->LeftNode, value);
    } else {
        return searchNode(root->RightNode, value);
    }
}

int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    
    return countNodes(root->LeftNode) + countNodes(root->RightNode) + 1;
}

int getMaxDepth(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    
    int leftDepth = getMaxDepth(root->LeftNode);
    int rightDepth = getMaxDepth(root->RightNode);
    
    if (leftDepth > rightDepth) {
        return leftDepth + 1;
    } else {
        return rightDepth + 1;
    }
}

int countLeafNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    
    if (root->LeftNode == NULL && root->RightNode == NULL) {
        return 1;
    }
    
    int leftLeafNodes = countLeafNodes(root->LeftNode);
    int rightLeafNodes = countLeafNodes(root->RightNode);
    
    return leftLeafNodes + rightLeafNodes;
}

void printInOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    
    printInOrder(root->LeftNode);
    printf("%d ", (int)root->Value);
    printInOrder(root->RightNode);
}

int main() {
    struct BST* bst = generateBST("input.txt");
    
    // Test the functions
    int choice;
    int value;
    struct Node* result;
    
    do {
        printf("\nSelect one of the options: \n\n");
        printf("1. Add Node\n");
        printf("2. Remove Node\n");
        printf("3. Search Node\n");
        printf("4. Count Nodes\n");
        printf("5. Get Max Depth\n");
        printf("6. Count Leaf Nodes\n");
        printf("7. Print Tree\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the value to add: ");
                scanf("%d", &value);
                addNode(bst->root, value,1);
                break;
            case 2:
                printf("Enter the value to remove: ");
                scanf("%d", &value);
                removeNode(bst->root, value);
                break;
            case 3:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                result = searchNode(bst->root, value);
                if (result != NULL) {
                    printf("Node with value %.2lf found.\n", result->Value);
                } else {
                    printf("Node not found.\n");
                }
                break;
            case 4:
                printf("Total number of nodes: %d\n", countNodes(bst->root));
                break;
            case 5:
                printf("Max depth of the tree: %d\n", getMaxDepth(bst->root));
                break;
            case 6:
                printf("Number of leaf nodes: %d\n", countLeafNodes(bst->root));
                break;
            case 7:
                printInOrder(bst->root);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 0);
    
    return 0;
}
