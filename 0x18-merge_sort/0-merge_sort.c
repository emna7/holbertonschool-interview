#include "sort.h"

/**
 * merge - merges subarrays
 *
 * @array: array
 * @subarray: subarray
 * @start: start index
 * @mid: middle index
 * @end: end index
 */
void merge(int *array, int *subarray, int start, int mid, int end)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, end - mid);

	for (i = start, j = mid, k = 0; i < mid && j < end; k++)
		if (array[i] < array[j])
			subarray[k] = array[i++];
		else
			subarray[k] = array[j++];
	while (i < mid)
		subarray[k++] = array[i++];
	while (j < end)
		subarray[k++] = array[j++];
	for (i = start, k = 0; i < end; i++)
		array[i] = subarray[k++];

	printf("[Done]: ");
	print_array(array + start, end - start);
}

/**
 * split_sort - splits array
 *
 * @array: array
 * @subarray: subarray
 * @start: start index
 * @end: end index
 */
void split_sort(int *array, int *subarray, int start, int end)
{
	int mid;

	if (end - start > 1)
	{
		mid = (end - start) / 2 + start;
		split_sort(array, subarray, start, mid);
		split_sort(array, subarray, mid, end);
		merge(array, subarray, start, mid, end);
	};
}

/**
 * merge_sort - sorts array using "Merge sort"
 *
 * @array: array
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *subarray;

	subarray = malloc(sizeof(int) * size);
	split_sort(array, subarray, 0, size);
	free(subarray);
}
