



class Solution {
private:
    ListNode* listHead; 

public:
    
    Solution(ListNode* head) {
        listHead = head; 
    }
    
    
    int getRandom() {
        int ans = listHead->val; 
        int count = 1;           
        
        ListNode* curr = listHead->next; 
        
        while (curr != nullptr) {
            count++;
            
           
            if (rand() % count == 0) {
                ans = curr->val; 
            }
            
            curr = curr->next; 
        }
        
        return ans;
    }
};