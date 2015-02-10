/**
 * Change Return
 * A simple program to determine the change given
 * back to the user depening on C & M
 *
 * C = Cost of item(s)
 * M = Money given by customer
 *
 * @Author: Chris Frank
 * @Email: 	chris@cfrank.org
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float getDif(float c, float m)
{
	// First find the difference between
	// c & m (m - c = d)
	float dif = m - c;

	// Return the difference
	return dif;
}

void getChange(float dif, int* cash, float* change)
{
	// If difference is less than 0 we have a problem
	// because the customer gave us less money than
	// the cost of the product
	if(dif < 0)
	{
		fprintf(stderr, "The customer has not given enough money!...\n");
		exit(EXIT_FAILURE);
	}
	// Cash is seen as the difference without any
	// decimals. So if the difference is $13.45
	// the cash would be 13 since cash is, in my
	// mind paper money
	*cash = (int) dif;

	// Change is seen as the difference - cash
	// if the difference is $13.45 the change
	// would be .45
	*change = dif - *cash;
}

void getCash(int cash, int* oneHundred, int* fifty, int* twenty, int* ten,
				int* five, int* one)
{
	if(cash == 0)
	{
		printf("Wow close to exact change! - No need for cash...\n");
		// End the function there is no need to continue
		return;
	}

	// Since cash is > 0 we need to determine the bills to return
	// to the user...
	// For each denomination of bill, check if the cash variable
	// is greater or equal to that denomination. If it is loop over
	// the cash variable and until it is less than that denomination
	// and incremement the variable corresponding to the bill.
	if(cash >= 100)
	{
		while(cash >= 100)
		{
			cash = cash - 100;
			++*oneHundred;
		}
	}

	if(cash >= 50)
	{
		while(cash >= 50)
		{
			cash = cash - 50;
			++*fifty;
		}
	}

	if(cash >= 20)
	{
		while(cash >= 20)
		{
			cash = cash - 20;
			++*twenty;
		}
	}

	if(cash >= 10)
	{
		while(cash >= 10)
		{
			cash = cash - 10;
			++*ten;
		}
	}

	if(cash >= 5)
	{
		while(cash >= 5)
		{
			cash = cash - 5;
			++*five;
		}
	}

	if(cash >= 1)
	{
		while(cash >= 1)
		{
			cash = cash - 1;
			++*one;
		}
	}
}

void getCoins(float change, int* quarter, int* dime, int* nickel, int* penny)
{
	// To find the correct change we need to turn the
	// current format of variable change (0.57) into
	// a easier to work with 57.
	int tenChange = floor((change * 100) + 0.5);
	
	// For each denomination of coins, check if the change variable
	// is greater or equal to that denomination. If it is loop over
	// the change variable and until it is less than that denomination
	// incremement the variable corresponding to the coin.
	if(tenChange >= 25)
	{
		while(tenChange >= 25)
		{
			tenChange = tenChange - 25;
			++*quarter;
		}
	}

	if(tenChange >= 10)
	{
		while(tenChange >= 10)
		{
			tenChange = tenChange - 10;
			++*dime;
		}
	}

	if(tenChange >= 5)
	{
		while(tenChange >= 5)
		{
			tenChange = tenChange - 5;
			++*nickel;
		}
	}

	if(tenChange >= 1)
	{
		while(tenChange >= 1)
		{
			tenChange = tenChange - 1;
			++*penny;
		}
	}
}

int main(void)
{
	// Create variables for the various things we create
	float c, m, dif, change;
	int cash, oneHundred, fifty, twenty, ten, five, one, quarter, dime, nickel,
		penny;

	printf("Enter the exact amount of the items (18.37): ");
	// Obtain the cost
	scanf("%f", &c);

	printf("Enter the amount of money given by the customer: ");
	// Obtain the money from customer
	scanf("%f", &m);

	// Obtain the difference of the cost
	// And the money given by calling the
	// getDif() function
	dif = getDif(c,m);

	// Send the difference to the getChange()
	// function, as well as the pointers 
	// cash & change which will be used in the
	// function and returned back here
	getChange(dif, &cash, &change);

	// First send the cash variable to the getCash
	// function along with pointers for each bill
	// The function will calculate the number of bills
	// to give to the customer and return each
	getCash(cash, &oneHundred, &fifty, &twenty, &ten, &five, &one);

	// Print the difference of the two denominations.
	printf("Difference = $%.2f\n", dif);

	// Print the number of bills to give to the customer
	if(oneHundred >= 1)
		printf("Give the customer %d Hundred doller bill(s)!\n", oneHundred);

	if(fifty >= 1)
		printf("Give the customer %d Fifty doller bill(s)!\n", fifty);

	if(twenty >= 1)
		printf("Give the customer %d Twenty doller bill(s)!\n", twenty);

	if(ten >= 1)
		printf("Give the customer %d Ten doller bill(s)!\n", ten);

	if(five >= 1)
		printf("Give the customer %d Five doller bill(s)!\n", five);

	if(one >= 1)
		printf("Give the customer %d One doller bill(s)!\n", one);

	// Print a seperator between cash, and change
	// making it easier to read
	if(cash >= 1 && change > 0)
		printf("--- ---\n");

	// Initalize the pointers from the cash function to 0 in order
	// to remove the possiblility that they next function (coins)
	// Will get unwanted values because of a overlap in memory.
	cash = oneHundred = fifty = twenty = ten = five = one =
			quarter = dime = nickel = penny = 0;

	// Second send the change variable to the getCoins
	// function along with pointers for each type of
	// coin. The function will calculate the number of
	// coins to give to the customer and return each
	getCoins(change, &quarter, &dime, &nickel, &penny);

	// Print the number of coins to give to the customer
	if(quarter >= 1)
		printf("Give the customer %d Quarter(s)\n", quarter);

	if(dime >= 1)
		printf("Give the customer %d Dime(s)\n", dime);

	if(nickel >= 1)
		printf("Give the customer %d Nickel(s)\n", nickel);

	if(penny >= 1)
		printf("Give the customer %d Penny(s)\n", penny);
	
	// Initialize the pointers from the coin function to 0
	change = quarter = dime = nickel = penny = 0;

	return 0;
}