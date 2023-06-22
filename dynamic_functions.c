#include "monty.h"

/**
 * my_calloc - allocates memory for an array and initializes it to zero
 *
 * @nmemb: number of elements
 * @size: size of each element
 * Return: pointer to the allocated memory, or NULL if it fails
 */
void *my_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr = NULL;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < (nmemb * size); i++)
		*((char *)(ptr) + i) = 0;

	return (ptr);
}

/**
 * my_realloc - reallocates a memory block with a new size
 *
 * @ptr: pointer to the previously allocated memory block
 * @old_size: old size in bytes
 * @new_size: new size in bytes
 * Return: pointer to the reallocated memory block, or NULL if it fails
 */
void *my_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr = NULL;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (!new_ptr)
			return (NULL);
		return (new_ptr);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size > old_size)
	{
		new_ptr = malloc(new_size);
		if (!new_ptr)
			return (NULL);
		for (i = 0; i < old_size; i++)
			new_ptr[i] = *((char *)ptr + i);
		free(ptr);
	}
	else
	{
		new_ptr = malloc(new_size);
		if (!new_ptr)
			return (NULL);
		for (i = 0; i < new_size; i++)
			new_ptr[i] = *((char *)ptr + i);
		free(ptr);
	}

	return (new_ptr);
}

