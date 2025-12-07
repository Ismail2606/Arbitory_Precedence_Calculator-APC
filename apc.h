#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct Dlist {
    char digit;
    struct Dlist *prev;
    struct Dlist *next;
} Dlist;

/* Linked list utility functions */
Dlist* create_node(char digit);
void insert_at_first(Dlist **head, char digit);
void insert_at_last(Dlist **head, char digit);
void print_list(Dlist *head);
void free_list(Dlist **head);
int compare_lists(Dlist *head1, Dlist *head2);
Dlist* subtract_lists(Dlist *minuend, Dlist *subtrahend);
int is_zero(Dlist *head);

/* Conversion from command line argument to list */
int CLA_to_list(const char *arg, Dlist **head, int *sign);
int validate_argv(int argc, char *argv[]);
int validate_number(const char *str);
int validate_operator(char *op);

/* Arithmetic operations */
int addition(Dlist *head1, Dlist *head2, Dlist **headR, int sign1, int sign2);
int subtraction(Dlist *head1, Dlist *head2, Dlist **headR, int sign1, int sign2);
int multiplication(Dlist *head1, Dlist *head2, Dlist **headR, int sign1, int sign2);
int division(Dlist *head1, Dlist *head2, Dlist **headR, int sign1, int sign2);

#endif
