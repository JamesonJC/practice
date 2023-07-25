#include "main.h"

pid_t exe(char **argv, char **av)
{
	char *path_cmd, *ext = "exit";
	int *status = 0;
	pid_t id = fork();

	if (id == -1)
		return (id);

	if (id == 0)
	{
		if (argv[0] == ext)
			shell_exit(id, argv);
		else
		{
			path_cmd = search_path(argv[0]);
				if (execve(path_cmd, argv, NULL) == -1)
				perror(av[0]);
		}
		 return (id);
	}
	else
	{
		wait(status);
		return (id);
	}
}
