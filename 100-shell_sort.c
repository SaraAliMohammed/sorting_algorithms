#include "sort.h"

/**
 * gap_max - gets the maximmum gap numbebr.
 * @size: The size of array.
 *
 * Return: The gap number.
 */
size_t gap_max(size_t size)
{
	size_t gap = 1;

	while (gap < size)
		gap = gap * 3 + 1;
	return ((gap - 1) / 3);
}

/**
 * shell_sort - sorts an array of integers in
 *ascending order using the Shell sort algorithm,
 *using the Knuth sequence.
 * @array: The array will be sorted.
 * @size: The size of array.
 *
 * Return: Nothing.
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap;
	int tmp;

	if (!array || !size)
		return;
	gap = gap_max(size);
	for (gap; gap; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j > gap - 1 && tmp < array[j - gap]; j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
