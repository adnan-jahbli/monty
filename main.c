#include "monty.h"

/* global variables */
char *argv_p, **instructions, *line;
int line_count;
FILE *file;
stack_t *stack;

/**
 * main - a program that reads the opcode.
 * @argc: The argument count.
 * @argv: An array of strings containing the arguments.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
	size_t len;
	ssize_t read;
	void (*f)(stack_t **stack, unsigned int line_number);

	stack = NULL;
	line_count = 1;
	instructions = NULL;
	argv_p = argv[1];
	if (argc != 2)
		error_msg(0);
	file = fopen(argv_p, "r");
	if (file == NULL)
		error_msg(1);
	line = NULL;
	len = 0;
	while ((read = _getline(&line, &len, file)) != -1)
	{
		instructions = split_line(line);
		if (instructions != NULL)
		{
			f = check_instruction(instructions);
			f(&stack, line_count);
			free_double_pointer(instructions);
		}

		line_count++;
	}

	fclose(file);
	if (line)
		free(line);
	if (stack)
		free_linked_list(stack);
	return (0);
}