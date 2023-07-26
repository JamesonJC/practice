#include "main.h"

/**
 * _memcpy - copies memory area from one address to another
 * @dest: first memory address
 * @src: second memory address
 * @n: Memory address size to be copied.
 * Return: Pointer to memory address copied
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}
