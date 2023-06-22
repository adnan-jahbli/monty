#include "monty.h"

global_data global_vars;

/**
 * free_global_vars - frees the global variables
 *
 * Return: no return
 */
void free_global_vars(void)
{
	free_doubly_linked_list(global_vars.head);
	free(global_vars.buffer);
	fclose(global_vars.file_ptr);
}

/**
 * initialize_global_vars - initializes the global variables
 *
 * @file_ptr: file pointer
 * Return: no return
 */
void initialize_global_vars(FILE *file_ptr)
{
	global_vars.lifo_mode = 1;
	global_vars.counter = 1;
	global_vars.argument = NULL;
	global_vars.head = NULL;
	global_vars.file_ptr = file_ptr;
	global_vars.buffer = NULL;
}

/**
 * check_input_file - checks if the file exists and can be opened
 *
 * @arg_count: argument count
 * @arg_vector: argument vector
 * Return: file pointer
 */
FILE *check_input_file(int arg_count, char *arg_vector[])
{
	FILE *file_ptr;

	if (arg_count == 1 || arg_count > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_ptr = fopen(arg_vector[1], "r");

	if (file_ptr == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", arg_vector[1]);
		exit(EXIT_FAILURE);
	}

	return (file_ptr);
}

/**
 * main - Entry point
 *
 * @arg_count: argument count
 * @arg_vector: argument vector
 * Return: 0 on success
 */
int main(int arg_count, char *arg_vector[])
{
	void (*func_ptr)(stack_t **stack, unsigned int line_number);
	FILE *file_ptr;
	size_t buffer_size = 256;
	ssize_t num_lines = 0;
	char *line_tokens[2] = {NULL, NULL};

	file_ptr = check_input_file(arg_count, arg_vector);
	initialize_global_vars(file_ptr);
	num_lines = getline(&global_vars.buffer, &buffer_size, file_ptr);
	while (num_lines != -1)
	{
		line_tokens[0] = strtoky(global_vars.buffer, " \t\n");
		if (line_tokens[0] && line_tokens[0][0] != '#')
		{
			func_ptr = get_opcode_func(line_tokens[0]);
			if (!func_ptr)
			{
				dprintf(2, "L%u: ", global_vars.counter);
				dprintf(2, "unknown instruction %s\n", line_tokens[0]);
				free_global_vars();
				exit(EXIT_FAILURE);
			}
			global_vars.argument = strtoky(NULL, " \t\n");
			func_ptr(&global_vars.head, global_vars.counter);
		}
		num_lines = getline(&global_vars.buffer, &buffer_size, file_ptr);
		global_vars.counter++;
	}

	free_global_vars();

	return (0);
}
