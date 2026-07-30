class MyQueue {
public:
stack<int>input,output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
        
    }
    
    int pop() {
        // remove elements from front of queue and return the elemenet
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }

        }
        //dekho hamne kya kra hamne input ke element udhake output stack me rakhdiye jab mera output stack empty tha 
        // ab wo queue bn gaya [3 4 1]=>[1 4 3]
        // ab front elment 1 ko hata de 
        int val=output.top();
        output.pop();
        return val;
    }
    
    int peek() {
        // return element aty front of queue
        //jase upr wala example me 1 hi return krna tha 
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */