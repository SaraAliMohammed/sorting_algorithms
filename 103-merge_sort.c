#include "sort.h"
/**
 * merge_compare_arrays - merges the arrays with compare integers.
 * @array: The array will be sorted.
 * @start: The start index.
 * @end: The end index.
 * @new_arr: The new array of integers.
 *
 * Return: Nothing.
 */
void merge_compare_arrays(int *array, size_t start, size_t end, int *new_arr)
{
	size_t i = start, middle = (start + end) / 2, j = middle, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, middle - start);
	printf("[right]: ");
	print_array(array + middle, end - middle);
	for (k = start; k < end; k++)
		if (i < middle && (j >= end || array[i] < array[j]))
			new_arr[k] = array[i++];
		else
			new_arr[k] = array[j++];
	printf("[Done]: ");
	print_array(new_arr + start, end - start);
}

/**
 * top_down_mege_sort - implements the top-down merge
 *sort algorithm.
 * @array: The array will be sorted.
 * @start: The start index.
 * @end: The end index.
 * @new_arr: The new array of integers.
 *
 * Return: Nothing.
 */
void top_down_mege_sort(int *array, size_t start, size_t end, int *new_arr)
{
	size_t middle;

	middle = (start + end) / 2;
	if (end - start < 2)
		return;
	top_down_mege_sort(new_arr, start, middle, array);
	top_down_mege_sort(new_arr, middle, end, array);
	merge_compare_arrays(array, start, end, new_arr);
}

/**
 * merge_sort - sorts an array of integers in
 *ascending order using the Merge sort algorithm.
 * @array: The array will be sorted.
 * @size: The size of array.
 *
 * Return: Nothing.
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *new_arr;

	if (!array || size < 2)
		return;
	new_arr = malloc(sizeof(int) *  size);
	if (!new_arr)
		return;
	for (i = 0; i < size; i++)
		new_arr[i] = array[i];
	top_down_mege_sort(new_arr, 0, size, array);
	free(new_arr);
}
