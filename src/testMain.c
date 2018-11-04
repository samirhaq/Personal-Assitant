#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#include "BinarySearchTreeAPI.h"
#include "personalAssistant.h"

void printInt(void * a) {
    printf("%d\n", *(int*)a);
    return;
}

void deleteInt(void * a) {
    free((int*)a);
    return;
}

int compareInt( const void * a, const void * b) {

     if (*(int*)a > *(int*)b) {
        return 1;
    }

    else if (*(int*)a < *(int*)b) {
        return -1;
    }

    else {
        return 0;
    }
}

int main(int argc, char ** argv) {
    int correct = 0;
    printf("Testing createBinTree()\n");
    Tree* tree = createBinTree(&compareInt, &compareInt, &deleteInt);
    printf("Expected result: The binary search tree exists\n");

    if (tree != NULL) {
        correct += 1;
        printf("Test passed\n");
    }

    else {
        printf("Test failed\n");
    }
    printf("**************************************************************************************************\n\n");


    printf("Testing createTreeNode() using an int\n");
    //Edge Case because of empty string
    int* intptr = malloc(sizeof(int));
    *intptr = 5;
    TreeNode *node = createTreeNode(intptr);
    addToTree(tree, intptr);
    printf("Expected Result: The Node exists and the data is not NULL\n");

    if (node != NULL) {
        if (node->data != NULL) {
            printf("Test passed\n");
            correct += 1;
        }

        else {
            printf("Test failed\n");
        }
    }
    else {
        printf("Test failed\n");
    }

    printf("**************************************************************************************************\n\n");

 
    printf("Testing addToTree() using an int\n");
    printf("Expected Result: 5 at the root\n");
    int* intptr2 = malloc(sizeof(int));
    *intptr2 = INT_MAX; //Edge case because of max integer value
    addToTree(tree, intptr2);
    printInOrder(tree, printInt);
    int* intTest = getRootData(tree);

    if (*intTest == 5) {
        printf("Test passed\n");
        correct += 1;
    }

    else {
        printf("Test failed\n");
    }
     printf("**************************************************************************************************\n\n");

    
    printf("Testing findInTree() using an int\n");
    printf("Expected Result: The int returned is 5\n");
    intTest = findInTree(tree, intptr);

    if (*intTest == 5) {
        printf("Test passed\n");
        correct += 1;
    }

    else {
        printf("Test failed\n");
    }

    printf("**************************************************************************************************\n\n");
    
    printf("Testing removeFromTree() using an integer\n");
    printf("Expected Result: 5 should be removed from the tree\n");
    removeFromTree(tree, intptr);
    printInOrder(tree, printInt);

    if (findInTree(tree, intptr) == NULL) {
        printf("Test passed\n");
        correct += 1;
    }
    

    else {
        printf("Test failed\n");
    }
    
    printf("**************************************************************************************************\n\n");

    int* intptr3 = malloc(sizeof(int));
    *intptr3 = INT_MIN; //Edge case
    addToTree(tree, intptr3);
    int* intptr4 = malloc(sizeof(int));
    *intptr4 = 5;
    addToTree(tree, intptr4);
    int* intptr5 = malloc(sizeof(int));
    *intptr5 = 2;
    addToTree(tree, intptr5);
    int* intptr6 = malloc(sizeof(int));
    *intptr6 = 7;
    addToTree(tree, intptr6);
    int* intptr7 = malloc(sizeof(int));
    *intptr7 = 9;
    addToTree(tree, intptr7);
    int* intptr8 = malloc(sizeof(int));
    *intptr8 = 4;
    addToTree(tree, intptr8);
    int* intptr9 = malloc(sizeof(int));
    *intptr9 = 8;
    addToTree(tree, intptr9);
    int* intptr10 = malloc(sizeof(int));
    *intptr10 = 1;
    addToTree(tree, intptr10);

    printf("Testing getRootData() using int\n");
    printf("Expected Result: The max int should be the root\n");
    intTest = getRootData(tree);
    printf("%d\n", *intTest);
    if (*intTest == INT_MAX) { 
        printf("Test passed\n");
        correct += 1;
    }

    else {
        printf("Test failed\n");
    }


    printf("**************************************************************************************************\n\n");
    printf("Testing getHeight() using integers\n");
    printf("Expected Result: The height should be 6\n");
    int height = getHeight(tree->root);
    if (height == 6) {
        printf("Test passed\n");
        correct += 1;
    }

    else {
        printf("Test failed\n");
    }

    printf("**************************************************************************************************\n\n");

printf("Testing isLeaf() using integers\n");
    printf("Expected Result: The min int should be a leaf\n");
    TreeNode* leafNode = findInTree(tree, intptr3);
    int leaf = isLeaf(leafNode);
    if (leaf == 1) {
        printf("Test passed\n");
        correct += 1;
    }

    else {
        printf("Test failed\n");
    }

    printf("**************************************************************************************************\n\n");
    
    printf("Testing hasChildren() using integers\n");
    printf("Expected Result: 5 should have 2 children\n");
    TreeNode* childrenNode = find(tree->root, intptr4, tree->compareFunc);
    int children = hasTwoChildren(childrenNode);
    if (children == 1) {
        printf("Test passed\n");
        correct += 1;
    }

    else {
        printf("Test failed\n");
    }

    printf("**************************************************************************************************\n\n");
    printf("Testing getMinimum() using integers\n");
    printf("Expected Result: The minimum should be the min int\n");
    TreeNode* minNode = getMinimum(tree->root);
    printInt(minNode->data);
    int* minInt = (int*)minNode->data;
    if (*minInt == INT_MIN) {
        printf("Test passed\n");
        correct += 1;
    }

    else {
        printf("Test failed\n");
    }

    printf("**************************************************************************************************\n\n");
    printf("Testing getMaximum() using integers\n");
    printf("Expected Result: The max should be the max int\n");
    TreeNode* maxNode = getMaximum(tree->root);
    printInt(maxNode->data);
    int* maxInt = (int*)maxNode->data;
    if (*maxInt == INT_MAX) {
        printf("Test passed\n");
        correct += 1;
    }

    else {
        printf("Test failed\n");
    }

    printf("**************************************************************************************************\n\n");
    printf("Testing destroyBinTree() using integers\n");
    printf("Expected Result: The tree root should be NULL\n");
    destroyBinTree(tree);
    if (tree->root == NULL) {
        printf("Test passed\n");
        correct += 1;
    }

    else {
        printf("Test failed\n");
    }

    printf("**************************************************************************************************\n\n");
    
    printf("%d/12 tests passed.\n", correct);
    return 0;
    
}

