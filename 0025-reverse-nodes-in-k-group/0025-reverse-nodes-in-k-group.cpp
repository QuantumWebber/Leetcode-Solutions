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
    ListNode* reverseKGroup(ListNode* head, int k) {


        //check if we have k groups or not 

        ListNode* curr=head;
        int count=0;
        while(curr!=nullptr && count<k){
            curr=curr->next;
            count++;
        }


        //if k nodes reverse them 

        if(count==k){
            ListNode* prev=nullptr;
            ListNode*forward=nullptr;
            int c=0;
            curr=head;


            while(c<k){
                forward=curr->next;
                curr->next=prev;
                prev=curr;
                curr=forward;

                c++;
            }



            //recursiveley next group

            if(forward!=nullptr){
                head->next=reverseKGroup(forward,k);
            }
            return prev;

        }

        //else not k group 
        return head;
        
    }
};