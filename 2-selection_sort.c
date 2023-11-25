#include "sort.h"

/**
 *selection_sort - selection sort function
 *@array: it is array of int
 *@size: this is the size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, min;
	int tmp;

	if (!array || size == 0)
		return;
	for (; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
				min = j;
		}
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
