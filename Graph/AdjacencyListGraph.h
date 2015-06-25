#include <stdlib.h>
#include <stdio.h>

/**
 * Define the graph elements
 */
typedef struct adjacencyListNode {
	int value;
	struct adjacencyListNode *next;
} adjacencyListNode;

typedef struct adjacencyList {
	struct adjacencyListNode *root;
} adjacencyList;

typedef struct adjacencyListGraph {
	int size;
	struct adjacencyList *list;
} adjacencyListGraph;

//
// Lookup
//

int isEmpty(struct adjacencyListGraph *graph);

int isFull(struct adjacencyListGraph *graph);

int countEdges(struct adjacencyListGraph *graph);

int countVertices(struct adjacencyListGraph *graph, int edge);

int getEdgeIndex(struct adjacencyListGraph *graph, int edge);

int getNextIndex(struct adjacencyListGraph *graph);

//
// CRUD functions
//

void addEdge(struct adjacencyListGraph *graph, int value);

void addVertex(struct adjacencyListGraph *graph, int origin, int destination);

struct adjacencyListNode * createNode(int value);

struct adjacencyListGraph * createGraph(int size);

void deleteGraph(struct adjacencyListGraph **graph);

void removeEdge(struct adjacencyListGraph *graph, int edge);

void removeEdgeVertices(struct adjacencyListGraph *graph, int edge);

void removeVertex(struct adjacencyListGraph *graph, int edge, int vertexEdge);

//
// Output
//

void displayGraph(struct adjacencyListGraph *graph);

