#include "main.h"

/**
 * main - Entry point of the shell program.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of strings containing the program name and its arguments.
 *
 * Description: The main function acts as the entry point for the shell program.
 *
 * Return: Always returns 0 to indicate successful execution.
 */

int main(int argc, char **argv)
{
	if (argc != 1)
		non_interactive();
	else
		interactive(argv);

	return (0);
}
