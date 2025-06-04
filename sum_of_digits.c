/**
    This program will print the sum of digits of a number
*/

#include <stdio.h>

int main()
{
    int n, digit, sum;

    printf("Enter n: ");
    scanf("%d", &n);

    sum = 0;
    while(n != 0)
    {
        digit = n % 10;
        sum = sum + digit;
        n = n / 10;
    }
    printf("The sum is: %d", sum);

    return 0;
}

