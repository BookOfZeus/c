#include "DoublyLinkedList.h"

/**
 * Check if the list is empty
 */
int isEmpty(struct doublyLinkedListNode *root) {
	return root == NULL;
}

/**
 * Check if a value exists in the list
 */
int exists(struct doublyLinkedListNode *root, int value) {
	if(isEmpty(root)) {
		return 0;
	}
	if(value == root->value) {
		return 1;
	}
	exists(root->next, value);
}

/**
 * Count the number of nodes in a list
 */
int countNode(struct doublyLinkedListNode *root) {
	if(isEmpty(root)) {
		return 0;
	}
	return 1 + countNode(root->next);
}

/**
 * Get the maximum value of a list
 */
int maxValue(struct doublyLinkedListNode *root) {
	if(isEmpty(root)) {
		return 0;
	}
	if(root->value < root->next->value) {
		return maxValue(root->next);
	}
	return root->value;
}

/**
 * Get the previous node
 */
int getPrevious(struct doublyLinkedListNode *root, int value) {
	if(isEmpty(root)) {
		return 0;
	}
	if(root->previous != NULL && root->value == value) {
		return root->previous->value;
	}
	getPrevious(root->next, value);
}

/**
 * Add a node to the list
 */
void addNode(struct doublyLinkedListNode **root, struct doublyLinkedListNode *node) {
	if(isEmpty(*root)) {
		*root = node;
		return;
	}
	node->previous = *root;
	addNode(&(*root)->next, node);
}

/**
 * Create a node
 */
struct doublyLinkedListNode *createNode(int value) {
	struct doublyLinkedListNode *tmp = malloc(sizeof(struct doublyLinkedListNode));
	if(tmp == NULL) {
		printf("ERROR: Out of Memory\n");
		exit(EXIT_FAILURE);
	}
	tmp->previous = NULL;
	tmp->next = NULL;
	tmp->value = value;
	return tmp;
}

/**
 * Delete a linked list
 */
void deleteList(struct doublyLinkedListNode **root) {
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
 * Remove a node from the list
 */
void removeNode(struct doublyLinkedListNode **root, int value) {
	if(isEmpty(*root)) {
		return;
	}
	struct doublyLinkedListNode *current = *root;

	for(; current != NULL; current = current->next) {
		if(current->value == value) {
			if(current->previous == NULL) {
				*root = current->next;
			}
			else {
				current->previous->next = current->next;
				current->next->previous = current->previous;
			}
			free(current);
			return;
		}
	}
}

/**
 * Display first in first out
 */
void displayFifo(struct doublyLinkedListNode *root) {
	if(root == NULL) {
		printf("\n** The list is empty **\n");
		return;
	}

	if(root->previous != NULL) {
		printf("Previous: %d --", root->previous->value);
	}
	printf("Current: %d", root->value);
	if(root->next != NULL) {
		printf("-- Next: %d --", root->next->value);
	}
	printf("\n");

	if(root->next) {
		displayFifo(root->next);
	}
}
