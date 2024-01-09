#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
	char *name;
	int age;
	int height;
	int weight;
}; // struct closures require a semicolon

struct Person *Person_create(char *name, int age, int height, int weight)
{
	struct Person *who = malloc(sizeof(struct Person)); //malloc
	assert(who != NULL);

	who->name = strdup(name);
	who->age =  age;
	who->height = height;
	who->weight = weight; // new syntax, some kind of mapping. 
			      // Looks a bit like inheretance here, doesn't it?
			      // also reminiscent of an object prototype or at least a method on a class...  

	return who;
}

void Person_destroy(struct Person *who) {
	assert(who != NULL);
        free(who->name);
	free(who); // free	
}

void Person_print(struct Person *who) {
	printf("Name: %s\n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);

}

int main(int argc, char *argv[])
{

	// make a two Person structs
	struct Person *joe = Person_create("John Doe", 32, 64, 140);

	struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

	// print the Person structs out and where they are in memory
	printf("Joe is at memory address %p\n", joe);
	Person_print(joe);

	printf("Frank is at memory address %p\n", frank);
	Person_print(frank);

	// make everyone's age 20 and print them out again
	printf("\n---\n Let's make everyone 20 years of age:");

	joe->age += 20; // exisiting value is more than 20
	Person_print(joe);

	frank->age += 20;
	Person_print(frank); // existing value is 20

	// destroy them both for cleaning up
	Person_destroy(joe);
	Person_destroy(frank);	

	return 0;

}

