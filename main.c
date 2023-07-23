#include "main.h"

int main(int argc, char **argv, char **env)
{
	if (argc != 1)
		non_interactive();
	else
		interactive(argv, env);

	return (0);
}
