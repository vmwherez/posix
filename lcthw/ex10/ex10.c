#include <stdio.h>

int main (int argc, char *argv[]){
	if (argc != 2) {
		printf("Error: you need one arguement \n");
		return 1;
	}

	int i = 0;

	for (i = 0; argv[1][i] != '\0'; i++) {
		char letter = argv[1][i];
		

		// a switch case to detect vowels

		switch (letter) {
			case 'a':
			case 'A':
			  printf("%d: 'A'\n", i);
			  break;
			case 'e':
			case 'E': 
			  printf("%d: 'E'\n", i);
	      		  break;
		  	case 'i':
			case 'I':
			  printf("%d: 'I'\n", i);
	      		  break;
		        case 'o':
			case 'O': 
			  printf("%d: 'O'\n", i);
	      		  break;
			case 'u':
			case 'U': 
			  printf("%d: 'U'\n", i);
	      		  break;
			case 'y':
			case 'Y':
  			  // ...and sometimes Y
			  if (i > 2) {
				  printf("%d: 'Y'\n", i);
				  break;
			  }
			default: 
			  printf("%d: %c is not a vowel.\n", i, letter);


	  }
	}
	return 0;
}