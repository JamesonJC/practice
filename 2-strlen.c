#include "main.h"

/**
 * _strlen - The function prints the length of a string
 * @s: The string that is taken into the a function
 * Return: returns integer value length of the string
 */

int _strlen(const char *s)
{
	int ln = 0;

	while (*s != '\0')
	{
		ln = ln + 1;
		s++;
	}
	return (ln);
}
