#include "BinaryTree.h"
#include "UnitTest.h"

/* Define UnitTests */

/**
 * Test if a node is removed.
 */
static char * test_deleteTree() {

	int height = 0;
	struct treeNode *root = NULL;

	root		= createNode(4);
	root->left	= createNode(2);
	root->right	= createNode(6);

	height = getHeight(&root);
	mu_assert("* Error: wrong height", height == 2);

	deleteNode(&root);

	height = getHeight(&root);
	mu_assert("* Error: wrong height", height == 0);

	return 0;
}

/**
 * Add a node to a tree
 */
static char * test_addNode() {
	int height = 0;
	int perfect = 0;

	struct treeNode *root = NULL;

	addNode(&root, createNode(1));
	addNode(&root, createNode(5));
	addNode(&root, createNode(2));
	addNode(&root, createNode(9));
	addNode(&root, createNode(3));

	height = getHeight(&root);
	mu_assert("* Error: wrong height", height == 4);

	perfect = isPerfect(&root);
	mu_assert("error: tree is NOT perfect", perfect == 0);

	// Free memory
	deleteNode(&root);

	return 0;
}

/**
 * Test if the tree is perfect
 * eg:
 *      1
 *     / \
 *    /   \
 *   2     3
 *  / \   / \
 * 4   5 6   7
 *
 */
static char * test_isPerfect() {
	int perfect = 0;
	struct treeNode *root = NULL;

	root		= createNode(1);
	root->left	= createNode(2);
	root->right	= createNode(3);
	root->left->left	= createNode(4);
	root->left->right	= createNode(5);
	root->right->left	= createNode(6);
	root->right->right	= createNode(7);

	perfect = isPerfect(&root);
	mu_assert("error: tree is perfect", perfect == 1);

	// Free memory
	deleteNode(&root);

	// Try a "not perfect" tree

	root		= createNode(4);
	root->left	= createNode(2);
	root->right	= NULL;
	root->left->left	= createNode(1);
	root->left->right	= NULL;

	perfect = isPerfect(&root);
	mu_assert("error: tree is not perfect", perfect == 0);

	// Free memory
	deleteNode(&root);

	return 0;
}

/**
 * Test if the tree is full
 * eg:
 *      1
 *     / \
 *    /   \
 *   2     3
 *  / \
 * 4   5
 *
 */
static char * test_isFull() {
	int full = 0;
	struct treeNode *root = NULL;

	root		= createNode(1);
	root->left	= createNode(2);
	root->right	= createNode(3);
	root->left->left	= createNode(4);
	root->left->right	= createNode(5);

	full = isFull(&root);
	mu_assert("error: tree is full", full == 1);

	// Free memory
	deleteNode(&root);

	return 0;
}

/**
 * Test if a node exists in a tree
 */
static char * test_exists() {

	struct treeNode *root = NULL;

	root		= createNode(182);
	root->left	= createNode(2);
	root->right	= createNode(59);
	root->left->left	= createNode(165);
	root->left->right	= createNode(73);
	root->right->left	= createNode(42);
	root->right->right	= createNode(651);

	mu_assert("error: 2 IS in the tree", exists(&root, 2));

	mu_assert("error: 99 IS in the tree", !exists(&root, 99));

	// Free memory
	deleteNode(&root);
	return 0;
}

/**
 * Test all 
 */
static char * all_tests() {
	printf("\nStarting tests:\n");

	printf(" testing test_addNode()\n");
	mu_run_test(test_addNode);

	printf(" testing test_deleteTree()\n");
	mu_run_test(test_deleteTree);

	printf(" testing test_isPerfect()\n");
	mu_run_test(test_isPerfect);

	printf(" testing test_isFull()\n");
	mu_run_test(test_isFull);

	printf(" testing test_exists()\n");
	mu_run_test(test_exists);

	return 0;
}

/******************************************************
 Start the Engine 
******************************************************/

int main() {

	char *result = all_tests();
	if (result != 0) {
		printf("%s\n", result);
	}
	else {
		printf("\nALL TESTS PASSED\n");
	}
	printf("Tests run: %d\n", tests_run);
	return result != 0;
}
