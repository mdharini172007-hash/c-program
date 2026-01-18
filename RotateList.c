/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next || k == 0)
        return head;

    // Step 1: find length and tail
    struct ListNode *tail = head;
    int len = 1;
    while (tail->next) {
        tail = tail->next;
        len++;
    }

    k = k % len;
    if (k == 0) return head;

    // Step 2: make circular
    tail->next = head;

    // Step 3: find new tail (len - k - 1)
    int steps = len - k;
    struct ListNode *newTail = head;
    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    struct ListNode *newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}