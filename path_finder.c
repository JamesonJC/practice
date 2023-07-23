#include "main.h"

/**
 * path_finder - Function allocates path to the input.
 * @in: The user inpute.
 * Return: The actual path of the inpute
 */

char *search_path(const char *in)
{
	char *path, *dup_path = NULL, *tok_path = NULL, *f_path = NULL;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		dup_path = strdup(path);
		tok_path = strtok(dup_path, ":");
		while (tok_path != NULL)
		{
			f_path = malloc(sizeof(char *) * BUFFER);
			strcpy(f_path, tok_path);
			strcat(f_path, "/");
			strcat(f_path, in);
			if (stat(f_path, &buffer) == 0)
			{
				free(dup_path);
				return (f_path);
			}
			free(f_path);
			tok_path = strtok(NULL, ":");
		}
		if (stat(in, &buffer) == 0)
		{
			free(dup_path);
			return (strdup(in));
		}
		free(dup_path);
		return (NULL);
	}
	return (NULL);
}
