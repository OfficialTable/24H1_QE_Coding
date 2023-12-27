#include <stdio.h>

// Declaration
int Factorial(int n);

int main(void) {

    int number;
    int answer;
    printf("Input a number: ");
    scanf("%d", &number);

    // Call 
    answer = Factorial(number);
    printf("The factorial of %d is %d\n", number, answer);
} 

// Definition
int Factorial(int n) {
    int result = 1;
    for (int i=1; i<=n; i++){
        result *= i;
    }
    return result;
}