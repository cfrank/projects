/*
 * A program to give you a random number between 1 - 100
 * Basically only useful for getting your post number
 * Without having to post on 4chan
**/

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
	static const int MAX = 100;

	// Define the min
	static const int MIN = 1;

	// Seed srand with current time
	srand(time(NULL));

	// Get the random number
	int random = rand() % MAX + MIN;

	// Print the result
	printf("%d\n", random);
}