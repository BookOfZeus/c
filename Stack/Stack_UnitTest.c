#include "../UnitTest.h"
#include "Stack.h"

/**
 */
int test_isEmpty() {
	int valid = 0;
	int empty = 0;
	struct stack stack = newStack();

	empty = isEmpty(&stack);
	valid += assertTrue("test_isEmpty: The stack is empty", empty == 1);

	push(&stack, 1);

	empty = isEmpty(&stack);
	valid += assertTrue("test_isEmpty: The stack is NOT empty", empty == 0);

	clean(&stack);

	empty = isEmpty(&stack);
	valid += assertTrue("test_isEmpty: All element removed", empty == 1);

	return valid;
}

/**
*/
int test_isFull() {
	int valid = 0;
	int full = 0;
	int i = 0;
	struct stack stack = newStack();

	full = isFull(&stack);
	valid += assertTrue("test_isFull: The stack is full", full == 0);

	for(; i < MAX_ELEMENT; ++i) {
		push(&stack, i);
	}

	full = isFull(&stack);
	valid += assertTrue("test_isFull: The stack is full", full == 1);

	return valid;
}

/**
*/
int test_getCount() {
	int valid = 0;
	int count = 0;
	struct stack stack = newStack();

	count = getCount(stack);
	valid += assertTrue("test_getCount: The stack is empty", count == 0);

	push(&stack, 1);
	push(&stack, 10);

	count = getCount(stack);
	valid += assertTrue("test_getCount: The stack is has 2 elements", count == 2);
	
	return valid;
}

/*
*/
int test_clean() {
	int valid = 0;
	int empty = 0;
	struct stack stack = newStack();

	empty = isEmpty(&stack);
	valid += assertTrue("test_isEmpty: The stack is empty", empty == 1);

	push(&stack, 1);
	push(&stack, 10);
	push(&stack, 100);

	clean(&stack);

	empty = isEmpty(&stack);
	valid += assertTrue("test_isEmpty: All element removed", empty == 1);
	return valid;
}

/**
*/
int test_pop() {
	int valid = 0;
	int count = 0;
	int element = 0;
	struct stack stack = newStack();

	push(&stack, 1);
	push(&stack, 10);
	push(&stack, 100);

	count = getCount(stack);
	valid += assertTrue("test_pop: The stack is has 3 elements", count == 3);

	element = pop(&stack);
	valid += assertTrue("test_pop: The pop'ed element is 100", element == 100);

	element = pop(&stack);
	valid += assertTrue("test_pop: The pop'ed element is 10", element == 10);

	count = getCount(stack);
	valid += assertTrue("test_pop: The stack is has 1 elements", count == 1);

	return valid;
}

/**
*/
int test_push() {
	int valid = 0;
	int count = 0;
	struct stack stack = newStack();

	push(&stack, 1);
	push(&stack, 10);
	push(&stack, 100);

	count = getCount(stack);
	valid += assertTrue("test_push: The stack is has 3 elements", count == 3);

	push(&stack, 1000);
	count = getCount(stack);
	valid += assertTrue("test_push: The stack is has 4 elements", count == 4);

	return valid;
}

/* Define UnitTests Lookup functions */

int getNumberTest() {
	return 6;
}

void getUnitTest(UnitTestFunction tests[], char *list[]) {
	int id = 0;

	tests[id]	= test_isEmpty;
	list[id++] = "test_isEmpty";

	tests[id]	= test_isFull;
	list[id++] = "test_isFull";

	tests[id]	= test_getCount;
	list[id++] = "test_getCount";

	tests[id]	= test_clean;
	list[id++] = "test_clean";

	tests[id]	= test_pop;
	list[id++] = "test_pop";

	tests[id]	= test_push;
	list[id++] = "test_push";

}
