#include "monty.h"

/**
 * divide_top_by_second - divides the second element
 * by the top element of the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number of the instruction
 * Return: no return
 */
void divide_top_by_second(stack_t **stack, unsigned int line_number)
{
	int m = 0;
	stack_t *temp = NULL;

	temp = *stack;

	for (; temp != NULL; temp = temp->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_number);
		free_global_vars();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		free_global_vars();
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	temp->n /= (*stack)->n;
	pop(stack, line_number);
}

/**
 * multiply_top_to_second - multiplies the top element
 * to the second top element of the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number of the instruction
 * Return: no return
 */
void multiply_top_to_second(stack_t **stack, unsigned int line_number)
{
	int m = 0;
	stack_t *temp = NULL;

	temp = *stack;

	for (; temp != NULL; temp = temp->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_number);
		free_global_vars();
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	temp->n *= (*stack)->n;
	pop(stack, line_number);
}

/**
 * compute_modulo - computes the remainder of
 * the division of the second element
 * by the top element of the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number of the instruction
 * Return: no return
 */
void compute_modulo(stack_t **stack, unsigned int line_number)
{
	int m = 0;
	stack_t *temp = NULL;

	temp = *stack;

	for (; temp != NULL; temp = temp->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", line_number);
		free_global_vars();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		free_global_vars();
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	temp->n %= (*stack)->n;
	pop(stack, line_number);
}

/**
 * print_char - prints the char value of the first element
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number of the instruction
 * Return: no return
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_number);
		free_global_vars();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_number);
		free_global_vars();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
/**
 * print_string - prints the string of the stack
 *
 * @stack: pointer to the head of the stack
 * @line_number: line number of the instruction
 * Return: no return
 */
void print_string(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;

	while (temp && temp->n > 0 && temp->n < 128)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}

	printf("\n");
}
