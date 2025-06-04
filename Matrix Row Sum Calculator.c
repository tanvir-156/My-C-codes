/**
    Adding the rows of a matrix
*/

#include <stdio.h>

int main()
{
    int m[4][4];
    int i, j, sum;

    printf("The contents of the matrix are:\n");
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            m[i][j] = rand() % 10;
            printf("\t%d", m[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<4; i++)
    {
        sum = 0;
        for(j=0; j<4; j++)
            sum += m[i][j];
        printf("\nSum of row %d: %d", i+1, sum);
    }

    return 0;
}
