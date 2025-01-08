/*
Name: Arshia Rahim
Student number: 112142161
Email: arahim5
Workshop: 7
Section: SJJ
Date: 2017/03/21
*/
#include <stdio.h>
#define MAX_SIZE 3


//prototype functions below
int decompose(const long long phoneNumber, int *area, int *prefix, int *line);

//implement functions below
int decompose(const long long phoneNumber, int *area, int *prefix, int *line) {

	*area = phoneNumber / 10000000;
	*prefix = (phoneNumber % 10000) % 1000;
	*line = phoneNumber % 10000;

	return 0;
}

/* main program */
int main(void) {

	int option;
	int n_Numbers = 0, area = 0, prefix = 0, line = 0;
	int i = 0;
	long long phoneNumber[MAX_SIZE] = { 0LL, 0LL, 0LL };



	printf("---=== Phone Numbers ===---\n\n");

	do {
		// Display the Option List
		printf("1. Display Phone List\n");
		printf("2. Add a Number\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:	// Exit the program
			printf("Exiting Phone Number App. Good Bye!!!");
			printf("\n");
			break;


		case 1: // Display the Phone List
				// @IN-LAB
			printf("Phone Numbers\n");
			printf("==============\n");
			// Display each number in decomposed form

			for (i = 0; i < MAX_SIZE; i++) {
				if (phoneNumber[i] > 0) {
					decompose(phoneNumber[i], &area, &prefix, &line);
					printf("(%3d)-%3d-%4d\n", area, prefix, line);
				}
			}
			printf("\n");
			break;

		case 2:	// Add a Phone Number
				// @IN-LAB
			printf("Add a Number\n");
			printf("============\n");

			if (n_Numbers < MAX_SIZE) {
				scanf("%lld", &n_Numbers);
				n_Numbers++;
				printf("\n");
			}
			else {
				printf("ERROR!!! Phone Number List is Full\n\n");
			}
			break;

		default:
			printf("ERROR!!!: Incorrect Option: Try Again\n\n");

			break;
		}


	} while (option != 0);

	return 0;
}

// Program Input/Output
/*

---=== Phone Numbers ===---

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 1

Phone Numbers
==============

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 2

Add a Number
============
4164915050

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 2

Add a Number
============
9052301212

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 2

Add a Number
============
6475551212

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 1

Phone Numbers
==============
(416)-491-5050
(905)-230-1212
(647)-555-1212

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 2

Add a Number
============
ERROR!!! Phone Number List is Full

1. Display Phone List
2. Add a Number
0. Exit

Please select from the above options: 0

Exiting Phone Number App. Good Bye!!!

*/

