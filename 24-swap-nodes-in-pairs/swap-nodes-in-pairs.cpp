class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Dummy node to simplify edge cases
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            // Swap
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move prev forward for next swap
            prev = first;
        }

        return dummy.next;
    }
};
