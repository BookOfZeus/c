#include "QuickSort.h"

/**
 * Quick sort
 *
 * Best:	O(n*log(n))
 * Worst: O(n²)
 */
void quickSort(int array[], int size) {

	int i = 0;
	int j = size - 1;
	int median;

	if (size < 2) {
		return;
	}
	median = array[size / 2];
	for (;; i++, j--) {
		while (array[i] < median) {
			i++;
		}
		while (median < array[j]) {
			j--;
		}
		if (i >= j) {
			break;
		}
		swap(array, i, j);
	}
	quickSort(array, i);
	quickSort(array + i, size - i);
}

