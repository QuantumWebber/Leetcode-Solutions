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
    ListNode* findMid(ListNode*head){
        //tortoise Hare method
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
           
        }
         return slow;
    }

    // merge wala code divide and conquer approach wala 
    ListNode* merge(ListNode* left,ListNode*right){
        if(left==NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }
       ListNode* ans =new ListNode(-1);
       ListNode* temp=ans;

       while(left!=NULL && right!=NULL){
        if(left->val<right->val){
            temp->next=left;
            temp=left;
            left=left->next;
        }else{
            temp->next=right;
            temp=right;
            right=right->next;
        }
       }

       while(left!=NULL)
       {
           temp->next=left;
           temp=left;
           left=left->next;
       }

       while(right!=NULL){
        temp->next=right;
        temp=right;
        right=right->next;

       }

       ans =ans->next;
       return ans ;


    }

public:
    ListNode* sortList(ListNode* head) {
        // dekho jee logic to whi hai konsa array ke merge sort wala 
        // middle nikalo 
        // left right do group ko merge krdo
                if (head == NULL || head->next == NULL) return head;

        ListNode* mid=findMid(head);
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;


        left = sortList(left);
    right = sortList(right);



    ListNode* result = merge(left, right);
    return result;
    
        
    }
};