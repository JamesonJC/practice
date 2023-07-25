#include "main.h"


int main(void)
{
	ssize_t n;
	size_t buf = 0;
	char *in = NULL;

	printf("Enter something: ");
	n = _getline(in, &buf, stdin);

	printf("Input is: %s and no. chars are: %ld", in, n);

	free(in);
	return (0);

}
