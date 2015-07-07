#include "InsertionSort.h"

/**
 * Insertion Sort: O(n²) algorithm
 *
 * Best:  O(n)
 * Worst: O(n²)
 */
void insertionSort(int array[], int size) {

  int i = 1;
  int j;
  int index;

  for (; i < size; ++i) {
    index = array[i];
    j = i;
    while (j > 0 && array[j-1] > index) {
      array[j] = array[j-1];
      j--;
    }
    array[j] = index;
  }
}
