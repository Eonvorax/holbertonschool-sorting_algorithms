#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * with the Shell sort algorithm, using the Knuth sequence
 * @array: given array to sort
 * @size: size of the array
 *
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j;
	size_t gap = 1;
	int tmp;

	if (array == NULL || size < 2)
	{
		return;
	}
	while (gap <= size / 3)
	{
		gap = gap * 3 + 1;
	}
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > tmp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = tmp;
		}
		gap /= 3;
		print_array(array, size);
	}
}
