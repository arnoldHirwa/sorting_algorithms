#include "sort.h"

/**
* swap_lists - swap values of two lists
* @list_1: first list
* @list_2: second list
* @head: head of the list
* Return: None
*/
void swap_lists(listint_t **head, listint_t **list_1, listint_t *list_2)
{
	(*list_1)->next = list_2->next;
	if (list_2->next != NULL)
		list_2->next->prev = *list_1;
	list_2->prev = (*list_1)->prev;
	list_2->next = *list_1;
	if ((*list_1)->prev != NULL)
		(*list_1)->prev->next = list_2;
	else
		*head = list_2;
	(*list_1)->prev = list_2;
	*list_1 = list_2->prev;
}


/**
* insertion_sort_list - sort list using insertion sort algorithm
* @list: list to be sorted
*
* Return: None
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_lists(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
