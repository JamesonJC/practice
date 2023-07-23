#include "main.h"

/******/


void _exit(pid)
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
