#include<stdio.h>
int main()
{ 
    int a, sum=0;
    
    for(a=1; a<=100; a++){

        if(a % 2 == 0) {
            sum += a;  
        }
    }
    
    printf("Sum of all even integers is %d", sum);
}
