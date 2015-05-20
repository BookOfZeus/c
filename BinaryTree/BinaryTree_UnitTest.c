#include "../UnitTest.h"
#include "BinaryTree.h"

/**
 */
int test_exists() {
	int valid = 0;
	struct treeNode *root = NULL;

	root		= createNode(182);
	root->left	= createNode(2);
	root->right	= createNode(59);
	root->left->left	= createNode(165);
	root->left->right	= createNode(73);
	root->right->left	= createNode(42);
	root->right->right	= createNode(651);

	valid += assertTrue("error: 2 IS in the tree", exists(&root, 2));

	valid += assertTrue("error: 99 IS in the tree", !exists(&root, 99));

	// Free memory
	deleteNode(&root);

	return valid;
}

/**
 */
int test_search() {
	int valid = 0;
	struct treeNode *root = NULL;
	struct treeNode *node = NULL;

	root		= createNode(36);
	root->left	= createNode(20);
	root->right	= createNode(59);
	root->left->left	= createNode(1);
	root->left->right	= createNode(30);
	root->right->left	= createNode(42);
	root->right->right	= createNode(651);

	node = search(root, 42);
	valid += assertTrue("error: node is null", node != NULL);
	valid += assertTrue("error: Search fail for value 42", node->value == 42);

	node = search(root, 5151);
	valid += assertTrue("error: node is not null", node == NULL);

	// Free memory
	deleteNode(&root);
	return valid;
}

/**
 * Test if the tree is balanced
 * eg:
 *      8
 *     / \
 *    /   \
 *   4     9
 *  / \
 * 1   6
 *
 */
int test_isBalanced() {
	int valid = 0;
	int balanced = 0;
	struct treeNode *root = NULL;

	root		= createNode(8);
	root->left	= createNode(4);
	root->right	= createNode(9);
	root->left->left	= createNode(1);
	root->left->right	= createNode(6);

	balanced = isBalanced(&root);
	valid += assertTrue("error: tree is balanced", balanced == 1);

	// Free memory
	deleteNode(&root);

	// Not balanced

	root		= createNode(1);
	root->left	= createNode(4);
	root->right	= createNode(9);
	root->left->left	= createNode(1);
	root->left->right	= createNode(6);

	balanced = isBalanced(&root);
	valid += assertTrue("error: tree is not balanced", balanced == 0);

	// Free memory
	deleteNode(&root);

	return valid;
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
int test_isFull() {
	int valid = 0;
	int full = 0;
	struct treeNode *root = NULL;

	root		= createNode(1);
	root->left	= createNode(2);
	root->right	= createNode(3);
	root->left->left	= createNode(4);
	root->left->right	= createNode(5);

	full = isFull(&root);
	valid += assertTrue("error: tree is full", full == 1);

	// Free memory
	deleteNode(&root);

	return valid;
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
int test_isPerfect() {
	int valid = 0;
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
	valid += assertTrue("error: tree is perfect", perfect == 1);

	// Free memory
	deleteNode(&root);

	// Try a "not perfect" tree

	root		= createNode(4);
	root->left	= createNode(2);
	root->right	= NULL;
	root->left->left	= createNode(1);
	root->left->right	= NULL;

	perfect = isPerfect(&root);
	valid += assertTrue("error: tree is not perfect", perfect == 0);

	// Free memory
	deleteNode(&root);

	return valid;
}

/**
 */
int test_addNode() {
	int valid = 0;
	int height = 0;
	int perfect = 0;

	struct treeNode *root = NULL;

	addNode(&root, createNode(1));
	addNode(&root, createNode(5));
	addNode(&root, createNode(2));
	addNode(&root, createNode(9));
	addNode(&root, createNode(3));

	height = getHeight(&root);
	valid += assertTrue("* Error: wrong height", height == 4);

	perfect = isPerfect(&root);
	valid += assertTrue("error: tree is NOT perfect", perfect == 0);

	// Free memory
	deleteNode(&root);

	return valid;
}

/**
 */
int test_deleteTree() {
	int valid = 0;
	int height = 0;
	struct treeNode *root = NULL;

	root		= createNode(4);
	root->left	= createNode(2);
	root->right	= createNode(6);

	height = getHeight(&root);
	valid += assertTrue("* Error: wrong height", height == 2);

	deleteNode(&root);

	height = getHeight(&root);
	valid += assertTrue("* Error: wrong height", height == 0);

	return valid;
}

/* Define UnitTests Lookup functions */

int getNumberTest() {
	return 7;
}

void getUnitTest(UnitTestFunction tests[], char *list[])
{
	int id = 0;

	tests[id]  = test_exists;
	list[id++] = "test_exists";

	tests[id]  = test_search;
	list[id++] = "test_search";

	tests[id]  = test_isBalanced;
	list[id++] = "test_isBalanced";

	tests[id]  = test_isFull;
	list[id++] = "test_isFull";

	tests[id]  = test_isPerfect;
	list[id++] = "test_isPerfect";

	tests[id]  = test_addNode;
	list[id++] = "test_addNode";

	tests[id]  = test_deleteTree;
	list[id++] = "test_deleteTree";
}
