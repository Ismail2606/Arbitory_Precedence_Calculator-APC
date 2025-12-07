/*
Project: Arbitory Precedence Calculator
Author: Ismail Pasha
Module: Data Structures and Algorithms
Description: This is the main file for the APC project which performs basic arithmetic operations on large numbers
*/

#include "apc.h"

int main(int argc, char *argv[])
{
    if (argc != 4) {
        printf("Usage: %s <num1> <operator> <num2>\n", argv[0]);
        return FAILURE;
    }

    Dlist *num1 = NULL, *num2 = NULL, *result = NULL;
    int sign1 = 1, sign2 = 1;

    // Convert command line arguments to lists
    if (validate_argv(argc, argv) == FAILURE) {
        printf("Invalid input.\n");
        return FAILURE;
    }

    if (CLA_to_list(argv[1], &num1, &sign1) == FAILURE ||
        CLA_to_list(argv[3], &num2, &sign2) == FAILURE) {
        printf("Error converting CLA to lists.\n");
        return FAILURE;
    }

    char op = argv[2][0];
    int status = FAILURE;
    switch (op) {
        case '+':
            status = addition(num1, num2, &result, sign1, sign2);
            printf("Addition successful.\n");
            break;
        case '-':
            status = subtraction(num1, num2, &result, sign1, sign2);
            printf("Subtraction successful.\n");
            break;
        case '*':
            status = multiplication(num1, num2, &result, sign1, sign2);
            printf("Multiplication successful.\n");
            break;
        case '/':
            status = division(num1, num2, &result, sign1, sign2);
            printf("Division successful.\n");
            break;
        default:
            printf("Unsupported operator %c\n", op);
            return FAILURE;
    }

    if (status == FAILURE) {
        printf("Operation failed.\n");
        return FAILURE;
    }

    printf("Result: ");
    print_list(result);
    printf("\n");

    free_list(&num1);
    free_list(&num2);
    free_list(&result);

    return SUCCESS;
}
