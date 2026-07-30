class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        


        //define maxHeap 


        priority_queue<int>pq;

        for(int stone: stones){
            pq.push(stone);
        }


        while(pq.size()>1){
            int first=pq.top();

            pq.pop();

            int second=pq.top(); pq.pop();


            int difference=first-second;

            pq.push(difference);
        }
        return pq.top();
    }
};


// haar baar largest stone nikalo second largest nikalo dono ka difference insert krdo 