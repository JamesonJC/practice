#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

char* myGetline() 
{
	char buffer[BUFFER_SIZE];
	char* line = NULL;
	if (fgets(buffer, BUFFER_SIZE, stdin))
	{
		size_t line_length = strlen(buffer);
		if (line_length > 0 && buffer[line_length - 1] == '\n'){
			buffer[line_length - 1] = '\0';// Remove the newline character
			line_length--; // Adjust the line length
		}
		line = (char*)malloc(line_length + 1);
		strcpy(line, buffer);
	}
	return line;

	int main()
	{
		printf("Enter a line of text: ");
	        fflush(stdout);
		char* inputLine = myGetline();
		printf("You entered: %s\n", inputLine);
		// Don't forget to free the memory allocated by myGetline
		free(inputLine);
		return 0;
	}
}
