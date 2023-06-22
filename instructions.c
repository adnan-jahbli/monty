#include "monty.h"

/**
 * _push - inserts a stack
 * @stack: a pointer to the first node
 * @line_number: the reached line number
 *
 * Return: void.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	(void) line_number;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Stack overflow\n");
		exit(1);
	}
	new_node->n = atoi(instructions[1]);
	new_node->prev = NULL;
	if (*stack == NULL)
	{
		new_node->next = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}

/**
 * _pall - prints the data of a stack
 * @stack: a pointer to the first node
 * @line_number: the reached line number
 *
 * Return: void.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	temp = *stack;
	if (*stack != NULL)
	{
		while (temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}