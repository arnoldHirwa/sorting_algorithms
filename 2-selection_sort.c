#include "sort.h"

/**
* selection_sort - sort array using selection_sort Algorithm
*
* @array: array to sort
* @size: size of the array
*
* Return: None
*/
void selection_sort(int *array, size_t size)
{
	size_t minPosition, swapPosition;
	int minValue, sawMin = 0;
	size_t i = 0, j;

	if (array == NULL || size < 2)
		return;

	minPosition = 0;
	swapPosition = 0;
	for ( ; i < size - 1; i++)
	{
		minValue = array[minPosition];
		for (j = minPosition + 1; j < size; j++)
		{
			if (array[j] < minValue)
			{
				minValue = array[j];
				swapPosition = j;
				sawMin = 1;
			}
		}
		if (sawMin)
		{
			array[swapPosition] = array[minPosition];
			array[minPosition] = minValue;
			print_array(array, size);
		}
		minPosition += 1;
		sawMin = 0;
	}
}
