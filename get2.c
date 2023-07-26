#include <stdio.h>
#include <stdlib.h>

int my_getline(char **lineptr, size_t *n)
{
	int c;
	size_t i = 0;
	if (lineptr == NULL || n == NULL)
	{
		return -1; // Invalid input parameters
	}
	// Allocate initial memory for the line
	*lineptr = (char*)malloc(*n);
	if (*lineptr == NULL)
	{
		return -1;
		// Memory allocation failure
	}
	// Read characters until newline or EOF is encountered
	while ((c = getchar()) != EOF && c != '\n')
	{
		(*lineptr)[i] = (char)c;
		i++;
		if (i == *n)
		{
			// If the buffer is full, reallocate more memory
			*n *= 2;
			char* temp = (char*)realloc(*lineptr, *n);
			if (temp == NULL)
			{
				free(*lineptr);
				return -1; // Memory allocation failure
			}
			*lineptr = temp;
		}
	}
	// Null-terminate the line
	(*lineptr)[i] = '\0';
	// If no characters were read and EOF is encountered, return -1
	if (c == EOF && i == 0)
	{
		return -1;
	}
	return i; // Return the number of characters read
	int main()
	{
		char *line = NULL;
		size_t bufsize = 32;
		int chars_read;
		printf("Enter a line of text:\n");
		chars_read = my_getline(&line, &bufsize);
		if (chars_read != -1)
		{
			printf("Number of characters read: %d\n", chars_read);
			printf("Line: %s\n", line);
		} else 
		{
			printf("No characters read or encountered EOF.\n");
		}
		free(line);
		return 0;
	}
}
