class MyStack {
    // now aim is to implement stack from queue
    queue<int> input;
    queue<int> temp;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        //agr mujhe push krna ho simply input.push(x )  krde
        input.push(x);
    }
    
    int pop() {
        while(input.size()>1){
            temp.push(input.front());
            input.pop();
        }
        int val=input.front();
        input.pop();
        swap(input,temp);
        return val;
        
    }
    
    int top() {
        

          while(input.size()>1){
            temp.push(input.front());
            input.pop();
        }
        int val=input.front();
        
            temp.push(val);  // Save the last element
            input.pop();

        swap(input,temp);
        return val;
    }
    
    bool empty() {
         return input.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */