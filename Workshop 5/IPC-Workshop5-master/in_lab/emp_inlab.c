/*
Name: Arshia Rahim
Student number: 112142161
Email: arahim5@myseneca.ca
Workshop: 5
Section: SJJ
Date: 2017/Feb/15
*/

#include <stdio.h>

// Define Number of Employees "SIZE" to be 2

#define SIZE 2	

// Declare Struct Employee
struct Employee {
	int empID;
	int empAge;
	double empSalary;
};


/* main program */
int main(void) {

	
	int option = 0;
	int i;
	int empn = 0;
	printf("---=== EMPLOYEE DATA ===---\n\n");

	// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero
	struct Employee emps[SIZE] = { { 0,0,0 },{ 0,0,0 } };

	do {
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		
		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:	// Exit the program
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;
		case 1: // Display Employee Data
				// @IN-LAB

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			for (i = 0; i < SIZE; i++)
			{
				printf("%6d%9d%11.2lf\n", emps[i].empID, emps[i].empAge, emps[i].empSalary);
			}
			// Use "%6d%9d%11.2lf" formatting in a   
			// printf statement to display
			// employee id, age and salary of 
			// all  employees using a loop construct 
			printf("\n");
			// The loop construct will be run for SIZE times 
			// and will only display Employee data 
			// where the EmployeeID is > 0
			break;
		case 2:	// Adding Employee
				// @IN-LAB

			printf("Adding Employee\n");
			printf("===============\n");

			if (empn < SIZE)
				{
					printf("Enter Employee ID: ");
					scanf("%d", &emps[empn].empID);
					printf("Enter Employee Age: ");
					scanf("%d", &emps[empn].empAge);
					printf("Enter Employee Salary: ");
					scanf("%lf", &emps[empn].empSalary);
					empn = empn + 1;
					printf("\n");
				}
				else 
				{
					printf("ERROR!!! Maximum Number of Employees Reached\n\n");
				}
			
			// Check for limits on the array and add employee 
			// data accordingly. 

		

			break;
		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);


	return 0;
}



//PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 111
Enter Employee Age: 34
Enter Employee Salary: 78980.88

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 112
Enter Employee Age: 41
Enter Employee Salary: 65000

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
111       34   78980.88
112       41   65000.00

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!

*/

