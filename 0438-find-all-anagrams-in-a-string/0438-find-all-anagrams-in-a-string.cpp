class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        unordered_map<char, int> need;

        // Pattern ki frequency banao
        for (char c : p)
            need[c]++;

        int required = p.size();

        int l = 0;

        vector<int> ans;

        // Expand window
        for (int r = 0; r < s.size(); r++) {

            // Agar current character required tha
            if (need[s[r]] > 0)
                required--;

            // Character consume kar lo
            need[s[r]]--;

            // Window size pattern se badi ho gayi
            if (r - l + 1 > p.size()) {

                // Left character wapas add karo
                need[s[l]]++;

                // Agar us character ki fir se need pad gayi
                if (need[s[l]] > 0)
                    required++;

                l++;
            }

            // Agar saare characters mil gaye
            if (required == 0)
                ans.push_back(l);
        }

        return ans;
    }
};