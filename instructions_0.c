#include "monty.h"

/**
 * push - pushes an element to the stack
 *
 * @stack: pointer to the head of the linked list (stack)
 * @line_number: line number
 * Return: no return
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n, j;

	if (!global_vars.argument)
	{
		dprintf(2, "L%u: ", line_number);
		dprintf(2, "usage: push integer\n");
		free_global_vars();
		exit(EXIT_FAILURE);
	}

	for (j = 0; global_vars.argument[j] != '\0'; j++)
	{
		if (!isdigit(global_vars.argument[j]) && global_vars.argument[j] != '-')
		{
			dprintf(2, "L%u: ", line_number);
			dprintf(2, "usage: push integer\n");
			free_global_vars();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(global_vars.argument);

	if (global_vars.lifo_mode == 1)
		add_node(stack, n);
	else
		add_node_end(stack, n);
}

/**
 * pall - prints all values on the stack
 *
 * @stack: pointer to the head of the linked list (stack)
 * @line_number: line number
 * Return: no return
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;
	(void) line_number;

	aux = *stack;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 *
 * @stack: pointer to the head of the linked list (stack)
 * @line_number: line number
 * Return: no return
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	if (*stack == NULL)
	{
		dprintf(2, "L%u: ", line_number);
		dprintf(2, "can't pint, stack empty\n");
		free_global_vars();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 *
 * @stack: pointer to the head of the linked list (stack)
 * @line_number: line number
 * Return: no return
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_number);
		free_global_vars();
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	*stack = (*stack)->next;
	free(aux);
}

/**
 * swap - swaps the top two elements of the stack
 *
 * @stack: pointer to the head of the linked list (stack)
 * @line_number: line number
 * Return: no return
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *stack;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_number);
		free_global_vars();
		exit(EXIT_FAILURE);
	}

	aux = *stack;
	*stack = (*stack)->next;
	aux->next = (*stack)->next;
	aux->prev = *stack;
	(*stack)->next = aux;
	(*stack)->prev = NULL;
}
