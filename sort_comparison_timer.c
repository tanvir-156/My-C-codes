#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 50000 

int temp;          
int t[SIZE];       
clock_t start, end;
double totalTime;

void bubbleSort(int a[]);
void bubbleSortImproved(int a[]);
void selectionSort(int a[]);

int main() {
    int a[SIZE];
    int i;

    srand(time(0));
    for(i = 0; i < SIZE; i++)
        a[i] = (rand() % 10000) - 1000;
    
    for(i = 0; i < SIZE; i++)
        t[i] = a[i];

    bubbleSort(a);  
    
    for(i = 0; i < SIZE; i++)
        a[i] = (rand() % 10000) - 1000;
    
    bubbleSortImproved(a);  
    
    for(i = 0; i < SIZE; i++)
        t[i] = a[i];

    selectionSort(a); 

    return 0;
}

void bubbleSort(int a[]) {
    int i, j;
    printf("Bubble sort in progress. Please wait ...\n");
    start = clock();

    for(i = 0; i < SIZE - 1; i++) {
        for(j = 0; j < SIZE - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                temp = a[j];          
                a[j] = a[j + 1];
                a[j + 1] = temp;      
            }
        }
    }

    end = clock();
    totalTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time required for Bubble Sort: %.2lf seconds.\n\n", totalTime);
}

void bubbleSortImproved(int a[]) {
    int i, j, swap;
    printf("Bubble sort (improved) in progress. Please wait ...\n");
    start = clock();

    for(i = 0; i < SIZE - 1; i++) {
        swap = 0;
        for(j = 0; j < SIZE - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                temp = a[j];          
                a[j] = a[j + 1];
                a[j + 1] = temp;     
                swap = 1;
            }
        }
        if(swap == 0)
            break;
    }

    end = clock();
    totalTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time required for Improved Bubble Sort: %.4lf seconds.\n\n", totalTime);
}

void selectionSort(int a[]) {
    int i, j, pos;
    printf("Selection sort in progress. Please wait ...\n");
    start = clock();

    for(i = 0; i < SIZE - 1; i++) {
        pos = i;
        for(j = i + 1; j < SIZE; j++) {
            if(a[j] < a[pos])
                pos = j;
        }
        if(pos != i) {
            temp = a[i];          
            a[i] = a[pos];
            a[pos] = temp; 
        }
    }

    end = clock();
    totalTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time required for Selection Sort: %.4lf seconds.\n\n", totalTime);
}
