#include <stdlib.h>
#include <stdio.h>

#define max(x, y) (((x) > (y)) ? (x) : (y))

/**
 * Define the basic node type
 */
struct treeNode {
	int val;
	struct treeNode *right;
	struct treeNode *left;
};

//
// Lookup functions
//

int getHeight(struct treeNode **node);

int exists(struct treeNode **node, int x);

int isPerfect(struct treeNode **tree);

int isFull(struct treeNode **tree);

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
