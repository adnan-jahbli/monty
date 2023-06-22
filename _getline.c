#include "monty.h"

#define INITIAL_BUFFER_SIZE 128

/**
 * _getline - a customizable version of getline function
 * @lineptr: a pointer to each line of the stream
 * @n: a pointer the size of each line
 * @stream: the given stream
 *
 * Return: void.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int ch/*, len*/;
	size_t i = 0;
	size_t buffer_size;
	char *buffer, *new_buffer;

	buffer_size = *n;
	buffer = *lineptr;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (buffer == NULL)
	{
        	buffer = malloc(INITIAL_BUFFER_SIZE);
        	if (buffer == NULL)
        		return (-1);
		buffer_size = INITIAL_BUFFER_SIZE;
	}

	while ((ch = fgetc(stream)) != EOF)
	{
		if (i >= buffer_size - 1)
		{
			buffer_size *= 2;
			new_buffer = malloc(buffer_size);
			if (new_buffer == NULL)
			{
				return (-1);
			}
			memcpy(new_buffer, buffer, i);
			free(buffer);
			buffer = new_buffer;
		}

		buffer[i++] = ch;

		if (ch == '\n')
			break;
	}

	/* len = strlen(buffer);
	if (len == 0)
	{
		new_buffer = NULL;
		free(buffer);
	} */
	if (i == 0)
	{
		return (-1);
	}

	buffer[i] = '\0';
	*lineptr = buffer;
	*n = buffer_size;

	return (i);
}