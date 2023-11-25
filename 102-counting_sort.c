#include "sort.h"
#include <stdlib.h>

/**
 *minMax - it should find minimum and maximum values
 *@array: array
 *@size: size of the array
 *@min: min value
 *@max: max value
 */

void minMax(int *array, size_t size, int *min, int *max)
{
	int i = 1;

	*min = *max = array[0];
	for (; i < (int)size; i++)
	{
		if (array[i] < *min)
			*min = array[i];
		else if (array[i] > *max)
			*max = array[i];
	}
}
/**
 *counting_sort - it must couunte sort algorithm
 *@array: array
 *@size: this is the array size
 */

void counting_sort(int *array, size_t size)
{
	int min, max, i, j;
	int *count_array, *output_array;
	int range;

	if (!array || size < 2)
		return;
	minMax(array, size, &min, &max);
	range = max + 1;
	count_array = malloc(range * sizeof(int));
	output_array = malloc(size * sizeof(int));
	if (!count_array || !output_array)
	{
		free(count_array);
		free(output_array);
		return;
	}
	for (i = 0; i < range; i++)
		count_array[i] = 0;
	for (i = 0; i < (int)size; i++)
		count_array[array[i]]++;
	for (j = 1; j < range; j++)
		count_array[j + 1] += count_array[j];
	print_array(count_array, range);
	for (i = 0; i < (int)size; i++)
	{
		count_array[array[i]]--;
		output_array[count_array[array[i]]] = array[i];
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output_array[i];
	free(count_array);
	free(output_array);
}
