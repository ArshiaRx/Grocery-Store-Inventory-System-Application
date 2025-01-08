#include <stdio.h>

int main(void)

{
	float Money;

	printf("How much money do you have in your pockets ? ");
	scanf("%f", &Money);

	printf("The amount of money in your pockets is $%.2f\n", Money);

	return 0;
}