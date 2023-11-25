#include "sort.h"
#include <stddef.h>
#include <sys/types.h>

/**
 *l_partition - Lomuto partition scheme.
 *@array: it is the array of ints
 *@size: it is the size of array
 *@start: it is the start of array
 *@end: it is end of array
 *Return: it must return pivot
 */

size_t l_partition(int *array, size_t size, int start, int end)
{
	int i = start;
	int j = start;
	int pivot = array[end];
	int tmp;

	for (; j < end; j++)
	{
		if (array[j] < pivot)
		{
		if (array[i] != array[j])
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
		i++;
		}
	}

	if (array[i] != array[end])
	{
		tmp = array[i];
		array[i] = array[end];
		array[end] = tmp;
		print_array(array, size);
	}

	return (i);
}
/**
 *recursive_quick_sort - quick_sort recursively
 *@array: it is array of ints
 *@size: it is size of array
 *@start: it is the start of array
 *@end: it is the end of array
 */

void recursive_quick_sort(int *array, size_t size, ssize_t start, ssize_t end)
{
	size_t pivot;

	if (start < end)
	{
		pivot = l_partition(array, size, start, end);
		recursive_quick_sort(array, size, start, pivot - 1);
		recursive_quick_sort(array, size, pivot + 1, end);
	}
}
/**
 *quick_sort - function use quicl quick_sort algorithm
 *@array: array numbers to sorted
 *@size: this is the size of array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size == 0)
		return;
	recursive_quick_sort(array, size, 0, size - 1);
}
