#include <stdio.h>
#include <stdlib.h>

#include "BinarySearchTreeAPI.h"

TreeNode* createTreeNode(TreeDataPtr data) {
    TreeNode* node = malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Tree * createBinTree(CompareFunc compare, CompareFunc userCompare, DeleteFunc del) {
    Tree* tree = malloc(sizeof(Tree));
    tree->root = NULL;
    tree->compareFunc = compare;
    tree->userCompare = userCompare;
    tree->deleteFunc = del;
    return tree;
}

void  destroyBinTree(Tree * toDestroy) {
    destroy(toDestroy->root, toDestroy->deleteFunc);
    free(toDestroy);
    toDestroy = NULL;
}

void removeFromTree(Tree * theTree, TreeDataPtr data) {
    theTree->root = removeNode(theTree->root, data, theTree->userCompare, theTree->deleteFunc);
    return;
}

void addToTree(Tree * theTree, TreeDataPtr data) {
    theTree->root = insert(theTree->root, data, theTree->compareFunc);
    return;
}

TreeDataPtr getRootData(Tree * theTree) {
    return theTree->root->data;
}

int isTreeEmpty(Tree* theTree) {
    if (theTree->root == NULL) {
        return 1;
    }

    else {
        return 0;
    }
}

int isLeaf( TreeNode * treeNode) {

    if ((treeNode->right == NULL) && (treeNode->left == NULL)) {
        return 1;
    }

    else {
        return 0;
    }
}

int hasTwoChildren( TreeNode *treeNode) {
    
    if ((treeNode->right != NULL) && (treeNode->left != NULL)) {
        return 1;
    }

    else {
        return 0;
    }
}

TreeDataPtr findInTree( Tree* theTree, TreeDataPtr data ) {
    
    TreeNode* node = find(theTree->root, data, theTree->userCompare);

    if (node != NULL) {
        return node->data;
    }

    else {
        return NULL;
    }
}

TreeNode* insert(TreeNode* currentNode, TreeDataPtr data, CompareFunc compareFunc) {
    
    if (currentNode == NULL) {
        TreeNode* node = createTreeNode(data);
        return node;
    }

    if (compareFunc(currentNode->data, data) < 0) {
        currentNode->right = insert(currentNode->right, data, compareFunc);
    }

    else if (compareFunc(currentNode->data, data) > 0) {
        currentNode->left = insert(currentNode->left, data, compareFunc);
    }
    return currentNode;
}

TreeNode* find(TreeNode* currentNode, TreeDataPtr data, CompareFunc compareFunc) {
    if (currentNode == NULL) {
        return NULL;
    }

    if (compareFunc(currentNode->data, data) == 0) {
        return currentNode;
    }

    else if (compareFunc(currentNode->data, data) > 0) {
        return find(currentNode->left, data, compareFunc);
    }

    else {
        return find(currentNode->right, data, compareFunc);
    }
}


int getHeight( TreeNode* treeNode ) {

    if (treeNode == NULL) {
        return 0;
    }

    int left = getHeight(treeNode->left);
    int right = getHeight(treeNode->right);
    
    if (right > left) {
        return right + 1;
    }

    else {
        return left + 1;
    }
}

void* getMinimum(TreeNode* node) {

    if (node->left == NULL) {
        return node;
    }

    else {
        return getMinimum(node->left);
    }
}

void* getMaximum(TreeNode* node) {

    if (node->right == NULL) {
        return node;
    }

    else {
        return getMaximum(node->right);
    }
}

void printInOrder(Tree * theTree, PrintFunc printData) {
    TreeNode* root = theTree->root;
    printInOrderHelper(root, printData);
}

void printPostOrder(Tree * theTree, PrintFunc printData) {
    TreeNode* root = theTree->root;
    printPostOrderHelper(root, printData);

}

void printPreOrder(Tree * theTree, PrintFunc printData) {
    TreeNode* root = theTree->root;
    printPreOrderHelper(root, printData);

}
    

void printInOrderHelper(TreeNode* root, PrintFunc printData) {

    if (root == NULL) {
        return;
    }

    printInOrderHelper(root->left, printData);
    printData(root->data);
    printInOrderHelper(root->right, printData);

}

void printPostOrderHelper(TreeNode* root, PrintFunc printData) {
    if (root == NULL) {
        return;
    }

    printPostOrderHelper(root->left, printData);
    printPostOrderHelper(root->right, printData);
    printData(root->data);
}

void printPreOrderHelper(TreeNode* root, PrintFunc printData) {
    if (root == NULL) {
        return;
    }

    printData(root->data);
    printPostOrderHelper(root->left, printData);
    printPreOrderHelper(root->right, printData);
}

TreeNode* removeNode(TreeNode* root, TreeDataPtr data, CompareFunc compare, DeleteFunc del) {
    if (root == NULL) {
        return root;
    }

    if (compare(root->data, data) < 0) {
        root->right = removeNode(root->right, data, compare, del);
    }

    else if (compare(root->data, data) > 0) {
        root->left = removeNode(root->left, data, compare, del);
    }

    else {
        if (isLeaf(root) == 1) {
            del(root->data);
            free(root);
            root = NULL;
        }

        else if (hasTwoChildren(root) == 1) {
            TreeNode* tempNode = getMinimum(root->right);
            root->data = tempNode->data;
            root->right = tempNode->right;
            root->right = removeNode(root->right, tempNode->data, compare, del);
        }

        else {
            if (root->left == NULL) {
                TreeNode* newRoot = root->right;
                del(root->data);
                free(root);
                root->left = NULL;
                root->right = NULL;
                root = NULL;
                return newRoot;
            }

            else if (root->right == NULL) {
                TreeNode* newRoot = root->left;
                del(root->data);
                free(root);
                root->left = NULL;
                root->right = NULL;
                root = NULL;
                return newRoot;
            }
        }
    }
    return root;
}

void destroy(TreeNode* root, DeleteFunc del) {
    if (root == NULL) {
        return;
    }

    if (root->right != NULL) {
        destroy(root->right, del);
    }

    else if (root->left != NULL) {
        destroy(root->left, del);
    }

    del(root->data);
    free(root);
    root = NULL;
}



