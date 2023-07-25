#include "main.h"

/******/


void shell_exit(pid_t pid, char **av)
{
	int state, exit_state;

	waitpid(pid, &state, 0);
	if (WIFEXITED(state))
	{
		exit_state = WEXITSTATUS(state);
		if (exit_state == 0 && av[0] == NULL)
		{
			exit(0);
		}
	}
}
