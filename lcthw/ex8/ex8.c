# include <stdio.h>

int main (int argc, char *argv[]) 
{
	int i = 0;

	if (argc == 1) {
		printf("You have no additional arguments. \n");
	} else if (argc > 1 && argc < 4 ) {
		/* index 0, the program itself is a command-line arg I guess...   */
		printf("Here's your arguments: \n");

		for (i = 0; i < argc; i++) {
			printf("%s ", argv[i]);
		}
		printf("\n");
	} else {
		printf("You have too many arguments. \n");
	}

	return 0;

}
