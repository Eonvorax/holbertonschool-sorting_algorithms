#include "sort.h"

/**
 * insertion_sort_list - sort the different node
 *
 * @list: the double linked list
 *
 * Return: no return, void function
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *swap_node;
	listint_t *previous;

	if (*list == NULL || (*list)->next == NULL)
	{
		return;
	}
	current = *list;

	while (current != NULL)
	{
		swap_node = current;
		while (swap_node->prev != NULL && swap_node->n < swap_node->prev->n)
		{
			previous = swap_node->prev;
			if (swap_node->n < swap_node->prev->n)
			{
				if (swap_node->next != NULL)
					swap_node->next->prev = previous;
				if (previous->prev != NULL)
					previous->prev->next = swap_node;
				else
					(*list) = swap_node;
				previous->next = swap_node->next;
				swap_node->prev = previous->prev;
				swap_node->next = previous;
				previous->prev = swap_node;
			}
			print_list((*list));
		}
		current = current->next;
	}
}
