class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;  // Return if the list is empty or has only one node

        ListNode* oddHead = head;                // Start with the head for odd indexed nodes
        ListNode* evenHead = head->next;        // The second node is the start for even indexed nodes
        ListNode* oddTail = oddHead;             // Tail for odd indexed nodes
        ListNode* evenTail = evenHead;           // Tail for even indexed nodes
        
        while (evenTail && evenTail->next) {
            oddTail->next = evenTail->next;     // Link the next odd indexed node
            oddTail = oddTail->next;             // Move the odd tail pointer
            evenTail->next = oddTail->next;     // Link the next even indexed node
            evenTail = evenTail->next;           // Move the even tail pointer
        }

        oddTail->next = evenHead;                // Merge the odd and even lists
        return oddHead;                          // Return the head of the rearranged list
    }
};