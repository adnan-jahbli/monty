#include "monty.h"

/**
 * _strdup - function that duplicates a string.
 * @str: string to duplicate.
 *
 * Return: the new string (duplicate)
 */
char *_strdup(const char *str)
{
	size_t i, len = strlen(str) + 1;
	char *new_str = malloc(len);

	if (new_str == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len; i++)
	{
		new_str[i] = str[i];
	}
	return (new_str);
}