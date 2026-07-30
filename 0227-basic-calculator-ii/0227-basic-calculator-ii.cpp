

class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        if (n == 0) return 0;

      
        vector<int> st; 
        int currentNumber = 0;
        char lastOperator = '+';

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (isdigit(ch)) {
                currentNumber = (currentNumber * 10) + (ch - '0');
            }

            
            if ((!isdigit(ch) && ch != ' ') || i == n - 1) {
                if (lastOperator == '+') {
                    st.push_back(currentNumber);
                } 
                else if (lastOperator == '-') {
                    st.push_back(-currentNumber);
                } 
                else if (lastOperator == '*') {
                    int top = st.back();
                    st.pop_back();
                    st.push_back(top * currentNumber);
                } 
                else if (lastOperator == '/') {
                    int top = st.back();
                    st.pop_back();
                    st.push_back(top / currentNumber);
                }

                currentNumber = 0;
                lastOperator = ch;
            }
        }

        
        int result = 0;
        for (int val : st) {
            result += val;
        }

        return result;
    }
};