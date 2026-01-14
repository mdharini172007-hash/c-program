struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (!head || k == 1) return head;

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *prev = &dummy;
    struct ListNode *curr = head;
    struct ListNode *next = NULL;

    // Count total nodes
    int count = 0;
    while (curr) {
        count++;
        curr = curr->next;
    }

    curr = head;

    while (count >= k) {
        struct ListNode *tail = curr;
        struct ListNode *prevNode = NULL;

        // Reverse k nodes
        for (int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = next;
        }

        // Connect reversed group
        prev->next = prevNode;
        tail->next = curr;

        // Move prev to tail
        prev = tail;

        count -= k;
    }

    return dummy.next;
}
s