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
public:
    void reorderList(ListNode* head) {


        // find middle
        if(!head || !head->next || !head->next->next ) return;


        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }


        // ab slow middle pr hai second half ko reverse krdo 

        ListNode* curr=slow->next;

        slow->next=nullptr;  //NULL->second list
        ListNode* prev=nullptr;
        ListNode* forward=nullptr;


        while(curr!=nullptr){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }




        // merge twp halves alternatively 

        ListNode* first=head;

        ListNode* second=prev;


        while(second!=nullptr){
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;


            first->next=second;
            second->next=temp1;



            first=temp1;
            second=temp2;
        }
        
    }
};