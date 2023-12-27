#include <stdio.h>

// Declaration
void swap(int firstVal, int secondVal);

int main(void) {
    int valA = 7;
    int valB = 5;

    printf("Before  : valA = %d, valB = %d\n", valA, valB);

    swap(valA, valB);
    printf("After   : valA = %d, valB = %d\n", valA, valB);

    printf("Swap does not happen!!!");
    
    return 0;
} 

// Definition

void swap(int firstVal, int secondVal){
    int tempVal;
    tempVal = firstVal;
    firstVal = secondVal;
    secondVal = tempVal;
    printf("In Swap : valA = %d, valB = %d\n", firstVal, secondVal);
}