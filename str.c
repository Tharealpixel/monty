#include "monty.h"

/**
 * _strdup - Duplicates a string
 * @str: The string to duplicate
 *
 * Return: Pointer to the newly allocated duplicate string, or NULL on failure
 */
char *_strdup(const char *str)
{
	size_t len = strlen(str) + 1;
	char *cpy = malloc(len);

	if (cpy == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	memcpy(cpy, str, len);
	return (cpy);
}
