//Name: Arshia Rahim
//Milestone: 4
//Section: SJJ
//Prof: Ian Tipson

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



// Define statements:
#define LINEAR 1
#define FORM 0
#define STOCK 1
#define CHECKOUT 0
#define MAX_ITEM_NO 500
#define MAX_QTY 999
#define SKU_MAX 999
#define SKU_MIN 100
#define DATAFILE "items.txt"



// Constant TAX value:
const double TAX = 0.13;

// Item structure:

struct Item {

	double price;
	int sku;
	int isTaxed;
	int quantity;
	int minQuantity;
	char name[21];

};


// Function Prototypes Milestone 1:
// tools
void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);
// app interface
int yes(void);
void GroceryInventorySystem(void);
int menu(void);




// Function Prototypes Milesone 2:

double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int noOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);


//Function Prototypes Milestone 3:
void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item* itemptr);
void addItem(struct Item item[], int* NoOfRecs, int sku);
void addOrUpdateItem(struct Item item[], int* NoOfRecs);
void adjustQuantity(struct Item item[], int NoOfRecs, int stock);

//function Prototypes Milestone 4:
void saveItem(struct Item item, FILE* dataFile);
int loadItem(struct Item* item, FILE* dataFile);
int saveItems(const struct Item item[], char filename[], int noOfRecs);
int loadItems(struct Item item[], char fileName[], int* NoOfRecsPtr);
// Function Implementations Milestone 1:
void welcome(void) {
	printf("---=== Grocery Inventory System ===---\n\n");
}

//title
void printTitle(void) {
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}

//footer title
void printFooter(double gTotal) {
	printf("--------------------------------------------------------+----------------\n");

	if (gTotal > 0)
		printf("                                           Grand Total: |%12.2lf\n", gTotal);

}

//will wait till you input something then it will countine 
void flushKeyboard(void) {
	while (getchar() != '\n');
}

//will have a quick pause after each section then it will countine by entering
void pause(void) {
	printf("Press <ENTER> to continue...");
	flushKeyboard();
}

int getInt(void) {
	char nL = 'x';
	int value;

	while (nL != '\n') {
		scanf("%d%c", &value, &nL); //&nL only receives the declared nL= x even though I type something character
		if (nL != '\n') {
			while (nL != '\n') {
				flushKeyboard();
				printf("Invalid integer, please try again: ");
				scanf("%d%c", &value, &nL);
			}
		}
	}
	return value;
}

//will set the range of value is avalible for you
int getIntLimited(int lowerLimit, int upperLimit) {

	int valueLimit;
	valueLimit = getInt();
	// Inclusive the lower&upper value
	while (valueLimit < lowerLimit || valueLimit > upperLimit) {
		printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
		valueLimit = getInt();
	}
	return valueLimit;
}

//will ask for new attemp if you input none exist number
double getDouble(void) {
	char nL = 'x';
	double value;

	while (nL != '\n') {
		scanf("%lf%c", &value, &nL);
		if (nL != '\n') {
			while (nL != '\n') {
				flushKeyboard();
				printf("Invalid number, please try again: ");
				scanf("%lf%c", &value, &nL);
			}
		}
	}
	return value;


}

//will give you a chance if you entered a wrong range number
double getDoubleLimited(double lowerLimit, double upperLimit) {

	double valueLimit;
	valueLimit = getDouble();
	while (valueLimit < lowerLimit || valueLimit > upperLimit) {
		printf("Invalid value, %lf <value < %lf: ", lowerLimit, upperLimit);
		valueLimit = getDouble();
	}
	return valueLimit;
}

//will only be accaptable if you input y as a yes or n as a no
int yes(void) {
	char response;
	int result;

	scanf("%c", &response);

	while (response != 'Y' && response != 'y' && response != 'N' && response != 'n') {
		printf("Only (Y)es or (N)o are acceptable: ");

		flushKeyboard();
		scanf("%c", &response);

	}

	if (response == 'Y' || response == 'y')
		result = 1;

	if (response == 'N' || response == 'n')
		result = 0;

	return result;
}

