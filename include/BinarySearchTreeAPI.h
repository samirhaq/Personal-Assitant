#ifndef BST_GUARD
#define BST_GUARD

/**************************************
Interface for a Binary Tree ADT
Author:  Judi McCuaig
October, 2012
Modfied: James Fraser (Nov 2017)
**************************************/

/**
 * Function pointer tyepdefs
 */
typedef int (*CompareFunc)(const void* a, const void* b);
typedef void (*DeleteFunc)(void* data);
typedef void (*PrintFunc)(void* data);

/*
 * Typedef the void* to make the API cleaner and more readable.
 */
typedef void* TreeDataPtr;

/*
 * A Single Binary Tree Node.
 * Left and Right branches
 * void* data
 */
typedef struct binTreeNode TreeNode;
struct binTreeNode{
	TreeDataPtr data;
	TreeNode * left;
	TreeNode * right;
    //Tree* parentTree;  Optional but gets you access to function pointers.
};

/**
 * This is the definition of the Binary Tree.
 *
 */
typedef struct binTree
{
	TreeNode *root;
	CompareFunc userCompare;
	CompareFunc compareFunc;
	DeleteFunc deleteFunc;

	// Additions must work with abstract data types.
	// Additional function pointers to generalize tree.
	// Additional properties can be added such as count.
} Tree;

/**
 * Creates a TreeNode. TreeNode children are set to NULL and data is set to the passed in data.
 * @param data - the data to be stored within the Node. 
 * @return Newly created TreeNode
 *
 */
TreeNode* createTreeNode(TreeDataPtr data);

/**
 * createBinTree allocates memory for Tree and assigned function pointers
 * @param  compare [Function pointer to Compare data in tree nodes]
 * @param  userCompare [Function pointer to compare data with a user-defined data type]
 * @param  del     [Function pointer to delete data from node]
 * @return Newly created Tree
 */
Tree * createBinTree(CompareFunc compare, CompareFunc userCompare, DeleteFunc del);

/**
 * destroyBinTree - remove all items and free memory
 * @param  toDestroy - the tree
 * @return
 */
void  destroyBinTree(Tree * toDestroy);

/**
 * Add data to a tree
 * @param theTree 
 * @param data    
 */
void addToTree(Tree * theTree, TreeDataPtr data);

/**
 * Remove data from the tree
 * @param theTree 
 * @param data    
 */
void removeFromTree(Tree * theTree, TreeDataPtr data);


/**
 * This function searches the tree for the target data
 * @param  theTree 
 * @param  data    
 * @return         NULL if fail, otherwise return data
 */
TreeDataPtr findInTree( Tree* theTree, TreeDataPtr data );

/**
 * Get data from the root of the Tree if it exists.
 * @param  theTree 
 * @return NULL if tree is empty, otherwise return root
 */
TreeDataPtr getRootData(Tree * theTree);

/**
 * [printInOrder This function prints the tree using an inOrder traversal
 * @param theTree   [the tree]
 * @param printData [user defined print function]
 */
void printInOrder(Tree * theTree, PrintFunc printData);

/**
 * [printPreOrder This function prints the tree using an preOrder traversal
 * @param theTree   [the tree]
 * @param printData [user defined print function]
 */
void printPreOrder(Tree * theTree, PrintFunc printData);

/**
 * [printPostOrder This function prints the tree using an postOrder traversal
 * @param theTree   [the tree]
 * @param printData [user defined print function]
 */
void printPostOrder(Tree * theTree, PrintFunc printData);

/**
 * Checks if a tree is empty
 * @param  theTree [the tree]
 * @return        0 if false, 1 otherwise
 */
int isTreeEmpty(Tree* theTree);


/**
 * Helper function for checking if a single node is a leaf (no children)
 * @param  treeNode [the treeNode to check]
 * @return          0 if false, 1 otherwise
 */
int isLeaf( TreeNode * treeNode);

/**
 * Helper funciton for checking if a single node has two children.
 * @param  treeNode [the treeNode to check]
 * @return         0 if false, 1 otherwise
 */
int hasTwoChildren( TreeNode *treeNode);

/**
 * Helper funciton Get the height of a particulat Node in the tree. 
 * @param  treeNode [the treeNode to start from]
 * @return    (1-Based) heigh for the tree. 
 */
int getHeight( TreeNode* treeNode );


/**
 * You may add additional API functions below this comment if you want to extend the funcitonality.
 */

/**
 * Helper function to recursively add to the tree 
 * @param  currentNode [the node of the tree]
 * @param  data [The data of the node that needs to be inserted]
 * @param compareFunc [The compare function to compare two nodes]
 * @return    the root of the tree
 */
TreeNode* insert(TreeNode* currentNode, TreeDataPtr data, CompareFunc compareFunc);

/**
 * Helper function to recursively search for data
 * @param  currentNode [the node of the tree]
 * @param  data [The data of the node that needs to be found]
 * @param compareFunc [The compare function to compare the node data with the user defined data]
 * @return    the matching node
 */
TreeNode* find(TreeNode* currentNode, TreeDataPtr data, CompareFunc compareFunc);

/**
 * Helper function to get the minimum of the tree
 * @param  treeNode [the node of the tree]
 * @return    the minimum node
 */
void* getMinimum(TreeNode* node);

/**
 * Helper function to get the maximum of the tree
 * @param  treeNode [the node of the tree]
 * @return    the maximum node
 */
void* getMaximum(TreeNode* node);

/**
 * Helper function to recursively print in order
 * @param  root [the root of the tree]
 * @param printData user defined print function to print the data of the node
 */
void printInOrderHelper(TreeNode* root, PrintFunc printData);

/**
 * Helper function to recursively print post order
 * @param  root [the root of the tree]
 * @param printData user defined print function to print the data of the node
 */
void printPostOrderHelper(TreeNode* root, PrintFunc printData);

/**
 * Helper function to recursively print pre order
 * @param  root [the root of the tree]
 * @param printData user defined print function to print the data of the node
 */
void printPreOrderHelper(TreeNode* root, PrintFunc printData);

/**
 * Helper function to recursively print in order
 * @param  root [the root of the tree]
 * @param  data The data that is being removed
 * @param  user defined comare function to compare user defined data type and node data
 * @param  user defined delete function
 * @param the tree
 * @return the root of the tree
 */
TreeNode* removeNode(TreeNode* root, TreeDataPtr data, CompareFunc compare, DeleteFunc del);

/**
 * Helper function to recursively destroy the tree
 * @param  root [the root of the tree]
 * @param del user defined delete function to delete the data in the tree
 */
void destroy(TreeNode* root, DeleteFunc del);


#endif