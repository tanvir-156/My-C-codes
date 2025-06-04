#include <stdio.h>
#include <math.h>

int main() {
    int lower, upper, count = 0, twinCount = 0;

    printf("\t\t\tPRIME GENERATOR\n");

    printf("Enter lower limit: ");
    scanf("%d", &lower);
    printf("Enter upper limit: ");
    scanf("%d", &upper);

    printf("\nThe prime numbers between %d and %d are:\n", lower, upper);

    int previousPrime = -1;

    for (int i = lower; i <= upper; i++) {
        int isPrime = 1;

        if (i <= 1) {
            isPrime = 0;
        } else if (i == 2 || i == 3) {
            isPrime = 1;
        } else if (i % 2 == 0 || i % 3 == 0) {
            isPrime = 0;
        } else {
            for (int j = 5; j <= sqrt(i); j += 6) {
                if (i % j == 0 || i % (j + 2) == 0) {
                    isPrime = 0;
                    break;
                }
            }
        }

        if (isPrime) {
            printf("%d ", i);
            count++;
            if (previousPrime != -1 && i - previousPrime == 2) {
                twinCount++;
                printf("(Twin with %d)", previousPrime);
            }
            previousPrime = i;
        }
    }

    printf("\n\nThere are %d prime numbers between %d and %d.\n", count, lower, upper);
    printf("There are %d pairs of twin primes between %d and %d.\n", twinCount, lower, upper);

    return 0;
}
