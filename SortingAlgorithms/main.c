#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "ShellSort.h"
#include "QuickSort.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUMBER_ITEM 10000
#define SHOW_ARRAYS 0

/**
 * Get the time differnce in msec (thanks SOF)
 */
float timedifference_msec(struct timeval t0, struct timeval t1) {
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

/**
 * Randomize Array
 */
void randomizeArray(int array[]) {

	int i = 0;
	int range;
	srand(time(NULL));
	range = ((NUMBER_ITEM * 100) - 1) + 1; 

	for(; i < NUMBER_ITEM; ++i) {
		array[i] = rand() % range + 1;
	}
}

/**
 * Swap 2 numbers in an array
 */
void swap(int array[], int a, int b) {
  int tmp = array[a];
  array[a] = array[b];
  array[b] = tmp;
}

/**
 * Display first in last out
 */
void display(int array[]) {

	int i = 0;

	for(; i < NUMBER_ITEM; ++i) {
		printf("%d ", array[i]);
	}
}

/**
 * Bubble Sort
 */
void run_BubbleSort(int array[]) {

  struct timeval t0;
  struct timeval t1;
  float timeSpent = 0;

  printf("\n\nTesting BubbleSort:\n");
  if(SHOW_ARRAYS == 1) {
    printf("  Current Array: ");
    display(array);
  }

  gettimeofday(&t0, 0);
  bubbleSort(array, NUMBER_ITEM);
  gettimeofday(&t1, 0);
  timeSpent = timedifference_msec(t0, t1);

  if(SHOW_ARRAYS == 1) {
    printf("\n  After Sort: ");
    display(array);
  }
  printf("\n  Sort executed in %f milliseconds with:\n  ", timeSpent);
}

/**
 * Selection Sort
 */
float run_SelectionSort(int array[]) {

  struct timeval t0;
  struct timeval t1;
  float timeSpent = 0;

  printf("\n\nTesting SelectionSort:\n");
  if(SHOW_ARRAYS == 1) {
    printf("  Current Array: ");
    display(array);
  }

  gettimeofday(&t0, 0);
  selectionSort(array, NUMBER_ITEM);
  gettimeofday(&t1, 0);
  timeSpent = timedifference_msec(t0, t1);

  if(SHOW_ARRAYS == 1) {
    printf("\n  After Sort: ");
    display(array);
  }
  printf("\n  Sort executed in %f milliseconds with:\n  ", timeSpent);
}

/**
 * Insertion Sort
 */
float run_InsertionSort(int array[]) {

  struct timeval t0;
  struct timeval t1;
  float timeSpent = 0;

  printf("\n\nTesting InsertionSort:\n");
  if(SHOW_ARRAYS == 1) {
    printf("  Current Array: ");
    display(array);
  }

  gettimeofday(&t0, 0);
  insertionSort(array, NUMBER_ITEM);
  gettimeofday(&t1, 0);
  timeSpent = timedifference_msec(t0, t1);

  if(SHOW_ARRAYS == 1) {
    printf("\n  After Sort: ");
    display(array);
  }
  printf("\n  Sort executed in %f milliseconds with:\n  ", timeSpent);
}

/**
 * Merge Sort
 */
float run_MergeSort(int array[]) {

  struct timeval t0;
  struct timeval t1;
  float timeSpent = 0;

  printf("\n\nTesting Merge Sort:\n");
  if(SHOW_ARRAYS == 1) {
    printf("  Current Array: ");
    display(array);
  }

  gettimeofday(&t0, 0);
  mergeSort(array, NUMBER_ITEM);
  gettimeofday(&t1, 0);
  timeSpent = timedifference_msec(t0, t1);

  if(SHOW_ARRAYS == 1) {
    printf("\n  After Sort: ");
    display(array);
  }
  printf("\n  Sort executed in %f milliseconds with:\n  ", timeSpent);

}

/**
 * Shell Sort
 */
float run_ShellSort(int array[]) {

  struct timeval t0;
  struct timeval t1;
  float timeSpent = 0;

  printf("\n\nTesting Shell Sort:\n");
  if(SHOW_ARRAYS == 1) {
    printf("  Current Array: ");
    display(array);
  }

  gettimeofday(&t0, 0);
  shellSort(array, NUMBER_ITEM);
  gettimeofday(&t1, 0);
  timeSpent = timedifference_msec(t0, t1);

  if(SHOW_ARRAYS == 1) {
    printf("\n  After Sort: ");
    display(array);
  }
  printf("\n  Sort executed in %f milliseconds with:\n  ", timeSpent);
}

/**
 * Heap Sort
 */
float run_HeapSort(int array[]) {

  struct timeval t0;
  struct timeval t1;
  float timeSpent = 0;

  printf("\n\nTesting Heap Sort:\n");
  if(SHOW_ARRAYS == 1) {
    printf("  Current Array: ");
    display(array);
  }

  gettimeofday(&t0, 0);
  heapSort(array, NUMBER_ITEM);
  gettimeofday(&t1, 0);
  timeSpent = timedifference_msec(t0, t1);

  if(SHOW_ARRAYS == 1) {
    printf("\n  After Sort: ");
    display(array);
  }
  printf("\n  Sort executed in %f milliseconds with:\n  ", timeSpent);
}

/**
 * Quick Sort
 */
float run_QuickSort(int array[]) {

  struct timeval t0;
  struct timeval t1;
  float timeSpent = 0;

  printf("\n\nTesting Quick Sort:\n");
  if(SHOW_ARRAYS == 1) {
    printf("  Current Array: ");
    display(array);
  }

  gettimeofday(&t0, 0);
  quickSort(array, NUMBER_ITEM);
  gettimeofday(&t1, 0);
  timeSpent = timedifference_msec(t0, t1);

  if(SHOW_ARRAYS == 1) {
    printf("\n  After Sort: ");
    display(array);
  }
  printf("\n  Sort executed in %f milliseconds with:\n  ", timeSpent);
}

/**
 * See if this work
 */
void main() {

	int array[NUMBER_ITEM];

	// Bubble Sort
  randomizeArray(array);
	run_BubbleSort(array);

	// Selection Sort
  randomizeArray(array);
	run_SelectionSort(array);

	// Insertion Sort
  randomizeArray(array);
	run_InsertionSort(array);

	// Merge Sort
  randomizeArray(array);
	run_MergeSort(array);

	// Shell Sort
  randomizeArray(array);
	run_ShellSort(array);

	// Heap Sort
  randomizeArray(array);
	run_HeapSort(array);

	// Quick Sort
  randomizeArray(array);
	run_QuickSort(array);

  printf("\n\n\n");
}

