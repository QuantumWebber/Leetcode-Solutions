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
    bool isPalindrome(vector<int>&arr){
        int n=arr.size();
        int s=0;
        int e=n-1;
        while(s<e){
            if(arr[s]!=arr[e])  return false;
            s++;
            e--;

        }
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        // convert ll into array 
        vector <int>arr;
        ListNode*temp=head;
        while(temp!=nullptr){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        return isPalindrome(arr);
    }
};