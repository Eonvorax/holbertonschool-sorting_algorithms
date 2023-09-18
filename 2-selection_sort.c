#include "sort.h"

/**
 * swap_ints - swaps two integers
 * @a: first given integer
 * @b: second given integer
 *
 * Return: void
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: pointer to array to be sorted
 * @size: Number of elements in @array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap_ints(&array[i], &array[min]);
			print_array(array, size);
		}
	}
}
