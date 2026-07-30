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
    void Insert(vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int curr = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > curr) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = curr;
        }
    }

public:
    ListNode* insertionSortList(ListNode* head) {
        // Convert linked list to array
        vector<int> ans;
        ListNode* temp = head;

        // Traverse the linked list and store values in the array
        while (temp != nullptr) {
            ans.push_back(temp->val);
            temp = temp->next;
        }

        // Sort the array using the Insert function
        Insert(ans);

        // Create a new sorted linked list
        head = new ListNode(ans[0]); // Create the head with the first value
        ListNode* curr = head;

        for (int i = 1; i < ans.size(); i++) {
            // Create a new node for each sorted value
            curr->next = new ListNode(ans[i]);
            curr = curr->next;
        }

        // Ensure the last node points to nullptr
        curr->next = nullptr;

        return head; // Return the head of the new sorted linked list
    }
};
