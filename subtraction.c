#include "apc.h"

int subtraction(Dlist *head1, Dlist *head2, Dlist **headR, int sign1, int sign2) {
    if (!head1 || !head2 || !headR) return FAILURE;

    Dlist *p1 = head1;
    Dlist *p2 = head2;
    int borrow = 0;

    while (p1 && p1->next) p1 = p1->next;
    while (p2 && p2->next) p2 = p2->next;

    while (p1) {
        int diff = (p1->digit - '0') - borrow;
        if (p2) { diff -= (p2->digit - '0'); p2 = p2->prev; }

        if (diff < 0) { diff += 10; borrow = 1; }
        else borrow = 0;

        insert_at_first(headR, diff + '0');
        p1 = p1->prev;
    }

    while (*headR && (*headR)->digit == '0' && (*headR)->next) {
        Dlist *temp = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        free(temp);
    }

    if (sign1 * sign2 == -1) insert_at_first(headR, '-');
    return SUCCESS;
}