#include "sort.h"

/**
 * selection_sort - swaps two nodes of a doubly linked list.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, index_min_num;
	int temp;

	if (!array || !size)
		return;
	for (i = 0; i < size - 1; i++)
	{
		index_min_num = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[index_min_num])
				index_min_num = j;
		}
		if (index_min_num != i)
		{
			temp = array[i];
			array[i] = array[index_min_num];
			array[index_min_num] = temp;
			print_array(array, size);
		}
	}
}
