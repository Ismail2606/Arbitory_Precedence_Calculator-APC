#include "apc.h"

/* Validate a number string (allow optional + or - at start) */
int validate_number(const char *str) {
    if (!str || !*str) return FAILURE;

    int i = 0;
    if (str[0] == '+' || str[0] == '-') i++;  // Optional sign

    if (str[i] == '\0') return FAILURE; // No digits after sign

    for (; str[i]; i++) {
        if (!isdigit(str[i])) return FAILURE;
    }

    return SUCCESS;
}

/* Validate operator string (should be single char + - * /) */
int validate_operator(char *op) {
    if (!op || op[0] == '\0') return FAILURE;

    char c = op[0];

    if (c == '+' || c == '-' || c == '/' ) {
        return SUCCESS;
    }
    else if (c == 'X' || c == 'x') {
        op[0] = '*';  // safely modify argv string
        return SUCCESS;
    }

    return FAILURE;
}


/* Validate full argv (num1, operator, num2) */
int validate_argv(int argc, char *argv[]) {
    if (argc != 4) return FAILURE;

    if (validate_number(argv[1]) == FAILURE) return FAILURE;
    if (validate_operator(argv[2]) == FAILURE) return FAILURE;
    if (validate_number(argv[3]) == FAILURE) return FAILURE;

    return SUCCESS;
}
