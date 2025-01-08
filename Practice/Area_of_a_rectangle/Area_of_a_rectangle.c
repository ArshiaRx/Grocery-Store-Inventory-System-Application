#include <stdio.h>

int main(void)
{
	float Width;
	float Length;
	float area;

	printf("What's The Length of your Rectangle? ");
	scanf("%f", &Width);
	printf("What's The Width of your Rectangle? ");
	scanf("%f", &Length);

	area = Width * Length;

	printf("The area of Rectangle is %.2f\n", area);

	return 0;
}

