#include "sort.h"

/**
 *shell_sort - shell sort amgorithm
 *@array: array to be sorted
 *@size: it is the size of array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap_start, gap_end, gap = 1;
	int tmp;

	if (!array || size == 0)
		return;
	while (gap < size)
		gap = (gap * 3) + 1;
	gap = (gap - 1) / 3;

	while (gap > 0)
	{
		for (gap_end = gap; gap_end < size; gap_end++)
		{
			tmp = array[gap_end];
			gap_start = gap_end;
			while (gap_start > gap - 1 && array[gap_start - gap] >= tmp)
			{
				array[gap_start] = array[gap_start - gap];
				gap_start = gap_start - gap;
			}
			array[gap_start] = tmp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
