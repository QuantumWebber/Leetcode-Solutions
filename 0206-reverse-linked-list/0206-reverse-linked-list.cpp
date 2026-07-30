class Solution {
private:
    void reverse(ListNode*& head, ListNode* curr, ListNode* prev) {
        // base case
        if (curr == nullptr) {
            head = prev;  // update the head to the new head (prev)
            return;
        }

        ListNode* forward = curr->next;
        reverse(head, forward, curr); // recurse forward
        curr->next = prev; // reverse the link
    }

public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        reverse(head, curr, prev);
        return head;
    }
};