#include "apc.h"

int division(Dlist *head1, Dlist *head2, Dlist **headR, int sign1, int sign2)
{
    if (!head1 || !head2 || !headR) return FAILURE;

    // Division by zero check
    if (head2->digit == '0' && !head2->next) {
        printf("Division by zero error\n");
        return FAILURE;
    }

    Dlist *dividend = NULL;
    for (Dlist *t = head1; t; t = t->next)
        insert_at_last(&dividend, t->digit);

    Dlist *divisor = head2;
    Dlist *quotient = NULL;
    Dlist *temp = NULL;

    for (Dlist *cur = dividend; cur; cur = cur->next) {
        insert_at_last(&temp, cur->digit);

        int count = 0;
        while (compare_lists(temp, divisor) >= 0) {
            Dlist *sub_res = subtract_lists(temp, divisor);
            free_list(&temp);
            temp = sub_res;
            count++;
        }

        insert_at_last(&quotient, count + '0');
    }

    // Remove leading zeros
    while (quotient && quotient->digit == '0' && quotient->next) {
        Dlist *tmp = quotient;
        quotient = quotient->next;
        quotient->prev = NULL;
        free(tmp);
    }

    // Apply sign
    if (sign1 * sign2 == -1)
        insert_at_first(&quotient, '-');

    *headR = quotient;

    free_list(&temp);
    free_list(&dividend);

    return SUCCESS;
}