#include "ShellSort.h"

/**
 * Shell sort
 *
 * Best:	O(n)
 * Worst: O(n²)
 */
void shellSort(int array[], int size) {

	int height = size;
	int i;
	int j;
	int tmp;

	for(;height /= 2;) {
		for (i = height; i < size; i++) {
			tmp = array[i];
			for (j = i; j >= height && tmp < array[j - height]; j -= height) {
				array[j] = array[j - height];
			}
			array[j] = tmp;
		}
	}
}
