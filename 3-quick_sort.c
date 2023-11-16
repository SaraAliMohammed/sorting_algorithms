#include "sort.h"

/**
 * swap - Swap two integers in an array.
 * @a: The first integer.
 * @b: The second integer.
 * @array: The array of integers.
 * @size: The size of the array.
 */
void swap(int *array, size_t size, int *a, int *b)
{
	int temp;

	if (*a != *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
		print_array((const int *) array, size);
	}
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *the lomuto partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @low: The first index.
 * @high: The last index.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, ssize_t low, ssize_t high)
{
	int i, j, pivot = array[high];

	for (i = j = low; j < high; j++)
		if (array[j] < pivot)
			swap(array, size, &array[j], &array[i++]);
	swap(array, size, &array[i], &array[high]);
	return (i);
}

/**
 * quicksort - Sorts an array.
 * @array: The array of integers.
 * @size: The size of the array.
 * @low: The first index.
 * @high: The last index.
 *
 * Return: Nothing.
 */
void quicksort(int *array, size_t size, ssize_t low, ssize_t high)
{
	ssize_t pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, size, low, high);
		quicksort(array, size, low, pivot - 1);
		quicksort(array, size, pivot + 1, high);
	}
}

/**
 * quick_sort - swaps two nodes of a doubly linked list.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort(array, size, 0, size - 1);
}
