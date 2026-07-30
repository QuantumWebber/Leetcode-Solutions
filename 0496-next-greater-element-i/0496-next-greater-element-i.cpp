class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n1=nums1.size();
        int n=nums2.size();



        stack<int>s;

        vector<int>ans(n1,-1);


        // ab suno yaha tak hua ab kya kiya jaaye 

        unordered_map<int,int>nextGreaterMap;

        for(int i=n-1;i>=0;i--){
            int curr=nums2[i];

            while(!s.empty() && s.top()<=curr){
                s.pop();
            }


            if(!s.empty()){
                nextGreaterMap[curr]=s.top();

            }else{
                nextGreaterMap[curr]=-1;
            }
s.push(curr);

        }


        for(int i=0;i<n1;i++){
            ans[i]=nextGreaterMap[nums1[i]];
        }

        return ans;
    }
};