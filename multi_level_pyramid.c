#include <stdio.h>

int main() {
    int size, numPyramids;
    
    printf("Size: ");
    scanf("%d", &size);
    
    printf("Level: ");
    scanf("%d", &numPyramids);

    for (int row = 1; row <= numPyramids; row++) {
        for (int i = 1; i <= size; i++) { 
            int spacesBefore = (numPyramids - row) * size + (size - i);

            for (int j = 0; j < spacesBefore; j++) printf(" ");

            for (int m = 0; m < row; m++) {
                printf("/");
                for (int k = 0; k < (i - 1) * 2; k++) 
                    printf(i == size ? "_" : " ");
                printf("\\");
                
                if (m < row - 1)
                    for (int j = 0; j < size - i; j++) printf("  ");
            }
            printf("\n");
        }
    }
    return 0;
}
