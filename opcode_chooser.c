#include "monty.h"

/**
 * get_opcode_func - selects the correct function for the given opcode
 *
 * @op: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */
void (*get_opcode_func(char *op))(stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmpy(instructions[i].opcode, op) == 0)
			break;
	}

	return (instructions[i].func);
}
