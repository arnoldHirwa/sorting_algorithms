#include "sort.h"

/**
 * swap_before_node - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @curr_s: A pointer to the current swapping node of the cocktail curr_s algo.
 */
void swap_before_node(listint_t **list, listint_t **tail, listint_t **curr_s)
{
	listint_t *tmp = (*curr_s)->next;

	if ((*curr_s)->prev != NULL)
		(*curr_s)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*curr_s)->prev;
	(*curr_s)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *curr_s;
	else
		*tail = *curr_s;
	(*curr_s)->prev = tmp;
	tmp->next = *curr_s;
	*curr_s = tmp;
}

/**
 * swap_prev_node - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @curr_s: A pointer to the current swapping node of the cocktail curr_s algo.
 */
void swap_prev_node(listint_t **list, listint_t **tail, listint_t **curr_s)
{
	listint_t *tmp = (*curr_s)->prev;

	if ((*curr_s)->next != NULL)
		(*curr_s)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*curr_s)->next;
	(*curr_s)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *curr_s;
	else
		*list = *curr_s;
	(*curr_s)->next = tmp;
	tmp->prev = *curr_s;
	*curr_s = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail curr_s algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *curr_s;
	int shaken_not_stirred = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == 0)
	{
		shaken_not_stirred = 1;
		for (curr_s = *list; curr_s != tail; curr_s = curr_s->next)
		{
			if (curr_s->n > curr_s->next->n)
			{
				swap_before_node(list, &tail, &curr_s);
				print_list((const listint_t *)*list);
				shaken_not_stirred = 0;
			}
		}
		for (curr_s = curr_s->prev; curr_s != *list;
				curr_s = curr_s->prev)
		{
			if (curr_s->n < curr_s->prev->n)
			{
				swap_prev_node(list, &tail, &curr_s);
				print_list((const listint_t *)*list);
				shaken_not_stirred = 0;
			}
		}
	}
}
