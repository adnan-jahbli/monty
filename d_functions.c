#include "monty.h"

/**
 * add_node_end - adds a node at the end of the doubly linked list
 * @head: pointer to the head of the linked list
 * @n: data to be stored in the new node
 * Return: pointer to the newly added node
 */
stack_t *add_node_end(stack_t **head, const int n)
{
	stack_t *temp, *current;

	if (head == NULL)
		return (NULL);

	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_global_vars();
		exit(EXIT_FAILURE);
	}

	temp->n = n;

	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}

	current = *head;
	while (current->next)
		current = current->next;

	temp->next = current->next;
	temp->prev = current;
	current->next = temp;

	return (current->next);
}

/**
 * add_node - adds a node at the beginning of the doubly linked list
 * @head: pointer to the head of the linked list
 * @n: data to be stored in the new node
 * Return: pointer to the newly added node
 */
stack_t *add_node(stack_t **head, const int n)
{
	stack_t *temp;

	if (head == NULL)
		return (NULL);

	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_global_vars();
		exit(EXIT_FAILURE);
	}

	temp->n = n;

	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}

	(*head)->prev = temp;
	temp->next = (*head);
	temp->prev = NULL;
	*head = temp;

	return (*head);
}

/**
 * free_doubly_linked_list - frees the doubly linked list
 * @head: head of the list
 * Return: no return
 */
void free_doubly_linked_list(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
