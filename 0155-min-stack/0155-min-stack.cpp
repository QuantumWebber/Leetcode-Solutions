#include <stack>
using namespace std;

class MinStack {
private:
   
    stack<int> st;
    stack<int> mini;

public:
    
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        
        
        if (mini.empty() || value <= mini.top()) {
            mini.push(value);
        }
    }
    
    void pop() {
        if (st.empty()) return;

        
        if (st.top() == mini.top()) {
            mini.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini.top();
    }
};