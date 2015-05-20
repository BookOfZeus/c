#include <stdlib.h>
#include <stdio.h>

#define max(x, y) (((x) > (y)) ? (x) : (y))

/**
 * Define the basic node type
 */
struct treeNode {
	int value;
	struct treeNode *right;
	struct treeNode *left;
};

//
// Lookup functions
//

int exists(struct treeNode **node, int value);

int getHeight(struct treeNode **node);

int isBalanced(struct treeNode **tree);

int isFull(struct treeNode **tree);

int isPerfect(struct treeNode **tree);

struct treeNode * search(struct treeNode *tree, int);

struct treeNode * searchChild(struct treeNode **tree, int);

//
// CRUD functions
//

void addNode(struct treeNode **tree, struct treeNode *node);

struct treeNode * createNode(int);

void deleteNode(struct treeNode **node);

//
// Output
//

void display(struct treeNode *node, int level);

void inOrder(struct treeNode *tree);

void preOrder(struct treeNode *tree);

void postOrder(struct treeNode *tree);
