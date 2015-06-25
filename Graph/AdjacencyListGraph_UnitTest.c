#include "../UnitTest.h"
#include "AdjacencyListGraph.h"

/**
 */
int test_isEmpty() {
	int valid = 0;
	int empty = 0;
	struct adjacencyListGraph *graph = NULL;

	graph = createGraph(1);
	addEdge(graph, 0);
	valid += assertTrue("test_isEmpty: The graph is not empty", empty == 0);

	deleteGraph(&graph);

	empty = isEmpty(graph);
	valid += assertTrue("test_isEmpty: The graph is empty", empty == 1);
	return valid;
}

/**
 */
int test_isFull() {
	int valid = 0;
	int full = 0;
	struct adjacencyListGraph *graph = NULL;

	graph = createGraph(2);
	addEdge(graph, 0);
	full = isFull(graph);
	valid += assertTrue("test_isFull: The graph is not full", full == 0);

	addEdge(graph, 1);
	full = isFull(graph);
	valid += assertTrue("test_isFull: The graph is not full", full == 1);

	addEdge(graph, 3);
	full = isFull(graph);
	valid += assertTrue("test_isFull: The graph is full", full == 1);

	deleteGraph(&graph);
	return valid;
}

/**
 */
int test_countEdges() {
	int valid = 0;
	int count = 0;
	struct adjacencyListGraph *graph = NULL;

	count = countEdges(graph);
	valid += assertTrue("test_countEdges: The graph has no edges", count == 0);

	graph = createGraph(3);

	addEdge(graph, 17);
	count = countEdges(graph);
	valid += assertTrue("test_countEdges: The graph has 1 edge", count == 1);

	addEdge(graph, 51);
	addEdge(graph, 23);
	count = countEdges(graph);
	valid += assertTrue("test_countEdges: The graph has 3 edge", count == 3);

	deleteGraph(&graph);
	return valid;
}

/**
 */
int test_countVertices() {
	int valid = 0;
	int count = 0;
	struct adjacencyListGraph *graph = NULL;

	graph = createGraph(3);
	addEdge(graph, 17);
	addEdge(graph, 51);
	addEdge(graph, 23);

	addVertex(graph, 17, 51);
	
	count = countVertices(graph, 17);
	valid += assertTrue("test_countVertices: The graph has 1 vertex", count == 1);

	addVertex(graph, 17, 23);
	addVertex(graph, 17, 66);

	count = countVertices(graph, 17);
	valid += assertTrue("test_countVertices: The graph has 2 vertices", count == 2);

	count = countVertices(graph, 100);
	valid += assertTrue("test_countVertices: The graph has no vertices", count == 0);

	deleteGraph(&graph);
	return valid;
}

/**
 */
int test_getEdgeIndex() {
	int valid = 0;
	int index = -1;
	struct adjacencyListGraph *graph = NULL;

	graph = createGraph(3);

	addEdge(graph, 12);
	addEdge(graph, 24);
	addEdge(graph, 48);

	index = getEdgeIndex(graph, 10);
	valid += assertTrue("test_getEdgeIndex: The index of 10 is -1", index == -1);

	index = getEdgeIndex(graph, 12);
	valid += assertTrue("test_getEdgeIndex: The index of 12 is 0", index == 0);

	index = getEdgeIndex(graph, 24);
	valid += assertTrue("test_getEdgeIndex: The index of 24 is 1", index == 1);

	index = getEdgeIndex(graph, 48);
	valid += assertTrue("test_getEdgeIndex: The index of 48 is 2", index == 2);

	deleteGraph(&graph);
	return valid;
}

/**
 */
int test_getNextIndex() {
	int valid = 0;
	int index = -1;
	struct adjacencyListGraph *graph = NULL;

	graph = createGraph(3);
	index = getNextIndex(graph);
	valid += assertTrue("test_getNextIndex: The next index is 0", index == 0);

	addEdge(graph, 12);
	index = getNextIndex(graph);
	valid += assertTrue("test_getNextIndex: The next index is 1", index == 1);

	addEdge(graph, 24);
	addEdge(graph, 48);

	index = getNextIndex(graph);
	valid += assertTrue("test_getNextIndex: The graph is full1", index == -1);

	deleteGraph(&graph);
	return valid;
}

/**
 */
