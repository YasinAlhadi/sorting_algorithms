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
	j = 0;
	i = lo - 1;
	for (j = lo; j <= hi - 1; j++)
	{
		if (array[j] <= pivot_v)
		{
			i++;
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
	tmp = array[hi];
	array[hi] = array[i + 1];
	array[i + 1] = tmp;
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
	if (array == NULL)
		return;
	quicksort_recs(array, size, 0, size - 1);
}
