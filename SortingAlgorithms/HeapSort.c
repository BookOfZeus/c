#include "HeapSort.h"

/**
 * Heap sort
 *
 * Best:	O(n*log(n))
 * Worst: O(n*log(n))
 */
void heapSort(int array[], int size) {

	int i = (size - 2) / 2;
	int j = size - 1;

	for(; i >= 0; --i) {
		siftDown(array, i, size);
	}
	for(; j > 0; --j) {
		swap(array, j, 0);
		siftDown(array, 0, j);
	}
}

/**
 * SiftDown: O(n)
 */
void siftDown(int array[], int start, int end) {

	int root = start;
	int node;

	while(root * 2 + 1 < end) {
		node = 2 * root + 1;
		if(node + 1 < end && array[node] < array[node + 1]) {
			node += 1;
		}
		if(array[root] < array[node]) {
			swap(array, node, root);
			root = node;
		}
		else {
			return;
		}
	}
}

/**
 * SiftUp: O(n*log(n)))
 */
void siftUp(int array[], int start, int end) {
	// Not implemented for this example
}
