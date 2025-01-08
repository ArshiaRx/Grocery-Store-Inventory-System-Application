// Area of a Triangle
//Area_Triangle.c

#include <stdio.h>

int main(void)
{
	int height;
	int base;
	int area;

	printf("Enter Height : ");
	scanf("%d", &height);

	printf("Enter Base : ");
	scanf("%d", &base);

	area = height * base / 2;

	printf("Area of Triangle is %d\n", area);

	return 0;
}