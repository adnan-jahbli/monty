#include "monty.h"

int only_digits(char *str);

/**
 * check_instruct - checks whether an instructions exists
 * @instructions: opcode passed.
 *
 * Return: a pointer to a function that excutes
 * the opcode.
 */
void (*check_instruction(char **instructions))(stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t words[] = {
				{"push", _push},
				{"pall", _pall},
				{NULL, NULL}
	};
	for (i = 0; words[i].opcode; i++)
	{
		if (!strncmp("push", instructions[0], strlen(words[i].opcode)))
		{
			if (only_digits(instructions[1]) == 1)
				return (words[i].f);
			else
				error_msg(2);
		}
		else if (!strncmp(words[i].opcode, instructions[0], strlen(words[i].opcode)))
		{
			return (words[i].f);
		}
	}
	/* in case no instruction found */
	error_msg(3);
	return (NULL);
}

/**
 * only_digits - checks if there's only digits in a string
 * @str: the given string
 *
 * Return: 1 if str contains digits, 0 otherwise.
 */
int only_digits(char *str)
{
	int i;

	if (str == NULL)
	{
		return (0);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
		{
			return (0);  /* Non-digit character found */
		}
	}

	return (1);  /* Contains only digits */
}