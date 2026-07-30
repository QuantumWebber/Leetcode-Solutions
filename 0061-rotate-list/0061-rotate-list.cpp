class Solution {
private:
    void reverse(vector<int>& arr, int s, int e) {
        while (s < e) {
            swap(arr[s], arr[e]);
            s++;
            e--;
        }
    }

    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        k = k % n; // In case k > n
        reverse(arr, 0, n - 1);
        reverse(arr, 0, k - 1);
        reverse(arr, k, n - 1);
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) return head;

        // Step 1: Copy linked list to vector
        vector<int> arr;
        ListNode* temp = head;
        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        // Step 2: Rotate array
        rotate(arr, k);

        // Step 3: Copy back to linked list
        temp = head;
        int i = 0;
        while (temp != nullptr) {
            temp->val = arr[i++];
            temp = temp->next;
        }

        return head;
    }
};
