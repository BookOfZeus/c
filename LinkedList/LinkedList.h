#include <stdlib.h>
#include <stdio.h>

/**
 * Define the basic node
 */
struct linkedListNode {
	int value;
	struct linkedListNode *next;
};

//
// Lookup functions
//

int isEmpty(struct linkedListNode *root);

int exists(struct linkedListNode *node, int value);

int countNode(struct linkedListNode *root);

int maxValue(struct linkedListNode *root);

//
// CRUD functions
//

void addNode(struct linkedListNode **root, struct linkedListNode *node);

struct linkedListNode * createNode(int value);

void deleteList(struct linkedListNode **root);

void insertAfter(struct linkedListNode **root, struct linkedListNode *node, int value);

void insertBefore(struct linkedListNode **root, struct linkedListNode *node, int value);

void removeNode(struct linkedListNode **root, int value);

//
// Output
//

void displayFifo(struct linkedListNode *root);

void displayPilo(struct linkedListNode *root);
