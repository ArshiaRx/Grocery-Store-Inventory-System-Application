/*
Name: Arshia Rahim
Student number: 112142161
Email: Arahim5@myseneca.ca
Workshop: 4
Section: SJJ
Date: 2017/feb/8
*/

#include <stdio.h>

int main()
{
	int numdays;
	int i;
	int high[10];
	int low[10];


	printf("---=== IPC Temperature Analyzer V2.0 ===---\n");

	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &numdays);
	printf("\n");

	while (numdays < 3 || numdays > 10)
	{
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &numdays);
		printf("\n");
	}

	for (i = 0; i < numdays; i++)
	{
		printf("Day %d - High: ", i + 1);
		scanf("%d", &high[i]);
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &low[i]);
	}
	
	printf("\n");
	printf("Day  Hi  Low\n");

	for (i = 0; i < numdays; i++)
	{
		printf("%d    %d    %d\n", i + 1, high[i], low[i]);

	}

	return 0;
}