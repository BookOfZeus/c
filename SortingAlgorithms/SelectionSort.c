#include "SelectionSort.h"

/**
 * Selection Sort: O(n²) algorithm
 *
 * Best:	O(n²)
 * Worst: O(n²)
 */
void selectionSort(int array[], int size) {

	int i = 0;
	int min;
	int j;
	int tmp;

	for (; i < (size - 1); ++i) {
		min = i;
		for (j = i + 1; j < size; ++j) {
			if (array[j] < array[min]) {
				min = j;
			}
		}
		tmp = array[i];
		array[i] = array[min];
		array[min] = tmp;
	}
}