int test_addEdge() {
	int valid = 0;
	int count = 0;
	int index = -1;
	int full = 0;
	struct adjacencyListGraph *graph = NULL;
	
	graph = createGraph(3);
	addEdge(graph, 17);
	addEdge(graph, 21);

	// test index
	index = getEdgeIndex(graph, 22);
	valid += assertTrue("test_addEdge: The index of 22 is -1", index == -1);

	// Add one more
	addEdge(graph, 22);

	// test index
	index = getEdgeIndex(graph, 17);
	valid += assertTrue("test_addEdge: The index of 17 is 0", index == 0);

	index = getEdgeIndex(graph, 21);
	valid += assertTrue("test_addEdge: The index of 17 is 1", index == 1);

	index = getEdgeIndex(graph, 212);
	valid += assertTrue("test_addEdge: The index of 17 is -1", index == -1);

	// Is full?
	full = isFull(graph);
	valid += assertTrue("test_addEdge: The graph is full", full == 1);

	deleteGraph(&graph);

	return valid;
}

/**
 */
int test_addVertex() {
	int valid = 0;
	int count = 0;
	struct adjacencyListGraph *graph = NULL;

	graph = createGraph(4);
	addEdge(graph, 17);
	addEdge(graph, 71);
	addEdge(graph, 42);
	addEdge(graph, 99);

	addVertex(graph, 17, 71);
	addVertex(graph, 17, 42);

	count = countVertices(graph, 17);
	valid += assertTrue("test_addVertex: The number of vertices for 17 is 2", count == 2);

	addVertex(graph, 17, 99);

	count = countVertices(graph, 17);
	valid += assertTrue("test_addVertex: The number of vertices for 17 is 3", count == 3);

	deleteGraph(&graph);
	return valid;
}

int test_removeEdge() {
	int valid = 0;
	int count = 0;
	struct adjacencyListGraph *graph = NULL;

	graph = createGraph(4);
	addEdge(graph, 10);
	addEdge(graph, 20);
	addEdge(graph, 30);
	addEdge(graph, 40);

	addVertex(graph, 10, 20);
	addVertex(graph, 10, 30);
	addVertex(graph, 10, 40);

	removeEdge(graph, 10);

	count = countEdges(graph);
	valid += assertTrue("test_removeEdge: The number of edges is 3", count == 3);

	deleteGraph(&graph);
	return valid;
}

/**
 */
int test_removeEdgeVertices() {
	int valid = 0;
	int count = 0;
	struct adjacencyListGraph *graph = NULL;

	graph = createGraph(2);
	addEdge(graph, 10);
	addEdge(graph, 20);

	count = countVertices(graph, 10);
	valid += assertTrue("test_removeEdgeVertices: The number of vertices for 10 is 0", count == 0);

	addVertex(graph, 10, 20);

	count = countVertices(graph, 10);
	valid += assertTrue("test_removeEdgeVertices: The number of vertices for 10 is 1", count == 1);

	removeEdgeVertices(graph, 10);

	count = countVertices(graph, 10);
	valid += assertTrue("test_removeEdgeVertices: The number of vertices for 10 is 0", count == 0);

	deleteGraph(&graph);
	return valid;
}

/**
 */
int test_removeVertex() {
	int valid = 0;
	int count = 0;
	struct adjacencyListGraph *graph = NULL;

	graph = createGraph(4);
	addEdge(graph, 10);
	addEdge(graph, 20);
	addEdge(graph, 30);
	addEdge(graph, 40);

	addVertex(graph, 10, 20);
	addVertex(graph, 10, 30);
	addVertex(graph, 10, 40);

	removeVertex(graph, 10, 30);

	count = countVertices(graph, 10);
	valid += assertTrue("test_removeVertex: The number of vertices for 10 is 2", count == 2);

	removeVertex(graph, 10, 50);

	count = countVertices(graph, 10);
	valid += assertTrue("test_removeVertex: The number of vertices for 10 is 2", count == 2);

	deleteGraph(&graph);
	return valid;
}

int getNumberTest() {
	return 11;
}

void getUnitTest(UnitTestFunction tests[], char *list[])
{
	int id = 0;

	tests[id]	= test_isEmpty;
	list[id++] = "test_isEmpty";

	tests[id]	= test_isFull;
	list[id++] = "test_isFull";

	tests[id]	= test_countEdges;
	list[id++] = "test_countEdges";

	tests[id]	= test_countVertices;
	list[id++] = "test_countVertices";

	tests[id]	= test_getEdgeIndex;
	list[id++] = "test_getEdgeIndex";

	tests[id]	= test_getNextIndex;
	list[id++] = "test_getNextIndex";

	tests[id]	= test_addEdge;
	list[id++] = "test_addEdge";

	tests[id]	= test_addVertex;
	list[id++] = "test_addvertex";

	tests[id]	= test_removeEdge;
	list[id++] = "test_removeEdge";

	tests[id]	= test_removeEdgeVertices;
	list[id++] = "test_removeEdgeVertices";

	tests[id]	= test_removeVertex;
	list[id++] = "test_removeVertex";
}
