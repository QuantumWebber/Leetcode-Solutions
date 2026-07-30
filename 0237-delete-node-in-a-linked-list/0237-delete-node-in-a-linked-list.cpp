/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node==NULL || node->next==NULL){
            return;
        }

        ListNode* newNode=node->next;
        node->val=newNode->val;
        node->next=newNode->next;
        delete newNode;
    }
};