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
    int length(ListNode* head) {
        int len = 0;
        while (head != nullptr) {
            head = head->next;
            len++;
        }
        return len;
    }

public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (!head) return nullptr;

        // Find length of the list
        int size = length(head);

        // Find the k-th node from the start
        ListNode* first = head;
        for (int i = 1; i < k; i++) {
            first = first->next;
        }

        // Find the k-th node from the end
        ListNode* second = head;
        for (int i = 1; i <= size - k; i++) {
            second = second->next;
        }

        // Swap the values of the two nodes
        swap(first->val, second->val);

        return head;
    }
};