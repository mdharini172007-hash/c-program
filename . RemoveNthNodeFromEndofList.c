#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *fast = &dummy;
    struct ListNode *slow = &dummy;

    // Move fast pointer n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // Move both pointers
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Remove the nth node
    struct ListNode *temp = slow->next;
    slow->next = slow->next->next;
    free(temp);

    return dummy.next;
}
