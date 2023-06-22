#include "monty.h"

/**
 * set_queue_mode - sets the format of the data to a queue (FIFO)
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number of the instruction
 * Return: no return
 */
void set_queue_mode(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	global_vars.lifo_mode = 0;
}

/**
 * set_stack_mode - sets the format of the data to a stack (LIFO)
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number of the instruction
 * Return: no return
 */
void set_stack_mode(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	global_vars.lifo_mode = 1;
}

/**
 * add_top_two_elements - adds the top two elements of the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number of the instruction
 * Return: no return
 */
void add_top_two_elements(stack_t **stack, unsigned int line_number)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *stack;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		free_global_vars();
		exit(EXIT_FAILURE);
	}

	aux = (*stack)->next;
	aux->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * do_nothing - doesn't do anything
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number of the instruction
 * Return: no return
 */
void do_nothing(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * subtract_top_element - subtracts the top element from
 * the second top element of the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number of the instruction
 * Return: no return
 */
void subtract_top_element(stack_t **stack, unsigned int line_number)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *stack;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_number);
		free_global_vars();
		exit(EXIT_FAILURE);
	}

	aux = (*stack)->next;
	aux->n -= (*stack)->n;
	pop(stack, line_number);
}
