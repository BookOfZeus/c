#include "BubbleSort.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUMBER_ITEM 10

/**
 * Get the time differnce in msec (thanks SOF)
 */
float timedifference_msec(struct timeval t0, struct timeval t1) {
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
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

void run_BubbleSort(int array[]) {

   struct timeval t0;
   struct timeval t1;
   float elapsed;

	printf("\n\nTesting BubbleSort:\n  ");

   gettimeofday(&t0, 0);
	bubbleSort(array, NUMBER_ITEM);
   gettimeofday(&t1, 0);

   elapsed = timedifference_msec(t0, t1);

   printf("BubbleSort Code executed in %f milliseconds with:\n  ", elapsed);
	display(array);
}

/**
 * See if this work
 */
void main() {

	int i = 0;
	int array[NUMBER_ITEM];
	int range;
	srand(time(NULL));
	range = ((NUMBER_ITEM * 100) - 1) + 1; 

	for(; i < NUMBER_ITEM; ++i) {
		array[i] = rand() % range + 1;
	}

	printf("\nCurrent Array:\n  ");
	display(array);

	// Bubble Sort
	run_BubbleSort(array);

	//


	printf("\n\n\n");
}

