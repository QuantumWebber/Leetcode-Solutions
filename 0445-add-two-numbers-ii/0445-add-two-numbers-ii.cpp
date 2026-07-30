/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    // Reverse the linked list
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* forward = nullptr;

        while (curr != nullptr) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    // Insert at tail of result list
    void insertAtTail(ListNode* &head, ListNode* &tail, int data) {
        ListNode* temp = new ListNode(data);
        if (head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    // Actual addition logic
    ListNode* add(ListNode* l1, ListNode* l2) {
        ListNode* ansHead = nullptr;
        ListNode* ansTail = nullptr;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
            int sum = val1 + val2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            insertAtTail(ansHead, ansTail, digit);

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        return ansHead;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Step 1: Reverse both lists
        l1 = reverse(l1);
        l2 = reverse(l2);

        // Step 2: Add the reversed lists
        ListNode* result = add(l1, l2);

        // Step 3: Reverse the result to get final answer
        result = reverse(result);
        return result;
    }
};
