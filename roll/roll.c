/**
 * A program to give you a random number between 1 - 90
 * which corresponds to a list of programming projects.
 * Whichever number you get, you do that project.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Main function
 * Returns an int
**/
int main(void)
{
	// Define the limit
	static const int MAX = 90;

	// Define the min
	static const int MIN = 1;

	// Seed srand with current time
	srand(time(NULL));

	// Get the random number
	int random = rand() % MAX + MIN;

	// Print the result
	printf("%d\n", random);
}