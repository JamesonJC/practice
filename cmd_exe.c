#include "main.h"

pid_t exe(char **argv, char **av, char **env)
{
	int *status;
	pid_t id = fork();
	(void)env;

	if (id == -1)
		return (id);

	if (id == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
			perror(av[0]);
		return (id);
	}
	else
	{
		wait(status);
		return (id);
	}
}
