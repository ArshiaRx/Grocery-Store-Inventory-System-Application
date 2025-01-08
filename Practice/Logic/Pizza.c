// Pizza
//if logic

#include <stdio.h>

int main(Void)

{
	int pizza;

	printf("How many pizza do you want? \n");
	scanf("%d", &pizza);

	if (pizza == 1)
		printf("I like pizza\n");
	else
		printf("I hate pizza\n");
	
	return 0;
}