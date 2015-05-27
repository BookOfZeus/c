#include <stdlib.h>
#include <stdio.h>

#define MAX_ELEMENT 10

/**
 * Define the basic node
 */
struct stack {
	int size;
	int list[MAX_ELEMENT];
};

//
// Lookup functions
//

int isEmpty(struct stack *stack);

int isFull(struct stack *stack);

int getCount(struct stack stack);

//
// CRUD functions
//

void clean(struct stack *stack);

struct stack newStack(void);

int pop(struct stack *stack);

void push(struct stack *stack, int value);

//
// Output
//

void display(struct stack *stack);
