#include "sort.h"

/**
 * swap - sort the different index in an array
 *
 * @a: first int to swap
 * @b: second int to swap
 *
 * Return: no return, voidd function
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * lomuto_part - sort the different index in an array
 *
 * @array: an array
 * @size: the size of the array
 * @low: start of array
 * @hight: end of array
 *
 * Return: no return, void function
 */

int lomuto_part(int array[], int low, int hight, size_t size)
{
	int pivot = array[hight];
	int i = low - 1;
	int j;

	for (j = low; j < hight; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[hight])
	{
		swap(&array[i + 1], &array[hight]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * second_quick_sort - sort the different index in an array
 *
 * @array: an array
 * @size: the size of the array
 * @low: start of array
 * @hight: end of array
 *
 * Return: no return, voidd function
 */

void second_quick_sort(int array[], int low, int hight, size_t size)
{
	int party;

	if (low < hight)
	{
		party = lomuto_part(array, low, hight, size);
		second_quick_sort(array, low, party - 1, size);
		second_quick_sort(array, party + 1, hight, size);
	}
}

/**
 * quick_sort - sort the different index in an array
 *
 * @array: an array
 * @size: the size of the array
 *
 * Return: no return, voidd function
 */

void quick_sort(int *array, size_t size)
{
	int low, hight;

	if (size < 2)
		return;

	low = 0;
	hight = size - 1;
	second_quick_sort(array, low, hight, size);
}
