#include "apc.h"

int multiplication(Dlist *head1, Dlist *head2, Dlist **headR, int sign1, int sign2)
{
    if (!head1 || !head2 || !headR) return FAILURE;

    // Get lengths
    int len1 = 0, len2 = 0;
    Dlist *temp;
    for (temp = head1; temp; temp = temp->next) len1++;
    for (temp = head2; temp; temp = temp->next) len2++;

    int *num1 = (int*)calloc(len1, sizeof(int));
    int *num2 = (int*)calloc(len2, sizeof(int));
    if (!num1 || !num2) return FAILURE;

    // Fill arrays in normal order
    temp = head1;
    for (int i = 0; i < len1; i++) { num1[i] = temp->digit - '0'; temp = temp->next; }

    temp = head2;
    for (int i = 0; i < len2; i++) { num2[i] = temp->digit - '0'; temp = temp->next; }

    int *res = (int*)calloc(len1 + len2, sizeof(int));
    if (!res) { free(num1); free(num2); return FAILURE; }

    // Multiply like grade-school method
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            res[i + j + 1] += num1[i] * num2[j];
        }
    }

    // Handle carry
    for (int i = len1 + len2 - 1; i > 0; i--) {
        res[i - 1] += res[i] / 10;
        res[i] %= 10;
    }

    // Skip leading zeros
    int start = 0;
    while (start < len1 + len2 - 1 && res[start] == 0) start++;

    // Insert into result list
    for (int i = start; i < len1 + len2; i++)
        insert_at_last(headR, res[i] + '0');

    // Apply sign
    if (sign1 * sign2 == -1)
        insert_at_first(headR, '-');

    free(num1); free(num2); free(res);
    return SUCCESS;
}
