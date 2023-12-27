#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int operand1, operand2; // Input values
    int result = 0;
    char operation;

    // Get the inputs 
    printf("Enter the first operand: ");
    scanf("%d", &operand1);

    printf("Enter the operation to perform (+, -, *, /): ");
    scanf("\n%c", &operation);

    printf("Enter the second operand: ");
    scanf("%d", &operand2);

    // Perform the calculation
    switch (operation)
    {
    case '+':
        result = operand1 + operand2;
        break;
    
    case '-':
        result = operand1 - operand2;
        break;

    case '*':
        result = operand1 * operand2;
        break;

    case '/':
        if (operand2 != 0){
            result = operand1 / operand2;
        }
        else {
            printf("Divide by 0 error!\n");
        }
        break;

    default:
        printf("Invalid operation!\n");
        break;
    }

    printf("The answer is %d\n", result);

}