//the menu which shows your selection choices
int menu(void) {
	int number;

	printf("1- List all items\n");
	printf("2- Search by SKU\n");
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("6- delete item\n");
	printf("7- Search by name\n");
	printf("0- Exit program\n");
	printf("> ");

	number = getIntLimited(0, 7);
	return number;

}

//Final Assembly/ this runs all the functions at a time
void GroceryInventorySystem(void) {

	int option, r_records = 0, exit = 0;		//r_recors will read the number of recors it hold

	struct Item item[MAX_ITEM_NO];
	welcome();
	if (loadItems(item, DATAFILE, &r_records) == 0)
	{
		printf("Could not read from %s.\n", DATAFILE);
	}
	else
	{
		do {
			option = menu();

			switch (option) {

			case 1:

				listItems(item, r_records);	//CALLS the function with it exiting data
				pause();

				break;

			case 2:
				search(item, r_records);  //CALLS the function with it exiting data
				pause();

				break;

			case 3:
				adjustQuantity(item, r_records, CHECKOUT);	//CALLS the function with it exiting data

				if (saveItems(item, DATAFILE, r_records) == 0)
				{
					printf("Could not update data file %s\n", DATAFILE);
				}
				pause();
				break;

			case 4:
				adjustQuantity(item, r_records, STOCK);	//CALLS the function  with it exiting data
				if (saveItems(item, DATAFILE, r_records) == 0)
				{
					printf("Could not update data file %s\n", DATAFILE);
				}
				pause();
				break;

			case 5:

				addOrUpdateItem(item, &r_records);	//CALLS the function  with it exiting data
				if (saveItems(item, DATAFILE, r_records) == 0)
				{
					printf("Could not update data file %s\n", DATAFILE);
				}
				pause();
				printf("\n");

				break;

			case 6:

				printf("Not implemented!\n");
				pause();

				break;

			case 7:

				printf("Not implemented!\n");
				pause();

				break;

			case 0:
				printf("Exit the program? (Y)es/(N)o: ");
				if (yes() == 1)

				{
					exit = 1;
				}
				break;
			default:
				printf("Invalid value, 0 < value < 7: ");
				flushKeyboard();
				break;
			}
		} while (exit != 1);
	}
}

// Function Implementations Milestone 2:

//calculate the total amount of money after tax
double totalAfterTax(struct Item item) {

	double totalInventoryPrice;
	//False == 0
	if (item.isTaxed == 0) {
		totalInventoryPrice = (item.price) * ((double)item.quantity); //comment
	}
	//True == 1
	else if (item.isTaxed == 1) {
		totalInventoryPrice = (item.price * (double)item.quantity) + ((item.price * (double)item.quantity) * TAX); //comment
	}

	return totalInventoryPrice;
}

//will search if there is low item in stock
int isLowQuantity(struct Item item) {

	int value = 0;
	if (item.quantity <= item.minQuantity)
		value = 1; //true

	return value;
}

//will ask to input the item your looking for
struct Item itemEntry(int sku) {

	struct Item item;
	printf("        SKU: %d\n", sku);
	printf("       Name: ");
	scanf(" %20[^\n]", item.name);	//comment
	flushKeyboard();
	printf("      Price: ");
	item.price = getDouble();
	printf("   Quantity: ");
	item.quantity = getInt();
	printf("Minimum Qty: ");
	item.minQuantity = getInt();
	printf("   Is Taxed: ");
	item.isTaxed = yes();
	/*comment*/ item.sku = sku; //  Assigning the value 999 to sku variable( after exiting the function, then 999 is not saved; so need to assgin the value again to save)
	flushKeyboard();
	return item;
}

