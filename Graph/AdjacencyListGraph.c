#include "AdjacencyListGraph.h"

/**
 * Add an edge to the graph from an origin to a destination
 */
int isEmpty(struct adjacencyListGraph *graph) {
	return graph == NULL;
}

/**
 * Check if a graph is full
 */
int isFull(struct adjacencyListGraph *graph) {
	return graph->size == countEdges(graph);
}

/**
 * Count the number of edges for a graph
 */
int countEdges(struct adjacencyListGraph *graph) {
	if(isEmpty(graph)) {
		return 0;
	}
	int i = 0;
	int count = 0;

	for (; i < graph->size; ++i) {
		if (graph->list[i].root != NULL) {
			count++;
		}
	}
	return count;
}

/**
 * Count the number of vertices for an edge
 */
int countVertices(struct adjacencyListGraph *graph, int edge) {
	int count = 0;
	if(isEmpty(graph)) {
		return count;
	}
	int index = getEdgeIndex(graph, edge);
	if(index == -1) {
		return count;
	}

	struct adjacencyListNode *adjListNode = graph->list[index].root;
	while(adjListNode->next != NULL) {
		count++;
		adjListNode = adjListNode->next;
	}
	return count;
}

/**
 * Get the adjacencyList index of the edge
 */
int getEdgeIndex(struct adjacencyListGraph *graph, int edge) {
	int i = 0;
	if(isEmpty(graph)) {
		return -1;
	}
	for (; i < graph->size; ++i) {
		if (graph->list[i].root != NULL && graph->list[i].root->value == edge) {
			return i;
		}
	}
	return -1;
}

/**
 * Get the next available index
 */
int getNextIndex(struct adjacencyListGraph *graph) {
	int i = 0;
	if(isEmpty(graph)) {
		return i;
	}
	for (; i < graph->size; ++i) {
		if (graph->list[i].root == NULL) {
			return i;
		}
	}
	return -1;
}

/**
 * Add an edge to the graph
 */
void addEdge(struct adjacencyListGraph *graph, int value) {
	int indexOrigin = getEdgeIndex(graph, value);

	if(indexOrigin == -1) {
		indexOrigin = getNextIndex(graph);
		if(indexOrigin == -1) {
			// Graph full
			return;
		}
	}

	struct adjacencyListNode *node = createNode(value);
	node->next = graph->list[indexOrigin].root;
	graph->list[indexOrigin].root = node;
}

/**
 * Add a vertex between 2 edges
 */
void addVertex(struct adjacencyListGraph *graph, int origin, int destination) {
	int indexOrigin = getEdgeIndex(graph, origin);
	if(indexOrigin == -1) {
		return;
	}
	int indexDestination = getEdgeIndex(graph, destination);
	if(indexDestination == -1) {
		return;
	}

	struct adjacencyListNode *node = createNode(destination);
	if(graph->list[indexOrigin].root->next == NULL) {
		graph->list[indexOrigin].root->next = node;
		return;
	}
	struct adjacencyListNode *adjListNode = graph->list[indexOrigin].root->next;
	while(adjListNode->next != NULL) {
		adjListNode = adjListNode->next;
	}
	adjListNode->next = node;
}

/**
 * Create a new adjacency list node
 */
struct adjacencyListNode * createNode(int value) {
	struct adjacencyListNode *tmp = malloc(sizeof(struct adjacencyListNode));
	if(tmp == NULL) {
		printf("ERROR: Out of Memory\n");
		exit(EXIT_FAILURE);
	}
	tmp->next = NULL;
	tmp->value = value;
	return tmp;
}

/**
 * Create a new adjacency list graph
 */
struct adjacencyListGraph * createGraph(int size) {

	if(size < 1) {
		printf("ERROR: The size of the graph needs to be at least 1\n");
		return NULL;
	}

	int i = 0;
	struct adjacencyListGraph *tmp = malloc(sizeof(struct adjacencyListGraph));	
	if(tmp == NULL) {
		printf("ERROR: Out of Memory while creating the graph\n");
		exit(EXIT_FAILURE);
	}

	tmp->size = size;

	// Create the adjacency list

	tmp->list = malloc(size * sizeof(struct adjacencyList));
	if(tmp->list == NULL) {
		printf("ERROR: Out of Memory while creating the list\n");
		exit(EXIT_FAILURE);
	}

	for(; i < size; ++i) {
		tmp->list[i].root = NULL;
	}

	return tmp;
}

/**
 * Delete a graph
 */
void deleteGraph(struct adjacencyListGraph **graph) {
	if(!(*graph)) {
		return;
	}

	int i = 0;
	for(; i < (*graph)->size; ++i) {
		if((*graph)->list[i].root == NULL) {
			continue;
		}
		removeEdgeVertices((*graph), (*graph)->list[i].root->value);
	}

	// Free the list first
	free((*graph)->list);

	free(*graph);
	*graph = NULL;
}

/**
 * Remove an edge
 */
void removeEdge(struct adjacencyListGraph *graph, int edge) {
	if(isEmpty(graph)) {
		return;
	}
	int i = 0;
	int index = getEdgeIndex(graph, edge);
	if(index == -1) {
		return;
	}
	for (; i < graph->size; ++i) {
		if(i == index) {
			removeEdgeVertices(graph, graph->list[i].root->value);
		}
		else {
			removeVertex(graph, graph->list[i].root->value, edge);
		}
	}
}

/**
 * Remove all vertices for an edge
 */
void removeEdgeVertices(struct adjacencyListGraph *graph, int edge) {
	if(isEmpty(graph)) {
		return;
	}
	int index = getEdgeIndex(graph, edge);
	if(index == -1) {
		return;
	}
	struct adjacencyListNode *adjListNode = graph->list[index].root;
	while(adjListNode != NULL) {
		struct adjacencyListNode *tmp = adjListNode;
		adjListNode = adjListNode->next;
		free(tmp);
	}
	graph->list[index].root = NULL;
}

/**
 * Remove a vertex from an edge
 */
void removeVertex(struct adjacencyListGraph *graph, int edge, int vertexEdge) {
	if(isEmpty(graph)) {
		return;
	}
	int i = 0;
	int index = getEdgeIndex(graph, edge);
	if(index == -1) {
		return;
	}
	struct adjacencyListNode *previous = NULL;
	struct adjacencyListNode *current = graph->list[index].root;
	for(; current != NULL; previous = current, current = current->next) {
		if(current->value == vertexEdge) {
			if(previous == NULL) {
				graph->list[index].root = current->next;
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
 * Display a graph
 */
void displayGraph(struct adjacencyListGraph *graph) {

	int i = 0;
	if(graph->size == 0) {
		printf("The graph is empty");
		return;
	}

	for(; i < graph->size; ++i) {
		struct adjacencyListNode *node = graph->list[i].root;
		printf("\nItem #%d: ", i);
		while(node != NULL) {
			printf(" %d -", node->value);
			node = node->next;
		}
	}
}
