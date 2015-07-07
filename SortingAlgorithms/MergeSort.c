#include "MergeSort.h"

/**
 * Merge sort
 *
 * Best:	O(n*log(n))
 * Worst: O(n*log(n))
 */
void mergeSort(int array[], int size) {

	if(size < 2) {
		return;
	}

	int median = size / 2;
	int i = 0;

	int leftArray[median];
	int rightArray[median + 1];

	for(; i < median; ++i) {
		leftArray[i] = array[i];
	}
	i = median;
	for(; i < size; ++i) {
		rightArray[i - median] = array[i];
	} 
	mergeSort(leftArray, median);
	mergeSort(rightArray, size - median);
	mergeArray(array, leftArray, rightArray, median, size - median);
}

/**
 * Merge arrays
 */
void mergeArray(int array[], int leftArray[], int rightArray[], int maxLeft, int maxRight) {

	int i = 0;
	int j = 0;
	int k = 0;

	while( i < maxLeft && j < maxRight) {
		if(leftArray[i] < rightArray[j]) {
			array[k++] = leftArray[i++];
		}
		else {
			array[k++] = rightArray[j++];
		}
	}
	while(i < maxLeft) {
		array[k++] = leftArray[i++];
	}
	while(j < maxRight) {
		array[k++] = rightArray[j++];
	}
}

