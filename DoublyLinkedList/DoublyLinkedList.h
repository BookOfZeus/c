#include <stdlib.h>
#include <stdio.h>

/**
 * Define the basic node
 */
struct doublyLinkedListNode {
	int value;
	struct doublyLinkedListNode *previous;
	struct doublyLinkedListNode *next;
};

//
// Lookup functions
//

int isEmpty(struct doublyLinkedListNode *root);

int exists(struct doublyLinkedListNode *node, int value);

int countNode(struct doublyLinkedListNode *root);

int maxValue(struct doublyLinkedListNode *root);

int getPrevious(struct doublyLinkedListNode *root, int value);

//
// CRUD functions
//

void addNode(struct doublyLinkedListNode **root, struct doublyLinkedListNode *node);

struct doublyLinkedListNode * createNode(int value);

void deleteList(struct doublyLinkedListNode **root);

void removeNode(struct doublyLinkedListNode **root, int value);

//
// Output
//

void displayFifo(struct doublyLinkedListNode *root);
