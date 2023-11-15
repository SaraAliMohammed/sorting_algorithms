#include "sort.h"

/**
 * swap_nodes - swaps two nodes of a doubly linked list.
 * @node1: first node pointer.
 * @node2: second node pointer.
 *
 * Return: Nothing
 */
void swap_nodes(listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node2->next = node1;
	node1->prev = node2;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 *ascending order using the Insertion sort algorithm
 *
 * @list: The list will be sorted.
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *a, *b;

	if (!list || !(*list) || !(*list)->next)
		return;
	a = (*list)->next;
	while (a)
	{
		b = a;
		a = a->next;
		while (b && b->prev)
		{
			if (b->n < b->prev->n)
			{
				swap_nodes(b->prev, b);
				if (!b->prev)
					*list = b;
				print_list((const listint_t *)*list);
			}
			else
				b = b->prev;
		}
	}
}
