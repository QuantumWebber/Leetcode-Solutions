class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> ans;
        for (int i = 0; i < nums1.size(); ++i) {
            int element = nums1[i];
            bool found = false;
            for (int j = 0; j < nums2.size(); ++j) {
                if (element == nums2[j]) {
                    found = true;
                    break;
                }
            }
            if (found && std::find(ans.begin(), ans.end(), element) == ans.end()) {
                ans.push_back(element);
            }
        }
        return ans;
    }
};