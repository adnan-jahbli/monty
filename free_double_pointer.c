#include "monty.h"

/**
 * free_double_pointer - frees a double pointer
 * @ptr: the given double pointer
 *
 * Return: void.
 */
void free_double_pointer(char **ptr)
{
	char **temp;

	temp = ptr;
	while (*temp != NULL)
	{
		free(*temp);
		temp++;
	}
	free(ptr);
}