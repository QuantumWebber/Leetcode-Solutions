class FreqStack {

    private:

    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>group;
    int maxFreq;
public:
    FreqStack() {
        maxFreq=0;
    }
    
    void push(int val) {

        freq[val]++;
        int currentFreq=freq[val];


        if(currentFreq>maxFreq){
            maxFreq=currentFreq;
        }

        group[currentFreq].push(val);
        
    }
    
    int pop() {
        
        int top=group[maxFreq].top();
        group[maxFreq].pop();


        freq[top]--;



        if(group[maxFreq].empty()){
            maxFreq--;
        }

        return top;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */