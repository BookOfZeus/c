#include "Stack.h"

/**
 * Check if the list is empty
 */
int isEmpty(struct stack *stack) {
	return stack->size == 0;
}

/**
 * Check if the list is empty
 */
int isFull(struct stack *stack) {
	return stack->size == MAX_ELEMENT;
}

/**
 * Get the number of items in the stack
 */
int getCount(struct stack stack) {
	return stack.size;
}

/**
 * Remove all element in the stack
 */
void clean(struct stack *stack) {
	if(isEmpty(stack)) {
		return;
	}
	stack->size = 0;
}

/**
 * Create a new stack
 */
struct stack newStack() {
	struct stack tmp;
	tmp.size = 0;
	return tmp; 
}

/**
 * Add an element to the stack
 */
void push(struct stack *stack, int value) {
	if(isFull(stack)) {
		return;
	}
	stack->size++;
	stack->list[stack->size] = value;
}

/**
 * Remove an element to the stack
 */
int pop(struct stack *stack) {
	if(isEmpty(stack)) {
		return;
	}
	int tmp = stack->list[stack->size];
	stack->size--;
	return tmp;
}

/**
 * Display the stack
 */
void display(struct stack *stack) {
	if(isEmpty(stack)) {
		printf("\n** The stack is empty **\n");
		return;
	}
	int i = 1;
	for(; i <= stack->size; ++i) {
		printf("%d\n", stack->list[i]);
	}
}
