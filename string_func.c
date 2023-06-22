#include "monty.h"

/**
 * strcmpy - Function that compares two strings.
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: 0 if s1 and s2 are equal, another value if they are different
 */
int strcmpy(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;

	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);

	return (0);
}

/**
 * sch - search if a char is inside a string
 * @s: string to search
 * @c: character to find
 * Return: 1 if success, 0 if not
 */
int sch(char *s, char c)
{
	int cont = 0;

	while (s[cont] != '\0')
	{
		if (s[cont] == c)
			break;
		cont++;
	}

	if (s[cont] == c)
		return (1);
	else
		return (0);
}

/**
 * strtoky - function that cuts a string
 * into tokens depending on the delimiters
 * @s: string to tokenize
 * @d: delimiters
 * Return: first token
 */
char *strtoky(char *s, char *d)
{
	static char *last;
	int i = 0, j = 0;

	if (!s)
		s = last;

	while (s[i] != '\0')
	{
		if (sch(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			last = s + i + 1;
			*last = '\0';
			s = s + j;
			return (s);
		}
		else if (sch(d, s[i]) == 0 && sch(d, s[i + 1]) == 0)
			i++;
		else if (sch(d, s[i]) == 0 && sch(d, s[i + 1]) == 1)
		{
			last = s + i + 1;
			*last = '\0';
			last++;
			s = s + j;
			return (s);
		}
		else if (sch(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}

	return (NULL);
}
