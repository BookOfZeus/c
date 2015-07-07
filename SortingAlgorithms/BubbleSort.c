#include "BubbleSort.h"

/**
 * Bubble sort
 *
 * Best:  O(n)
 * Worst: O(n²)
 */
void bubbleSort(int array[], int size) {

	int i = 0;
	int j;
	int tmp = 0;

	for(; i < (size - 1); ++i) {
		for(j = 0; j < (size - 1 - i); ++j) {
			if(array[j] > array[(j + 1)]) {
				tmp = array[(j + 1)];
				array[(j + 1)] = array[j];
				array[j] = tmp;
			}
		}
	}
}
