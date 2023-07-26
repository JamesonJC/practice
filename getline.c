#include "main.h"

/*******/

ssize_t _getline(char *str, static size_t *buffer, FILE *stream)
{
	int c;
	static char temp[BUFFER];
	size_t index = 0;
	static ssize_t _chars = 0;

	/*if (str == NULL || index == NULL)
		return (-1);
	*str = (char *)malloc(*n);
	if (*str == NULL)
		return (-1);*/
	while(1)
	{
		if (buffer >= _chars)
		{
			if (stream == stdin)
			{
				_chars = read(STDIN_FILENO, temp, BUFFER);
				buffer = 0;

				if (_chars <= 0)
					break;
			}
		}
		c = temp[buffer++];

		if (c == '\n' || c == EOF)
			break;

		if (index == 0)
			str = malloc(BUFFER);
		else if (index % BUFFER == 0)
			str = realloc(str, index + BUFFER);
		str[index++] = c;
	}
	if (str)
	{
		str = realloc(str, index + 1);
		str[index] = '\0';
	}
	return (_chars /*= index*/);
}
