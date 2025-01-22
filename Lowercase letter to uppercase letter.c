#include<stdio.h>
int main()
{
	char ch;
	printf("Enter a lowercase letter: ");
	scanf("%c",&ch);
	ch=ch-32;
	printf("Uppercase letter is %c",ch);
	return 0;
}
