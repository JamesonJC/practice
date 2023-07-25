#include "main.h"

int main(int argc, char **argv)
{
	if (argc != 1)
		non_interactive();
	else
		interactive(argv);

	return (0);
}
