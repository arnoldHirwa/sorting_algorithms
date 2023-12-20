#include "sort.h"


/**
* swap_int - swap integers at provided memory locations
* @first: the first integer to swap
* @second: the second integer to swap
*
* Return: None
*/
void swap_int(int *first, int *second)
{
	int temp = *first;

	*first = *second;
	*second = temp;
}
/**
* partition - partition of the array with respect to the pivot
* @array: array to be partitioned
* @start: the beginning of the array
* @end: the end of the array
* @size: size of the array
* Return: the pivot Id of the array
*/
int partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int pivotId = start;
	int i;

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			swap_int(&array[i], &array[pivotId]);
			pivotId++;
		}
	}

	swap_int(&array[pivotId], &array[end]);
	print_array(array, size);
	return (pivotId);
}

/**
* quick_recursion - recursively sort the array using quick sort algorithm
* @array: array to be partitioned
* @start: the beginning of the array
* @end: the end of the array
*@size: size of the array
* Return: None
*/

void quick_recursion(int *array, int start, int end, size_t size)
{
	int partitionId;

	if (start < end)
	{
		partitionId = partition(array, start, end, size);
		quick_recursion(array, start, partitionId - 1, size);
		quick_recursion(array, partitionId + 1, end, size);
	}
}

/**
* quick_sort - sort the array using quick sort algorithm
*
* @array: array to sort
* @size: size of the array
*
* Return: None
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_recursion(array, 0, size - 1, size);
}
