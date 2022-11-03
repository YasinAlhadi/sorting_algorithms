#include "sort.h"
#include <stdbool.h>


/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array of ineger
 * @size: size of array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, tmp;
	bool swapped = false;

	i = 0;

	do {
		swapped = false;
		for (j = 0; j < (size - 1 - i); j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swapped = true;
				print_array(array, size);
			}
		}
		i++;
	} while (swapped);
}
