#include "BinaryTree.h"

/**
 * Add a node to a tree
 */
void addNode(struct treeNode **tree, struct treeNode *node) {
	if (*tree == NULL) {
		*tree = node;
		return;
	}
	if(node->val < (*tree)->val) {
		addNode(&(*tree)->left, node);
	}
	if(node->val > (*tree)->val) {
		addNode(&(*tree)->right, node);
	}
}

/**
 * Create a new node for the tree
 */
struct treeNode *createNode(int x) {
	struct treeNode *tmp = malloc(sizeof(struct treeNode));
	if(tmp == NULL) {
		printf("ERROR: Out of Memory\n");
		exit(EXIT_FAILURE);
	}
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->val = x;
	return tmp;
}

/**
 * Delete a node
 */
void deleteNode(struct treeNode **node) {
	if (*node == NULL) {
		return;
	}
	if ((*node)->left != NULL) {
		deleteNode(&(*node)->left);
	}
	if ((*node)->right != NULL) {
		deleteNode(&(*node)->right);
	}
	free(*node);
	*node = NULL;
}

/**
 * Calculate the height of the tree
 */
int getHeight(struct treeNode **node) {
	if(*node == NULL) {
		return 0;
	}
	int heightLeft = getHeight(&(*node)->left);
	int heightRight = getHeight(&(*node)->right);
	return max(heightLeft, heightRight) + 1;
} 

/**
 * Check if a node is perfect
 */
int isPerfect(struct treeNode **tree) {
	if(*tree == NULL) {
		return 1; 
	}
	int heightLeft  = getHeight(&(*tree)->left);
	int heightRight = getHeight(&(*tree)->right);
	if(heightLeft != heightRight) {
		return 0;
	}
	return isPerfect(&(*tree)->left) && isPerfect(&(*tree)->right);
}

/**
 * Check if a tree is full
 */
int isFull(struct treeNode **tree) {
	if(*tree == NULL) {
		return 1; 
	}
	if ((*tree)->left == NULL && (*tree)->right == NULL) {
		return 1;
	}
	if ((*tree)->left != NULL && (*tree)->right != NULL) {
		return isFull(&(*tree)->left) && isFull(&(*tree)->right);
	}
	return 0;
}

/**
 * Check if a node exist in a tree
 */
int exists(struct treeNode **tree, int x) {
	if (*tree == NULL) {
		return 0;
	}
	if (x < (*tree)->val) {
		return exists(&(*tree)->left, x);
	}
	if( x > (*tree)->val) { 
		return exists(&(*tree)->right, x);
	}
	return 1;
}

/**
 * Show the tree in a file/folder structure format
 */
void display(struct treeNode *tree, int level) {
	if(tree == NULL) {
		printf("\n** Tree is empty **\n");
		return;
	}
	printf("%*.*s%d\n", level, 0, " ", tree->val); 
	if(tree->left) {
		display(tree->left, level + 2);
	}
	if(tree->right) {
		display(tree->right, level + 2);
	}
}

/**
 * Display the tree in "in order" sequence
 */
void inOrder(struct treeNode *node) {
	if(node != NULL) {
		inOrder(node->left) ;
		printf ("%d, ", node->val) ;
		inOrder(node->right) ;
	}
}

/**
 * Display the tree in "pre order" sequence
 */
void preOrder(struct treeNode *node) {
	if(node != NULL) {
		printf ("%d, ", node->val) ;
		preOrder(node->left) ;
		preOrder(node->right) ;
	}
}

/**
 * Display the tree in "post order" sequence
 */
void postOrder(struct treeNode *node) {
	if(node != NULL) {
		postOrder(node->left) ;
		postOrder(node->right) ;
		printf ("%d, ", node->val) ;
	}
}
