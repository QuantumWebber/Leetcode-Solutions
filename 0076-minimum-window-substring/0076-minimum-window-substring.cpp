class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> need;

        // t ke har character ki frequency store karo
        for (char c : t) {
            need[c]++;
        }

        int required = t.size();   // kitne characters abhi bhi match hone baaki hain

        int l = 0;
        int start = 0;
        int minLen = INT_MAX;

        // Expand window
        for (int r = 0; r < s.size(); r++) {

            // Agar current character required tha
            if (need[s[r]] > 0)
                required--;

            // Character ko consume kar lo
            need[s[r]]--;

            // Jab saare required characters mil gaye
            while (required == 0) {

                // Minimum window update karo
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                // Left character ko remove kar rahe hain
                need[s[l]]++;

                // Agar us character ki fir se need pad gayi
                // to window invalid ho jayegi
                if (need[s[l]] > 0)
                    required++;

                l++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};