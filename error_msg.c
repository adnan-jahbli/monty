#include "monty.h"

/**
 * error_msg - prints error messages and exit
 * @error_type: an integer that indicates the type of the error
 * Return: void.
 */
void error_msg(int error_type)
{
	switch (error_type)
	{
		case 0:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 1:
			fprintf(stderr, "Error: Can't open file %s\n", argv_p);
			break;
		case 2:
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_count);
			free_double_pointer(instructions);
			if (stack)
				free_linked_list(stack);
			free(line);
			fclose(file);
			break;
		}
		case 3:
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, instructions[0]);
			free_double_pointer(instructions);
			if (stack)
				free_linked_list(stack);
			free(line);
			fclose(file);
			break;
		}
	}
	exit(EXIT_FAILURE);
}