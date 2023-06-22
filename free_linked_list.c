#include "monty.h"

/**
 * free_linked_list - Frees a doubly linked list.
 *
 * @head: Head of the list.
 *
 * Return: No return value.
 */
void free_linked_list(stack_t *head)
{
	stack_t *temp;

	if (head != NULL)
		while (head->prev != NULL)
			head = head->prev;

	while ((temp = head) != NULL)
	{
		head = head->next;
		free(temp);
	}
}