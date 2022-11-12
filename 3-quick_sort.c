#include "sort.h"

/**
 * partition - partition scheme
 * @array: array of ineger
 * @size: sizr of array
 * @lo: minimum element
 * @hi: maximum element
 *
 * Return: index
 */
int partition(int *array, size_t size, int lo, int hi)
{
	int pivot_v, j, i, tmp;

	pivot_v = array[hi];
	i = lo - 1;
	for (j = lo; j <= hi; j++)
	{
		if (array[j] < pivot_v)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[hi] < array[i + 1])
	{
		tmp = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort_recs - quicksort
 * @array: array of integer
 * @size: size of array
 * @lo: minimum element
 * @hi: maximum element
 *
 * Return: viod
 */
void quicksort_recs(int *array, size_t size, int lo, int hi)
{
	int pivot;

	if (lo < hi)
	{
		pivot = partition(array, size, lo, hi);
		quicksort_recs(array, size, lo, pivot - 1);
		quicksort_recs(array, size, pivot + 1, hi);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array of integer
 * @size: size of array
 *
 * Return: viod
 */
void quick_sort(int *array, size_t size)
{
	quicksort_recs(array, size, 0, size - 1);
}
