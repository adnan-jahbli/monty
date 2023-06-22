#include "monty.h"

/**
 * split_line - splits a line into words
 * @str: the given line
 *
 * Return: a double pointer containing the splited words.
 */
char **split_line(char *str)
{
	char *token, **instructions;
	int i, number_words;

	number_words = 0;
	if (str[0] != ' ' && str[0] != '\t' && str[0] != '\n')
		number_words++;
	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] == ' ' || str[i] == '\t') && str[i + 1] != ' '
				&& str[i + 1] != '\t' && str[i + 1] != '\n' && str[i + 1] != '\0')
			number_words++;
	}
	if (number_words == 0)
		return (NULL);

	instructions = malloc((number_words + 1) * sizeof(char *));
	if (instructions == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(str);
		exit(1);
	}

	token = strtok(str, DELIM);
	i = 0;
	while (token)
	{
		instructions[i] = _strdup(token);
		if (instructions[i] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			/* free_instructions(instructions); */
			exit(1);
		}
		token = strtok(NULL, DELIM);
		i++;
	}
	instructions[number_words] = NULL;

	return (instructions);
}