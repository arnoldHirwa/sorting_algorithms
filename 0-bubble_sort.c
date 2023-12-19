#include "sort.h"

/**
* bubble_sort - sort array using bubble sort method
*
* @array: an array to sort
* @size: size of the array
*
* Return: None
*/
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j;
	size_t temp, max, currentSize;

	if (size < 2)
		return;

	max = 0;
	currentSize = size - 1;
	for ( ; i < size - 1; i++)
	{
		for (j = 0; j < currentSize; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				max = j + 1;
				print_array(array, size);
			}
		}
		currentSize = max;
		if (currentSize == 0)
			break;
	}
}
