#include <stdio.h>

int main(int argc, char *argv[])
{
	int distance = 100;
	float power = 2.345f;
	double superpower = 56789.4532;
	char initial = 'A';
	char first_name[] = "Zed";
	char last_name[] = "Shaw";

	printf("you are %d miles away. \n", distance);
	printf("you have %f levels of power. \n", power);
	printf("you have %f awesome super powers \n", superpower);
	printf("I have initial %c. \n", initial);
	printf("I have first name %s.", first_name);
	printf("I have last name %s.", last_name);
	printf("My full name is  %s %c. %s. \n", first_name, initial, last_name);

	int bugs = 100;
	double bug_rate = 1.2;

	printf("You have %d bugs at the imaginary rate of %f. \n", bugs, bug_rate);

	long universe_of_defects = 1L * 1024L * 1024L * 1024L;
       	printf("The entire unviverse has %ld bugs. \n", universe_of_defects);

	double expected_bugs = bugs * bug_rate;
	printf("You are expected to have %f bugs. \n", expected_bugs);

	double part_of_universe = expected_bugs / universe_of_defects;
	printf("This is only a %e portion of the universe. \n", part_of_universe);

	//"this makes no sense, just a demo of something weird."
	char nul_byte = '\0'
	int care_percentage = bugs * nul_byte;
	printf("Which means you should care %d%%. \n", care_percentage);	
	
	return 0;

}
