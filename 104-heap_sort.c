#include "sort.h"
#define parent(x) (((x) - 1) / 2)
#define left_child(x) (((x) * 2) + 1)

/**
 * swap - Swap two integers in an array.
 * @a: The first integer.
 * @b: The second integer.
 * @array: The array of integers.
 * @size: The size of the array.
 *
 * Return: Nothing.
 */
void swap(int *array, size_t size, int *a, int *b)
{
	int temp;

	if (*a != *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
	print_array((const int *) array, size);
}

/**
 * sift_down - sift down implementation.
 * @array: The array of integers.
 * @size: The size of the array.
 * @start: The start index.
 * @stop: The stop index.
 *
 * Return: Nothing.
 */
void sift_down(int *array, size_t size, size_t start, size_t stop)
{
	size_t root = start, temp, child;

	while (left_child(root) <= stop)
	{
		child = left_child(root);
		temp = root;
		if (array[child] > array[temp])
			temp = child;
		if (child + 1 <= stop && array[child + 1] > array[temp])
			temp = child + 1;
		if (temp == root)
			return;
		swap(array, size, &array[root], &array[temp]);
		root = temp;
	}
}

/**
 * heap - makes heap.
 * @array: The array of integers.
 * @size: The size of the array.
 *
 * Return: Nothing.
 */
void heap(int *array, size_t size)
{
	ssize_t start;

	for (start = parent(size - 1); start >= 0; start--)
		sift_down(array, size, start, size - 1);
}

/**
 * heap_sort - sorts an array of integers in ascending
 *order using the Heap sort algorithm.
 * @array: The array of integers.
 * @size: The size of the array.
 *
 * Return: Nothing.
 */
void heap_sort(int *array, size_t size)
{
	size_t stop;

	if (!array || !size)
		return;
	heap(array, size);
	stop = size - 1;
	while (stop > 0)
	{
		swap(array, size, &array[stop], &array[0]);
		stop--;
		sift_down(array, size, 0, stop);
	}
}
