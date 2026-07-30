class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        


        priority_queue<pair<int,char>>maxHeap;


        if(a>0) maxHeap.push({a,'a'});
        if(b>0) maxHeap.push({b,'b'});
        if(c>0) maxHeap.push({c,'c'});


        string ans="";


        while(!maxHeap.empty()){


            auto first=maxHeap.top();
            maxHeap.pop();

            int freq=first.first;
            char ch=first.second;




            if(ans.size()>=2 && ans.back()==ch && ans[ans.size()-2]==ch){
                if(maxHeap.empty()) break;



                auto second=maxHeap.top(); maxHeap.pop();

                ans+=second.second;

                second.first--;

                if(second.first>0) maxHeap.push(second);
            

            maxHeap.push(first);
            }else{


                ans+=ch;

                freq--;


                if(freq>0) maxHeap.push({freq,ch});

            }
        }


        return ans;
    }
};