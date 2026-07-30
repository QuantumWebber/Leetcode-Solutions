class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
       if(hand.size() %groupSize!=0) return false;
       if(groupSize==1)  return true;



       // count freq
       map<int,int>freq;
       for(int card:hand){
        freq[card]++;
       }

       // make priority qeueue

       priority_queue<int,vector<int>,greater<int>>minHeap;
       for(auto& it:freq){
        minHeap.push(it.first);
       }



while(!minHeap.empty()){
    int start=minHeap.top();// take the smallest card 


    for(int i=0;i<groupSize;i++){
      int card=start+i;


      if(freq[card]==0) return false;


      freq[card]--;



      if(freq[card]==0 && card==minHeap.top()){
        minHeap.pop();
      }
    }

}
return true;
       
    }
};