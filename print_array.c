#include <stdio.h>
#include <stdlib.h>

/**
 * print_array - it Prints array integers
 *
 * @array: array to printed
 * @size: Number elements in @array
 */
void print_array(const int *array, size_t size) {
  size_t i;

  i = 0;
  while (array && i < size) {
    if (i > 0)
      printf(", ");
    printf("%d", array[i]);
    ++i;
  }
  printf("\n");
}