//displays the items detail 
void displayItem(struct Item item, int linear) {
	double totalPrice;
	totalPrice = totalAfterTax(item);


	if (linear == 1) {
		printf("|%3d", item.sku);
		printf("|%-20s", item.name);
		printf("|%8.2lf", item.price);

		if (item.isTaxed == 1) {
			printf("|  Yes");
		}

		else if (item.isTaxed == 0) {
			printf("|   No");
		}

		printf("|%4d ", item.quantity);
		printf("|%4d ", item.minQuantity);
		printf("|%12.2lf|", totalPrice);

		if (item.quantity > item.minQuantity) {
			printf("\n");
		}

		else if (item.quantity <= item.minQuantity) {
			printf("***\n");
		}
	}

	else if (linear == 0) {
		printf("        SKU: %d\n", item.sku);
		printf("       Name: %s\n", item.name);
		printf("      Price: %.2lf\n", item.price);
		printf("   Quantity: %d\n", item.quantity);
		printf("Minimum Qty: %d\n", item.minQuantity);

		if (item.isTaxed == 1) {
			printf("   Is Taxed: Yes\n");
		}

		else if (item.isTaxed == 0) {
			printf("   Is Taxed: No\n");
		}

		if (isLowQuantity(item))
		{
			printf("WARNING: Quantity low, please order ASAP!!!\n");
		}
	}
}

//list the items being selected
void listItems(const struct Item item[], int noOfItems) {

	int counter = 0;
	double grandTototal = 0.0;

	printTitle();
	while (counter < noOfItems) {
		printf("%-4d", counter + 1);
		displayItem(item[counter], LINEAR); //comment
		/*comment*/	grandTototal += totalAfterTax(item[counter]); //add the total price of the current Item element in the array to the grand total value.
		counter++;
	}
	printFooter(grandTototal);
}

//finds and give the address of that item
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index) {

	for (*index = 0; *index < NoOfRecs; (*index)++) {
		if (item[*index].sku == sku) {
			return 1;
		}
	}

	return 0;
}

//Function implementation milestone 3:

//search for the sku number in stock
void search(const struct Item item[], int NoOfRecs)
{
	int s_SKU, i = 0;							//s_sku will search for the sku number
	printf("Please enter the SKU: ");
	s_SKU = getIntLimited(SKU_MIN, SKU_MAX);

	if (locateItem(item, NoOfRecs, s_SKU, &i))	//comment
	{
		displayItem(item[i], FORM);		//comment
	}
	else
	{
		printf("Item not found!");
		printf("\n");
	}
}
//will be able to be edited and get updated
void updateItem(struct Item* itemptr)
{
	struct Item item;
	printf("Enter new data:");
	printf("\n");
	item = itemEntry(itemptr->sku);		//comment
	printf("Overwrite old data? (Y)es/(N)o: ");
	if (yes() == 1)
	{
		*itemptr = item;		//comment

		printf("--== Updated! ==--");
		printf("\n");

	}
	else
	{
		printf("--== Aborted! ==--");
		printf("\n");
	}
}
//lets you add new item to your inventory
void addItem(struct Item item[], int* NoOfRecs, int sku)
{
	struct Item newItem;
	if (*NoOfRecs == MAX_ITEM_NO)
	{
		printf("Can not add new item; ");
		printf("Storage Full!\n");
		return;
	}
	else
	{
		newItem = itemEntry(sku);
		printf("Add Item? (Y)es/(N)o: ");
		int string = yes();
		if (string == 1)
		{
			item[*NoOfRecs] = newItem;	//comment
			(*NoOfRecs)++;	//comment
			printf("--== Added! ==--");
			printf("\n");
		}
		else
		{
			printf("--== Aborted! ==--");
			printf("\n");
		}

	}
}
//will let you add and update your inventory
void addOrUpdateItem(struct Item item[], int* NoOfRecs)
{
	int t_SKU;				//temprary_sku_number	
	int i;
	printf("Please enter the SKU: ");
	t_SKU = getIntLimited(SKU_MIN, SKU_MAX);
	if (locateItem(item, *NoOfRecs, t_SKU, &i)) //comment
	{
		displayItem(item[i], FORM);
		printf("Item already exists, Update? (Y)es/(N)o: ");
		int a = yes();
		if (a == 1)
		{
			updateItem(&item[i]);
		}
		else
		{
			printf("--== Aborted! ==--");
			printf("\n");
		}
	}
	else
	{
		addItem(item, NoOfRecs, t_SKU);
	}
}

