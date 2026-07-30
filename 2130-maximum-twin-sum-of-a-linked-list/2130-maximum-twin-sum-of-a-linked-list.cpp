class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> temp;
        while (head) {
            temp.push_back(head->val);
            head = head->next;
        }
        int ans = 0, n = temp.size();
        for (int i = 0; i < n; i++)
            ans = max(ans, temp[i] + temp[n - i - 1]);
        return ans;
    }
};
