class KthLargest {

    private:
    //minheap ka top element lelenge aur usse kabhi k se zada nhi hone denge 
priority_queue<int, vector<int>, greater<int>> minHeap;
int maxSize;
public:

//constructor
    KthLargest(int k, vector<int>& nums) {
        maxSize=k;

        for(int num:nums){
            minHeap.push(num);
        

        if(minHeap.size()>maxSize){
            minHeap.pop();
        }
        }
        
    }
    
    int add(int val) {
        
        minHeap.push(val);

        if(minHeap.size()>maxSize){
            minHeap.pop();// smallest i.e k element added in stream largest kth 
        }

        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */