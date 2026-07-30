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
    void insertAtTail(ListNode* &head,ListNode* &tail,int data ){
            ListNode* temp=new ListNode(data);
            if(head==nullptr){
                head=temp;
                tail=temp;
            }else{
                tail->next=temp;
                tail=temp;
            }
            
    }


    ListNode* add(ListNode* l1, ListNode*l2){
       // creating new linked list to store ans of sum 
       ListNode* ansHead= nullptr;
       ListNode* ansTail=nullptr;

       int carry=0;

       while(l1!=nullptr || l2!=nullptr || carry!=0){
        int val1=(l1!=nullptr)?l1->val:0;
        int val2=(l2!=nullptr)?l2->val:0;
        int sum=val1+val2+carry;
        int digits=sum%10;
         insertAtTail(ansHead,ansTail,digits);
          carry=sum/10;
         if(l1!=nullptr)   l1=l1->next;
         if(l2!=nullptr)  l2=l2->next;
         
       }
       return ansHead;

    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1,l2);
    }
};