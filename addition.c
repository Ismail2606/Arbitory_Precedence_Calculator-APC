#include "apc.h"

int addition(Dlist *head1, Dlist *head2, Dlist **headR, int sign1, int sign2)
{
    if (!head1 || !head2 || !headR) return FAILURE;

    if (sign1 == sign2) {
        // Same signs → simple addition
        Dlist *p1 = head1;
        Dlist *p2 = head2;
        int carry = 0;

        while (p1 && p1->next) p1 = p1->next;
        while (p2 && p2->next) p2 = p2->next;

        while (p1 || p2 || carry) {
            int sum = carry;
            if (p1) { sum += p1->digit - '0'; p1 = p1->prev; }
            if (p2) { sum += p2->digit - '0'; p2 = p2->prev; }
            insert_at_first(headR, (sum % 10) + '0');
            carry = sum / 10;
        }

        // Apply sign only if result is non-zero
        if (sign1 == -1 ) insert_at_first(headR, '-');
    }
    else {
        // Different signs → subtraction
        int cmp = compare_lists(head1, head2);
        if (cmp == 0) {
            insert_at_last(headR, '0'); // Result is zero
        }
        else if (cmp > 0) {
            subtraction(head1, head2, headR, 1, 1); // |head1| > |head2|
            if (sign1 == -1) insert_at_first(headR, '-');
        }
        else {
            subtraction(head2, head1, headR, 1, 1); // |head2| > |head1|
             if (sign2 == -1) insert_at_first(headR, '-');
        }
    }

    return SUCCESS;
}
