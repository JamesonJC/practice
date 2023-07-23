#include "main.h"

#define MX_CMD 10

void interactive(char **av, char **env )
{
	char *input = NULL;
	int i;
	size_t buffer = 0;
	ssize_t _chars;
	char *argv[MX_CMD];
	(void)env;

	while(1)
	{
		printf("%s", PROMPT);
		_chars = getline(&input, &buffer, stdin);
		if (_chars == -1 || input == NULL)
		{
			free(input);
			exit(1);
		}

		for(i = 0; input[i] != '\0'; i++)
			if (input[i] == '\n')
				input[i] = '\0';

		argv[0] = strtok(input, " ");
		
		for(i = 0; argv[i] != NULL; i++)
		{
			argv[++i] = strtok(NULL, " ");
		}

		if (exe(argv, av, NULL) == -1)
		{
			free(input);
			exit(1);
		}
	}
}
