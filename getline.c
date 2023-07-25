#include "main.h"

/*******/

ssize_t _getline(char *str, size_t index, int stream)
{
	char c;
	static char array_buffer[BUFFER];
	static size_t buffer = 0;
	static ssize_t _chars = 0;
	buffer = 0;

	while(1)
	{
		if (buffer >= _chars)
		{
			if (stream == 0)
			{
				_chars = read(STDIN_FILENO, array_buffer, BUFFER);
				buffer = 0;

				if (_chars <= 0)
				{
					break;
				}
			}
		}
		c = array_buffer[buffer];
		index++;

		if (c == '\n' || c == EOF)
			break;
		if (index == 0)
			str = malloc(BUFFER);
		else if (index % BUFFER == 0)
			str = realloc(str, index + BUFFER);
		str[index] = c;
	}
	if (str)
	{
		str = realloc(str, index++);
		str[index] = '\0';
	}
	return (_chars = index);
}
