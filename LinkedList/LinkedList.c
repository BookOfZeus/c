#include "LinkedList.h"

/**
 * Check if the list is empty
 */
int isEmpty(struct linkedListNode *root) {
	return root == NULL;
}

/**
 * Count the number of nodes in a list
 */
int countNode(struct linkedListNode *root) {
	if(isEmpty(root)) {
		return 0;
	}
	return 1 + countNode(root->next);
}

/**
 * Check if a value exists in the list
 */
int exists(struct linkedListNode *root, int value) {
	if(isEmpty(root)) {
		return 0;
	}
	if(value == root->value) {
		return 1;
	}
	exists(root->next, value);
}

/**
 * Get the next value of a node
 */
int getNext(struct linkedListNode *node, int value) {
	if(isEmpty(node)) {
		return 0;
	}
	if(!exists(node, value)) {
		return 0;
	}
	if(node->next == NULL) {
		return 0;
	}
	if(node->value == value) {
		return node->next->value;
	}
	getNext(node->next, value);
}

/**
 * Get the previous value of a node
 */
int getPrevious(struct linkedListNode *node, int value) {
	if(isEmpty(node)) {
		return 0;
	}
	if(!exists(node, value)) {
		return 0;
	}
	if(node->value == value) {
		return 0;
	}
	if(node->next->value == value) {
		return node->value;
	}
	getPrevious(node->next, value);
}

/**
 * Get the maximum value of a list
 */
int maxValue(struct linkedListNode *root) {
	if(isEmpty(root)) {
		return 0;
	}
	if(root->value < root->next->value) {
		return maxValue(root->next);
	}
	return root->value;
}

/**
 * Add a node to the list
 */
void addNode(struct linkedListNode **root, struct linkedListNode *node) {
	if(isEmpty(*root)) {
		*root = node;
		return;
	}
	addNode(&(*root)->next, node);
}

/**
 * Create a node
 */
struct linkedListNode *createNode(int value) {
	struct linkedListNode *tmp = malloc(sizeof(struct linkedListNode));
	if(tmp == NULL) {
		printf("ERROR: Out of Memory\n");
		exit(EXIT_FAILURE);
	}
	tmp->next = NULL;
	tmp->value = value;
	return tmp;
}

/**
 * Delete a linked list
 */
void deleteList(struct linkedListNode **root) {
	if(isEmpty(*root)) {
		return;
	}
	if((*root)->next != NULL) {
		deleteList(&(*root)->next);
	}
	free(*root);
	*root = NULL;
}

/**
 * Insert a node after a specific value
 */
void insertAfter(struct linkedListNode **root, struct linkedListNode *node, int value) {
	if(isEmpty(*root)) {
		return;
	}
	if((*root)->value == value) {
		if((*root)->next != NULL) {
			node->next = (*root)->next;
		}
		(*root)->next = node;
	}
	insertAfter(&(*root)->next, node, value);
}

/**
 * Insert a node before a specific value
 */
void insertBefore(struct linkedListNode **root, struct linkedListNode *node, int value) {
	if(isEmpty(*root)) {
		return;
	}
	if((*root)->value == value) {
		node->next = *root;
		*root = node;
		return;
	}
	else if((*root)->next->value == value) {
		node->next = (*root)->next;
		(*root)->next = node;
		return;
	}
	insertBefore(&(*root)->next, node, value);
}

/**
 * Remove a node from the list
 */
void removeNode(struct linkedListNode **root, int value) {
	if(isEmpty(*root)) {
		return;
	}
	if(!exists(*root, value)) {
		return;
	}
	struct linkedListNode *previous = NULL;
	struct linkedListNode *current = *root;
	for(; current != NULL; previous = current, current = current->next) {
		if(current->value == value) {
			if(previous == NULL) {
				*root = current->next;
			}
			else {
				previous->next = current->next;
			}
			free(current);
			return;
		}
	}
}

/**
 * Remove a node after a value
 */
void removeAfter(struct linkedListNode **root, int value) {
	if(isEmpty(*root)) {
		return;
	}
	if(!exists(*root, value)) {
		return;
	}
	int after = getNext((*root), value);
	if(after == 0) {
		return;
	}
	removeNode(&(*root), after);
}

/**
 * Remove a node before a value
 */
void removeBefore(struct linkedListNode **root, int value) {
	if(isEmpty(*root)) {
		return;
	}
	if(!exists(*root, value)) {
		return;
	}
	int before = getPrevious((*root), value);
	if(before == 0) {
		return;
	}
	removeNode(&(*root), before);
}

/**
 * Display first in first out
 */
void displayFifo(struct linkedListNode *root) {
	if(root == NULL) {
		printf("\n** The list is empty **\n");
		return;
	}
	printf("%*.*s%d\n", 1, 1, " ", root->value);
	if(root->next) {
		displayFifo(root->next);
	}
}

/**
 * Display first in last out
 */
void displayFilo(struct linkedListNode *root) {
	if(root == NULL) {
		printf("\n** The list is empty **\n");
		return;
	}
	if(root->next) {
		displayFilo(root->next);
	}
	printf("%*.*s%d\n", 1, 1, " ", root->value);
}
