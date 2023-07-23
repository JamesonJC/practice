#include "main.h"

/**
 * display_env - Output the shell local environment details
 *@av: Array of arguments values
 */

void display_env(char *av[])
{
	char **env = environ;

	if (strcmp(av[0], "env") == 0)
	{

		if (av[1] != NULL)
		{
			return;
		}
		while (*env)
		{
			if (*env)
				puts(*env);
			env++;
		}
	} else if (strcmp(av[0], "exit") == 0)
	{
		exit(0);
	}
	else
	{
		/*perfoms other commands*/
	}
}