#include "apc.h"

Dlist* create_node(char digit) {
    Dlist *node = (Dlist*)malloc(sizeof(Dlist));
    if (!node) return NULL;
    node->digit = digit;
    node->prev = node->next = NULL;
    return node;
}

void insert_at_first(Dlist **head, char digit) {
    Dlist *node = create_node(digit);
    if (!node) return;
    node->next = *head;
    if (*head) (*head)->prev = node;
    *head = node;
}

void insert_at_last(Dlist **head, char digit) {
    Dlist *node = create_node(digit);
    if (!node) return;
    if (!*head) { *head = node; return; }
    Dlist *temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = node;
    node->prev = temp;
}

void print_list(Dlist *head) {
    while (head) { putchar(head->digit); head = head->next; }
}

void free_list(Dlist **head) {
    Dlist *temp;
    while (*head) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int CLA_to_list(const char *arg, Dlist **head, int *sign) {
    if (!arg || !head || !sign) return FAILURE;

    *sign = 1;
    int i = 0;
    if (arg[0] == '-') { *sign = -1; i++; }
    else if (arg[0] == '+') i++;

    for (; arg[i]; i++) {
        if (!isdigit(arg[i])) return FAILURE;
        insert_at_last(head, arg[i]);
    }

    if (!*head) return FAILURE;
    return SUCCESS;
}

int compare_lists(Dlist *head1, Dlist *head2) {
    int len1 = 0, len2 = 0;
    Dlist *t;

    for (t = head1; t; t = t->next) len1++;
    for (t = head2; t; t = t->next) len2++;

    if (len1 > len2) return 1;
    if (len1 < len2) return -1;

    while (head1 && head2) {
        if (head1->digit > head2->digit) return 1;
        if (head1->digit < head2->digit) return -1;
        head1 = head1->next;
        head2 = head2->next;
    }
    return 0;
}

// Subtract two positive lists: head1 >= head2
Dlist* subtract_lists(Dlist *head1, Dlist *head2) {
    Dlist *res = NULL;
    subtraction(head1, head2, &res, 1, 1);
    return res;
}

