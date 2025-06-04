

#include <stdio.h>
#include <math.h>

void decimal_to_binary();
void binary_to_decimal();

int main()
{
	int choice;

	printf("\tWelcome to Number Base Converter\n");
	printf("\t================================\n");

	do {
		printf("\n\n1. Decimal to Binary\n");
		printf("2. Binary to Decimal\n");
		printf("3. Exit\n");
		printf("\n\nEnter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				decimal_to_binary();
				break;
			case 2:
				binary_to_decimal();
				break;
			default:
				return 0;
		}
	} while (1);

	return 0;
}

void decimal_to_binary()
{
	int decimal, binary = 0, base = 1, remainder;
	
	printf("Enter a decimal number: ");
	scanf("%d", &decimal);

	while (decimal > 0)
	{
		remainder = decimal % 2;
		binary += remainder * base;
		base *= 10;
		decimal /= 2;
	}

	printf("Equivalent binary number is: %d\n", binary);
}

void binary_to_decimal()
{
	int binary, decimal = 0, base = 0, remainder;
	
	printf("Enter a binary number: ");
	scanf("%d", &binary);

	while (binary > 0)
	{
		remainder = binary % 10;
		decimal += remainder * pow(2, base);
		base++;
		binary /= 10;
	}

	printf("Equivalent decimal number is: %d\n", decimal);
}