//will let you add and remove the amount of item you want
void adjustQuantity(struct Item item[], int NoOfRecs, int stock)
{
	int t_SKU, n, i;			//n = numbers, i = index of content, t_sku = temperary_sku

	printf("Please enter the SKU: ");
	t_SKU = getIntLimited(SKU_MIN, SKU_MAX);
	if (locateItem(item, NoOfRecs, t_SKU, &i))
	{
		displayItem(item[i], FORM);
		if (stock == STOCK)
		{
			printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", "to stock", (MAX_QTY - item[i].quantity));
			n = getIntLimited(0, MAX_QTY - item[i].quantity); //comment
			if (n == 0)
			{
				printf("--== Aborted! ==--");
				printf("\n");
			}
			else
			{
				if (stock == STOCK)
				{
					item[i].quantity = n + item[i].quantity; //comment
					printf("--== Stocked! ==--");
					printf("\n");
				}
			}
		}

		if (stock == CHECKOUT)
		{
			printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", "to checkout", item[i].quantity);
			n = getIntLimited(0, MAX_QTY - item[i].quantity);
			if (n == 0)
			{
				printf("--== Aborted! ==--");
				printf("\n");
			}
			else
			{
				if (stock == CHECKOUT)
				{
					item[i].quantity = item[i].quantity - n;
					printf("--== Checked out! ==--\n");
				}
			}
		}
		if (isLowQuantity(item[i])) //comment
		{
			printf("Quantity is low, please reorder ASAP!!!");
			printf("\n");
		}
	}
	else
	{
		printf("SKU not found in storage!\n");
	}
}

//Function implementation Milestone 4:

void saveItem(struct Item item, FILE* dataFile)					//Will save the data input into text file
{
	/*comment*/	fprintf(dataFile, "%d,%d,%d,%.2lf,%d,%s\n", item.sku, item.quantity, item.minQuantity, item.price, item.isTaxed, item.name);
}

int loadItem(struct Item* item, FILE* dataFile)					//It will look up for the item in text file to be find
{
	int flag;
	if (fscanf(dataFile, "%d,%d,%d,%lf,%d,%[^\n]s", &item->sku, &item->quantity, &item->minQuantity, &item->price, &item->isTaxed, item->name) == 6)
	{
		flag = 1;
	}
	else
	{
		flag = 0;
	}
	return flag;
}

int saveItems(const struct Item item[], char fileName[], int NoOfRecs)		//This will save multiple data's into text file
{
	int index, flag;
	FILE* fp = NULL; fp = fopen(fileName, "w");

	if (fp != NULL)
	{

		for (index = 0; index < NoOfRecs; index++)
		{
			saveItem(item[index], fp);

		}
		fclose(fp);
		flag = 1;
	}

	else
	{
		flag = 0;
	}
	return flag;
}

int loadItems(struct Item item[], char fileName[], int* NoOfRecsPtr)	//this will search up for multiple datas in text file
{
	int i = 0, temps = 0, flag;
	FILE* fp = NULL;
	fp = fopen(fileName, "r");
	if (fp != NULL)
	{
		temps = loadItem(&item[i], fp);				//comment

		while (temps)
		{
			i++;
			temps = loadItem(&item[i], fp);
		}
		*NoOfRecsPtr = i;
		flag = 1;
		fclose(fp);
	}

	else
	{
		flag = 0;
	}
	return flag;
}
//calls the main function and it groceryInventorySystem functions included
int main(void)
{
	GroceryInventorySystem();
	return 0;
}