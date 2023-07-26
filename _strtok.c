#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char* my_strtok(char* str, const char* delim) {
	    static char* nextToken = NULL;

	        // If str is NULL, continue tokenizing from the last position
	        if (str == NULL)
			        str = nextToken;

		    // Skip leading delimiters
		    str += strspn(str, delim);

		        // If str is empty or contains only delimiters, return NULL
		        if (*str == '\0')
				        return NULL;

			    // Find the end of the token
			    char* end = str + strcspn(str, delim);
			        
			        // Check if we reached the end of the input string
			        if (*end == '\0') {
					        nextToken = NULL;
						    } else {
							            // Null-terminate the token and update the nextToken pointer
							            *end = '\0';
								            nextToken = end + 1;
									        }

				    return str;
}

int main() {
	    char str[] = "Hello, World! This is my strtok implementation.";
	        const char delim[] = " ,!.";

		    char* token = my_strtok(str, delim);
		        while (token != NULL) {
				        printf("%s\n", token);
					        token = my_strtok(NULL, delim);
						    }

			    return 0;
}
